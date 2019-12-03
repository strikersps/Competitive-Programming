/*  Problem Statement: https://www.hackerrank.com/challenges/minimum-swaps-2/problem
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>
#include<string.h>
#include<assert.h>

typedef struct unordered_array {
    uint32_t index,value;
    bool is_visited;
} unordered_array_t;

static void merge_sort(unordered_array_t[*],const uint32_t,const uint32_t);
static void merge_data(unordered_array_t[*],const uint32_t,const uint32_t,const uint32_t);
static uint32_t mininmum_swaps(unordered_array_t[*],const uint32_t);

int main(void) {
    uint32_t n;
    scanf("%"SCNu32, &n);
    assert(n > 0 && n < 100001);
    unordered_array_t data[n];
    for(uint32_t i = 0; i < n; ++i) {
        scanf("%"SCNu32, &data[i].value);
        assert(data[i].value >= 0 && data[i].value < (n + 1));
        data[i].index = (i + 1);
        data[i].is_visited = false;
    }
    merge_sort(data,0,(n - 1));
    printf("%"PRIu32"\n", mininmum_swaps(data,n));
    return EXIT_SUCCESS;
}

static void merge_sort(unordered_array_t data[],const uint32_t start,uint32_t end) {
    if(start < end) {
        uint32_t mid = ((end - start) >> 1) + start;
        merge_sort(data,start,mid);
        merge_sort(data,(mid + 1),end);
        merge_data(data,start,mid,end);
    }
}

static void merge_data(unordered_array_t data[],const uint32_t start,uint32_t mid,uint32_t end) {
    const uint32_t left_size = (mid - start) + 1;
    unordered_array_t *const left_data = malloc(sizeof(unordered_array_t) * left_size);
    if(left_data) {
        memcpy(left_data,&data[start],(sizeof(unordered_array_t) * left_size));
    } else {
        fprintf(stderr,"Line number: %u: Not able to allocate %lu bytes of memory to *left-data\n", __LINE__,(sizeof(unordered_array_t) * left_size));
    }
    const uint32_t right_size = end - mid;
    unordered_array_t *const right_data = malloc(sizeof(unordered_array_t) * right_size);
    if(right_data) {
        memcpy(right_data,&data[mid + 1],(sizeof(unordered_array_t) * right_size));
    } else {
        fprintf(stderr,"Line number: %u: Not able to allocate %lu bytes of memory to *right-data\n", __LINE__,(sizeof(unordered_array_t) * right_size));
    }
    for(uint32_t k = start,i = 0, j = 0; k <= end; ++k) {
        if(i == left_size) {
            memcpy(&data[k],&right_data[j],sizeof(unordered_array_t));
            ++j;
        } else if(j == right_size) {
            memcpy(&data[k],&left_data[i],sizeof(unordered_array_t));
            ++i;
        } else if(left_data[i].value < right_data[j].value) {
            memcpy(&data[k],&left_data[i],sizeof(unordered_array_t));
            ++i;
        } else {
            memcpy(&data[k],&right_data[j],sizeof(unordered_array_t));
            ++j;
        }
    }
    free(left_data);
    free(right_data);
}

static uint32_t mininmum_swaps(unordered_array_t data[],uint32_t n) {
    uint32_t min_swaps = 0;
    for(uint32_t i = 0; i < n; ++i) {
        uint32_t count_nodes = 0;
        if(!data[i].is_visited) {
            uint32_t j = i;
            for(; data[j].index != (i + 1); j = (data[j].index - 1)) {
                data[j].is_visited = true;
                ++count_nodes;
            }
            data[j].is_visited = true;
            min_swaps += count_nodes;
        }
    }
    return min_swaps;
}