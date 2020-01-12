/*
 * Problem Statement: https://github.com/strikersps/Competitive-Programming/blob/master/Other-Programs/Best-Pair/readme.md
 * Author: striker
 *
 * Copyright 2020 striker
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <time.h>

typedef unsigned long long ull_t;
typedef long long ll_t;

typedef struct Point2D {
    int x, y;
} point_2d;

#define MOD (1000000000 + 7) // Prime Number
#define PI 3.141592653589793 // Number of digits(15) of Pi which JPL uses for Interplanetary Caculations.

#define MEMORY_ALLOCATION_FAILED_ERROR(variable, bytes) fprintf(stderr, "Line number: %u: Not able to allocate <%lu> bytes of memory to <%s> variable.\n", __LINE__, (bytes), #variable)
#define CONSTRAINTS_OUT_OF_BOUND_ERROR(variable, constraints) fprintf(stderr, "Line number: %u: Constraints not satisfied for the variable <%s>, i.e. %s.\n", __LINE__, #variable, #constraints)
#define INITIALISE_CONTAINER_ZERO(container, bytes) memset(container, 0, (bytes))
#define FIND_MAX(a, b) (a) > (b) ? (a) : (b)
#define FIND_MIN(a, b) (a) < (b) ? (a) : (b)
#define FIND_MID(start, end) (((end) - (start)) >> 1) + (start)

static bool check_sorted(const ll_t *const, const int);
static void merge_sort(ll_t *const, const int, const int);
static void merge_data(ll_t *const, const int, const int, const int);

int main(void) {
    #ifndef ONLINE_JUDGE
        freopen("test-cases/test-case-1.in", "r", stdin);
        freopen("test-cases/test-case-1.out", "w", stdout);
    #endif
    int test;
    scanf("%d", &test);
    while(test--) {
        int n;
        scanf("%d", &n);
        ll_t *const data = calloc(n, sizeof*data);
        if(data) {
            for(int i = 0; i < n; ++i) {
                scanf("%lld", &data[i]);
            }
            if(!check_sorted(data, n)) {
                merge_sort(data, 0, n - 1);
            }
            printf("%lld\n", FIND_MAX((data[0] * data[1]), (data[n - 1] * data[n - 2])));
            free(data);
        } else {
            MEMORY_ALLOCATION_FAILED_ERROR(data, n * sizeof*data);
            exit(0);
        }
    }
    return EXIT_SUCCESS;
}

static bool check_sorted(const ll_t *const data, const int n) {
    bool is_sorted = true;
    for(int i = 0; i < (n - 1); ++i) {
        if(data[i] > data[i + 1]) {
            is_sorted = false;
            break;
        }
    }
    return is_sorted;
}

static void merge_sort(ll_t *const data, const int start, const int end) {
    if(start < end) {
        const int mid = FIND_MID(start, end);
        merge_sort(data, start, mid);
        merge_sort(data, mid + 1, end);
        merge_data(data, start, mid, end);
    }
}

static void merge_data(ll_t *const data, const int start, const int mid, const int end) {
    const int left_size = (mid - start) + 1;
    ll_t *const left_data = calloc(left_size, sizeof*left_data);
    if(left_data) {
        memcpy(left_data, &data[start], left_size * sizeof*data);
    } else {
        MEMORY_ALLOCATION_FAILED_ERROR(left_data, left_size * sizeof*left_data);
        exit(0);
    }
    const int right_size = end - mid;
    ll_t *const right_data = calloc(right_size, sizeof*right_data);
    if(right_data) {
        memcpy(right_data, &data[mid + 1], right_size * sizeof*data);
    } else {
        MEMORY_ALLOCATION_FAILED_ERROR(right_data, right_size * sizeof*right_data);
        exit(0);
    }
    for(int i = 0, j = 0, k = start; k <= end;) {
        if(i == left_size) {
            data[k++] = right_data[j++];
        } else if(j == right_size) {
            data[k++] = left_data[i++];
        } else if(left_data[i] < right_data[j]) {
            data[k++] = left_data[i++];
        } else {
            data[k++] = right_data[j++];
        }
    }
    free(left_data);
    free(right_data);
}
