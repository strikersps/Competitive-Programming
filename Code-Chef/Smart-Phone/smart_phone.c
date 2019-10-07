/*  Problem Statement: https://www.codechef.com/ZCOPRAC/problems/ZCO14003
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

#define ull_t unsigned long long

void take_input(ull_t *const,ull_t);
const bool check_sorted(ull_t *const,ull_t);
void merge_sort(ull_t *const,ull_t,ull_t);
void merge_data(ull_t *const,ull_t,ull_t,ull_t);
const ull_t maximum_possible_revenue(ull_t *const,ull_t);

int main(void) {
    ull_t n;
    scanf("%llu",&n);
    assert(n > 0 && n < 500001);
    ull_t *const budget = calloc(n,sizeof(ull_t));
    if(budget) {
        take_input(budget,n);
        if(!(check_sorted(budget,n))) {
            merge_sort(budget,0,(n - 1));
        }
        printf("%llu\n",maximum_possible_revenue(budget,n));
        free(budget);
    } else {
        fprintf(stderr,"Memory not allocated to *budget pointer!\n");
    }
    return 0;
}

void take_input(ull_t *const budget,ull_t n) {
    for(ull_t i = 0; i < n; ++i) {
        scanf("%llu",&budget[i]);
        assert(budget[i] > 0 && budget[i] < 100000001);
    }
}

const bool check_sorted(ull_t *const budget,ull_t n) {
    bool is_sorted_decreasing = true;
    for(ull_t i = 0; i < (n - 1); ++i) {
        if(budget[i] < budget[i + 1]) {
            is_sorted_decreasing = false;
            break;
        }
    }
    return is_sorted_decreasing;
}

void merge_sort(ull_t *const budget,ull_t start,ull_t end) {
    if(start < end) {
        ull_t mid = ((end - start) >> 1) + start;
        merge_sort(budget,start,mid);
        merge_sort(budget,(mid + 1),end);
        merge_data(budget,start,mid,end);
    }
}

void merge_data(ull_t *const budget,ull_t start,ull_t mid,ull_t end) {
    ull_t left_size,right_size;
    left_size = (mid - start) + 1;
    right_size = (end -  mid);
    ull_t *const left_array = calloc(left_size,sizeof(ull_t));
    ull_t *const right_array = calloc(right_size,sizeof(ull_t));
    if(left_array) {
        for(ull_t i = 0; i < left_size; (left_array[i] = budget[start + i]),++i);
    } else {
        fprintf(stderr,"Memory not allocated to *left_array pointer!\n");
    }
    if(right_array) {
        for(ull_t j = 0; j < right_size; (right_array[j] = budget[mid + 1 + j]),++j);
    } else {
        fprintf(stderr,"Memory not allocated to *right_array pointer!\n");
    }
    for(ull_t i = 0, j = 0, k = start; k <= end; ++k) {
        if(i == left_size) {
            budget[k] = right_array[j];
            ++j;
        } else if(j == right_size) {
            budget[k] = left_array[i];
            ++i;
        } else if(left_array[i] < right_array[j]) {
            budget[k] = right_array[j];
            ++j;
        } else {
            budget[k] = left_array[i];
            ++i;
        }
    }
    free(left_array);
    free(right_array);
}

const ull_t maximum_possible_revenue(ull_t *const budget,ull_t n) {
    ull_t max_revenue,curr_revenue;
    max_revenue = 0;
    for(ull_t i = 0; i < n; ++i) {
        if((curr_revenue = budget[i] * (i + 1)) > max_revenue) {
            max_revenue = curr_revenue;
        }
    }
    return max_revenue;
}