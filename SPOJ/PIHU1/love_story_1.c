/*  Problem Statement: https://www.spoj.com/problems/PIHU1/
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>
#include<assert.h>

const bool check_sorted(uint32_t *const,uint16_t);
void merge_sort(uint32_t *const,uint16_t,uint16_t);
void merge_data(uint32_t *const,uint16_t,uint16_t,uint16_t);
const bool is_representation_possible(uint32_t *const,uint16_t,uint32_t);

int main(void) {
    uint8_t test;
    scanf("%"SCNu8, &test);
    assert(test > 0);
    while(test--) {
        uint16_t n;
        scanf("%"SCNu16, &n);
        uint32_t *const data = calloc(n,sizeof(uint32_t));
        if(data) {
            for(uint16_t i = 0; i < n; ++i) {
                scanf("%"SCNu32, &data[i]);
            }
            uint32_t p;
            scanf("%"SCNu32, &p);
            if(!check_sorted(data,n)) {
                merge_sort(data,0,(n - 1));
            }
            printf("%s", (is_representation_possible(data,n,p) ? "YES\n" : "NO\n"));
            free(data);
        } else {
            fprintf(stderr,"Not able to allocate %lu bytes of memory\n", (n * sizeof(uint32_t)));
        }
    }
    return EXIT_SUCCESS;
}

const bool check_sorted(uint32_t *const data,uint16_t n) {
    bool is_sorted = true;
    for(uint32_t i = 0; i < (n - 1); ++i) {
        if(data[i] > data[i + 1]) {
            is_sorted = false;
            break;
        }
    }
    return is_sorted;
}

void merge_sort(uint32_t *const data,uint16_t start,uint16_t end) {
    if(start < end) {
        uint16_t mid = ((end - start) >> 1) + start;
        merge_sort(data,start,mid);
        merge_sort(data,(mid + 1),end);
        merge_data(data,start,mid,end);
    }
}

void merge_data(uint32_t *const data,uint16_t start,uint16_t mid,uint16_t end) {
    uint16_t left_size = (mid - start) + 1;
    uint32_t *const left_list = calloc(left_size,sizeof(uint32_t));
    if(left_list) {
        for(uint16_t i = 0; i < left_size; ++i) {
            left_list[i] = data[start + i];
        }
    } else {
        fprintf(stderr,"Not able to allocate %lu bytes of memory to left-list\n", left_size * sizeof(uint32_t));
    }
    uint16_t right_size = end - mid;
    uint32_t *const right_list = calloc(right_size,sizeof(uint32_t));
    if(right_list) {
        for(uint32_t j = 0; j < right_size; ++j) {
            right_list[j] = data[(mid + 1) + j];
        }
    } else {
        fprintf(stderr,"Not able to allocate %lu bytes of memory to right-list\n", right_size * sizeof(uint32_t));
    }
    for(uint16_t k = start, i = 0,j = 0; k <= end; ++k) {
        if(i == left_size) {
            data[k] = right_list[j];
            ++j;
        } else if(j == right_size) {
            data[k] = left_list[i];
            ++i;
        } else if(left_list[i] < right_list[j]) {
            data[k] = left_list[i];
            ++i;
        } else {
            data[k] = right_list[j];
            ++j;
        }
    }
    free(left_list);
    free(right_list);
}

const bool is_representation_possible(uint32_t *const data,uint16_t n,uint32_t p) {
    bool is_possible = false;
    for(uint16_t i = 0; i < (n - 2); ++i) {
        if(data[i] >= p) {
            continue;
        }
        uint32_t s = p - data[i];
        for(uint16_t start = (i + 1), end = (n - 1); start < end;) {
            if(data[start] + data[end] == s) {
                // printf("Ai: %"PRIu32" Aj: %"PRIu32" Ak: %"PRIu32"\n", data[start],data[end],(p - s));
                is_possible = true;
                break;
            } else if(data[start] + data[end] > s) {
                --end;
            } else {
                ++start;
            }
        }
        if(is_possible) {
            break;
        }
    }
    return is_possible;
}