/*  Problem Statement: https://www.spoj.com/problems/AE1B/
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>

#define MAX_NUMBER_SCREWS 1000

static const bool check_sorted(const uint32_t *const,uint32_t);
static void linear_bound_sorting(uint32_t *const,uint32_t);
static const uint32_t compute_minimum_boxes(const uint32_t *const,uint32_t,int32_t);

int main(void) {
    uint32_t n,k,s;
    scanf("%"SCNu32"%"SCNu32"%"SCNu32, &n,&k,&s);
    assert((n > 0 && n <= MAX_NUMBER_SCREWS) && (k > 0 && k <= MAX_NUMBER_SCREWS) && (s > 0 && s <= MAX_NUMBER_SCREWS));
    uint32_t *const boxes = calloc(sizeof(uint32_t), n);
    if(boxes) {
        for(uint32_t i = 0; i < n; ++i) {
            scanf("%"SCNu32, &boxes[i]);
            assert(boxes[i] > 0 && boxes[i] <= MAX_NUMBER_SCREWS);
        }
        if(!check_sorted(boxes,n)) {
            linear_bound_sorting(boxes,n);
        }
        printf("%"PRIu32"\n", compute_minimum_boxes(boxes,n,(k * s)));
        free(boxes);
    } else {
        fprintf(stderr,"Not able to allocate %lu bytes of memory\n", sizeof(uint32_t) * n);
    }
    return EXIT_SUCCESS;
}

static const bool check_sorted(const uint32_t *const data,uint32_t n) {
    uint32_t is_sorted = true;
    for(uint32_t i = 0; i < (n - 1); ++i) {
        if(data[i] < data[i + 1]) {
            is_sorted = false;
            break;
        }
    }
    return is_sorted;
}

static void linear_bound_sorting(uint32_t *const data,uint32_t n) {
    uint32_t freq_data[MAX_NUMBER_SCREWS];
    memset(freq_data,0,(sizeof(uint32_t) * MAX_NUMBER_SCREWS));
    for(uint32_t i = 0; i < n; ++i) {
        ++freq_data[data[i] - 1];
    }
    for(int32_t i = (MAX_NUMBER_SCREWS - 1), j = 0; i >= 0 && j < n; --i) {
        if(freq_data[i]) {
            for(uint32_t k = 0; k < freq_data[i]; ++k) {
                data[j++] = i + 1;
            }
        }
    }
}

static const uint32_t compute_minimum_boxes(const uint32_t *const data,uint32_t n,int screw_needed) {
    uint32_t min_boxes,tot_screws;
    min_boxes = tot_screws = 0;
    for(uint32_t i = 0; i < n; ++i) {
        tot_screws += data[i];
        ++min_boxes;
        if(tot_screws >= screw_needed) {
            break;
        }
    }
    if(tot_screws >= screw_needed) {
        return min_boxes;
    } else {
        return 0;
    }
}