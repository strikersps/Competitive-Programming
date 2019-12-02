/*  Problem Statement: https://www.hackerrank.com/challenges/minimum-swaps-2/problem
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#include<assert.h>

typedef struct unordered_data {
    uint32_t index,value;
    bool is_visited;
} unordered_data_t;

static int32_t compute_minimum_swaps(unordered_data_t[*],uint32_t);
int comparator_callback(const void*,const void*);

int main(void) {
    uint32_t n;
    scanf("%"SCNu32, &n);
    assert(n > 0 && n < 100001);
    unordered_data_t data[n];
    for(uint32_t i = 0; i < n; ++i) {
        scanf("%"SCNu32, &data[i].value);
        assert(data[i].value > 0 && data[i].value < (n + 1));
        data[i].index = (i + 1);
        data[i].is_visited = false;
    }
    printf("%"PRId32"\n", compute_minimum_swaps(data,n));
    return EXIT_SUCCESS;
}

static int32_t compute_minimum_swaps(unordered_data_t data[],uint32_t n) {
    int32_t min_swaps = 0, count_nodes;
    qsort(data,n,sizeof(unordered_data_t),comparator_callback);
    for(uint32_t i = 0; i < n; ++i) {
        count_nodes = 0;
        if(!(data[i].is_visited)) {
            uint32_t j;
            for(j = i; (data[j].index != (i + 1)); j = ((data[j].index) - 1)) {
                data[j].is_visited = true;
                ++count_nodes;
            }
            data[j].is_visited = true;
            min_swaps += count_nodes;
        }
    }
    return min_swaps;
}
int comparator_callback(const void *a,const void *b) {
    return (((unordered_data_t*)a)->value) > (((unordered_data_t*)b)->value);
}