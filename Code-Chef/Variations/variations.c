/*  Problem Statement: https://www.codechef.com/ZCOPRAC/problems/ZCO15002
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>
#include<assert.h>

#define NOT_FOUND -1

void take_input(uint32_t *const,uint32_t);
const bool check_sorted(uint32_t *const,uint32_t);
void merge_sort(uint32_t *const,uint32_t,uint32_t);
void merge_list(uint32_t *const,uint32_t,uint32_t,uint32_t);
const uint32_t compute_total_variation_count(uint32_t *const,uint32_t,uint32_t);

int main(void) {
    uint32_t n,k;
    scanf("%"SCNu32"%"SCNu32, &n,&k);
    assert((n > 0 && n < 65001) && (k > 0 && k < 100000001));
    uint32_t *const data = calloc(n,sizeof(uint32_t));
    if(data) {
        take_input(data,n);
        if(!check_sorted(data,n)) {
            merge_sort(data,0,(n - 1));
        }
        printf("%"PRIu32"\n", compute_total_variation_count(data,n,k));
        free(data);
    } else {
        fprintf(stderr,"Memory not allocated to *data pointer!\n");
    }
    return 0;
}

void take_input(uint32_t *const data,uint32_t n) {
    for(uint32_t i = 0; i < n; ++i) {
        scanf("%"SCNu32, &data[i]);
        assert(data[i] >= 0 && data[i] < 100000001);
    }
}

const bool check_sorted(uint32_t *const data,uint32_t n) {
    bool is_sorted = true;
    for(uint32_t i = 0; i < (n - 1); ++i) {
        if(data[i] > data[i + 1]) {
            is_sorted = false;
            break;
        }
    }
    return is_sorted;
}

void merge_sort(uint32_t *const data,uint32_t start,uint32_t end) {
    if(start < end) {
        uint32_t mid = ((end - start) >> 1) + start;
        merge_sort(data,start,mid);
        merge_sort(data,(mid + 1),end);
        merge_list(data,start,mid,end);
    }
}

void merge_list(uint32_t *const data,uint32_t start,uint32_t mid,uint32_t end) {
    uint32_t left_size,right_size;
    left_size = (mid - start) + 1;
    uint32_t *const left_list = calloc(left_size,sizeof(uint32_t));
    if(left_list) {
        for(uint32_t i = 0; i < left_size; left_list[i] = data[start + i],++i);
    } else {
        fprintf(stderr,"Memory not allocated to *left_list pointer!\n");
    }
    right_size = (end - mid);
    uint32_t *const right_list = calloc(right_size,sizeof(uint32_t));
    if(right_list) {
        for(uint32_t j = 0; j < right_size; right_list[j] = data[(mid + 1) + j],++j);
    } else {
        fprintf(stderr,"Memory not allocated to *right_list pointer!\n");
    }
    for(uint32_t k = start, i = 0, j = 0; k <= end; ++k) {
        if(i == left_size) {
            data[k] = right_list[j];
            ++j;
        } else if(j == right_size) {
            data[k] = left_list[i];
            ++i;
        } else if(right_list[j] > left_list[i]) {
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

const uint32_t compute_total_variation_count(uint32_t *const data,uint32_t n,uint32_t k) {
    uint32_t variation_count = 0;
    for(uint32_t i = 0; i < (n - 1); ++i) {
        for(uint32_t j = (i + 1); j < n; ++j) {
            if(abs(data[i] - data[j]) >= k) {
                variation_count += (n - j);
                break;
            }
        }
    }
    return variation_count;
}