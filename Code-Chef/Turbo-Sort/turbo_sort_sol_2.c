/*  Problem Statement: https://www.codechef.com/problems/TSORT
    Author: striker
    NOTE: Solved the problem using Merge-Sort Algorithm. Time-Complexity = O(nlogn)
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>
#include<string.h>
#include<assert.h>

static const bool check_sorted(uint32_t[*],const uint32_t);
static void merge_sort(uint32_t[*],const uint32_t,const uint32_t);
static void merge_data(uint32_t[*],const uint32_t,const uint32_t,const uint32_t);

int main(void) {
    uint32_t n;
    scanf("%"SCNu32, &n);
    assert(n > 0 && n < 1000001);
    uint32_t data[n];
    for(uint32_t i = 0; i < n; ++i) {
        scanf("%"SCNu32, &data[i]);
        assert(data[i] >= 0 && data[i] < 1000001);
    }
    if(!check_sorted(data,n)) {
        merge_sort(data,0,(n - 1));
    }
    for(uint32_t i = 0; i < n; ++i) {
        printf("%"PRIu32"\n", data[i]);
    }
    return EXIT_SUCCESS;
}

static const bool check_sorted(uint32_t data[],const uint32_t n) {
    bool is_sorted = true;
    for(uint32_t i = 0; i < (n - 1); ++i) {
        if(data[i] > data[i + 1]) {
            is_sorted = false;
            break;
        }
    }
    return is_sorted;
}

static void merge_sort(uint32_t data[],const uint32_t start,const uint32_t end) {
    if(start < end) {
        const uint32_t mid = ((end - start) >> 1) + start;
        merge_sort(data,start,mid);
        merge_sort(data,(mid + 1),end);
        merge_data(data,start,mid,end);
    }
}

static void merge_data(uint32_t data[],const uint32_t start,uint32_t mid,uint32_t end) {
    uint32_t left_size = (mid - start) + 1;
    uint32_t left_data[left_size];
    memcpy(left_data,&data[start],(sizeof(uint32_t) * left_size));
    uint32_t right_size = end - mid;
    uint32_t right_data[right_size];
    memcpy(right_data,&data[mid + 1],(sizeof(uint32_t) * right_size));
    for(uint32_t k = start,i = 0, j = 0; k <= end; ++k) {
        if(i == left_size) {
            data[k] = right_data[j];
            ++j;
        } else if(j == right_size) {
            data[k] = left_data[i];
            ++i;
        } else if(left_data[i] < right_data[j]) {
            data[k] = left_data[i];
            ++i;
        } else {
            data[k] = right_data[j];
            ++j;
        }
    }
}