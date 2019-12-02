/*  Problem Statement: https://www.hackerrank.com/challenges/ctci-bubble-sort/problem
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<assert.h>

static void bubble_sort(uint32_t[*],uint16_t,uint32_t *const);
static void swap_data(uint32_t *const,uint32_t *const);

int main(void) {
    uint16_t n;
    scanf("%"SCNu16, &n);
    uint32_t data[n];
    for(uint32_t i = 0; i < n; ++i) {
        scanf("%"SCNu32, &data[i]);
        assert(data[i] > 0 && data[i] < 2000001);
    }
    uint32_t total_swaps = 0;
    bubble_sort(data,n,&total_swaps);
    printf("Array is sorted in %"PRIu32" swaps.\nFirst Element: %"PRIu32"\nLast Element: %"PRIu32"\n", total_swaps,data[0],data[n - 1]);
    return EXIT_SUCCESS;
}

static void bubble_sort(uint32_t data[],uint16_t n,uint32_t *const tot_swaps) {
    for(int32_t i = (n - 1); i >= 0; --i) {
        for(uint32_t j = 0; j < i; ++j) {
            if(data[j] > data[j + 1]) {
                swap_data(&data[j],&data[j + 1]);
                ++(*tot_swaps);
            }
        }
    }
}

static void swap_data(uint32_t *const a,uint32_t *const b) {
    if(!(a == b)) {
        (*a) = (*a) ^ (*b);
        (*b) = (*a) ^ (*b);
        (*a) = (*a) ^ (*b);
    }
}