/*  Problem Statement: https://www.codechef.com/LRNDSA01/problems/ZCO14003
    Author: striker
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef unsigned long long ull_t;

static void take_input(ull_t *const,ull_t);
static bool check_sorted(ull_t *const,ull_t);
static void merge_sort(ull_t *const,ull_t,ull_t);
static void merge_data(ull_t *const,ull_t,ull_t,ull_t);
static ull_t maximum_possible_revenue(ull_t *const,ull_t);

int main(void) {
    ull_t n;
    if(1 != scanf("%llu", &n)) {
        fprintf(stderr, "Line number: %u: scanf() Read Error!\n", __LINE__);
        exit(0);
    }
    ull_t *const budget = calloc(n, sizeof*budget);
    if(budget) {
        take_input(budget, n);
        if(!(check_sorted(budget, n))) {
            merge_sort(budget, 0, (n - 1));
        }
        printf("%llu\n", maximum_possible_revenue(budget, n));
        free(budget);
    } else {
        fprintf(stderr,"Memory not allocated to *budget pointer!\n");
    }
    return 0;
}

static void take_input(ull_t *const budget, ull_t n) {
    for(ull_t i = 0; i < n; ++i) {
        if(1 == scanf("%llu", &budget[i])) {
            continue;
        }
    }
}

static bool check_sorted(ull_t *const budget, ull_t n) {
    bool is_sorted_decreasing = true;
    for(ull_t i = 0; i < (n - 1); ++i) {
        if(budget[i] < budget[i + 1]) {
            is_sorted_decreasing = false;
            break;
        }
    }
    return is_sorted_decreasing;
}

static void merge_sort(ull_t *const budget, ull_t start, ull_t end) {
    if(start < end) {
        ull_t mid = ((end - start) >> 1) + start;
        merge_sort(budget, start,mid);
        merge_sort(budget, (mid + 1),end);
        merge_data(budget, start, mid, end);
    }
}

static void merge_data(ull_t *const budget,ull_t start,ull_t mid,ull_t end) {
    ull_t left_size,right_size;
    left_size = (mid - start) + 1;
    right_size = (end -  mid);
    ull_t left_array[left_size];
    memcpy(left_array, &budget[start], left_size * sizeof*budget);
    ull_t right_array[right_size];
    memcpy(right_array, &budget[mid + 1], right_size * sizeof*budget);
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
}

static ull_t maximum_possible_revenue(ull_t *const budget, ull_t n) {
    ull_t max_revenue,curr_revenue;
    max_revenue = 0;
    for(ull_t i = 0; i < n; ++i) {
        if((curr_revenue = budget[i] * (i + 1)) > max_revenue) {
            max_revenue = curr_revenue;
        }
    }
    return max_revenue;
}
