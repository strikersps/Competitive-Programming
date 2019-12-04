/*  Problem Statement: https://www.hackerrank.com/challenges/fraudulent-activity-notifications/problem
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<string.h>
#include<assert.h>

#define MAX_VALUE 201

static uint32_t compute_total_notifications_sent(uint32_t[*],uint32_t,uint32_t d);
static double compute_median(uint32_t[*],uint32_t);

int main(void) {
    uint32_t n,d;
    scanf("%"SCNu32"%"SCNu32, &n,&d);
    assert((n > 0 && n < 200001) && (d > 0 && d <= n));
    uint32_t expenditure[n];
    for(uint32_t i = 0; i < n; ++i) {
        scanf("%"SCNu32, &expenditure[i]);
        assert(expenditure[i] >= 0 && expenditure[i] < 201);
    }
    if(d >= n) {
        printf("0\n");
    } else {
        printf("%"PRIu32"\n", compute_total_notifications_sent(expenditure,n,d));
    }
    return EXIT_SUCCESS;
}

static uint32_t compute_total_notifications_sent(uint32_t expenditure[],uint32_t n,uint32_t d) {
    uint32_t notification_count = 0;
    uint32_t frequency_data[MAX_VALUE];
    memset(frequency_data,0,(sizeof(uint32_t) * MAX_VALUE));
    for(uint32_t i = 0; i < d; ++i) {
        ++frequency_data[expenditure[i]];
    }
    for(uint32_t i = d, start = 0, end = (i - 1); i < n; ++i, ++start, end = (i - 1)) {
        double median = compute_median(frequency_data,d);
        --frequency_data[expenditure[start]];
        ++frequency_data[expenditure[end + 1]];
        if(expenditure[i] >= (2 * median)) {
            ++notification_count;
        }
    }
    return notification_count;
}

static double compute_median(uint32_t frequency_data[],uint32_t d) {
    uint32_t mid = d >> 1;
    if(d & 1) {
        ++mid;
    }
    uint32_t total_numbers = 0, mid_index;
    for(uint32_t i = 0; i < MAX_VALUE; ++i) {
        total_numbers += frequency_data[i];
        if(total_numbers >= mid) {
            mid_index = i;
            break;
        }
    }
    double median = 0.0;
    if(d & 1) {
        median = mid_index;
    } else {
        if(total_numbers == mid) {
            median = mid_index;
            for(uint32_t i = (mid_index + 1); i < MAX_VALUE; ++i) {
                if(frequency_data[i]) {
                    median += i;
                    break;
                }
            }
            median /= 2.0;
        } else {
            median = mid_index;
        }
    }
    return median;
}