/*
 * Problem Statement: https://www.hackerrank.com/challenges/ctci-merge-sort/problem
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
#include <math.h>
#include <limits.h>
#include <time.h>

typedef unsigned long long ull_t;
typedef long long ll_t;

typedef struct Point2D {
    int x, y;
} point_2d;

#define MOD (1000000000 + 7) // Prime Number
#define PI 3.141592653589793 // Number of digits(15) of Pi which JPL uses for Interplanetary Caculations.
#define GOLDEN_RATIO 1.618033988749895 // Number of digits(15).

#define MEMORY_ALLOCATION_FAILED_ERROR(variable, bytes) fprintf(stderr, "Line number: %u: Not able to allocate <%lu> bytes of memory to <%s> variable.\n", __LINE__, (bytes), #variable)
#define CONSTRAINTS_OUT_OF_BOUND_ERROR(variable, constraints) fprintf(stderr, "Line number: %u: Constraints not satisfied for the variable <%s>, i.e. %s.\n", __LINE__, #variable, #constraints)
#define INITIALISE_INT_CONTAINER_ZERO(container, bytes) memset(container, 0, (bytes))
#define INITIALISE_CHAR_CONTAINER_ZERO(container, bytes) memset(container, '0', (bytes))
#define FIND_MAX(a, b) (a) > (b) ? (a) : (b)
#define FIND_MIN(a, b) (a) < (b) ? (a) : (b)
#define FIND_MID(start, end) (((end) - (start)) >> 1) + (start)

static bool check_sorted(const int *const, const int);
static ull_t compute_inversions(int *const, const int, const int);
static ull_t merge_data(int *const, const int, const int, const int);

int main(void) {
    /* Hacker-Rank doesn't have ONLINE_JUDGE macro defined.
    #ifndef ONLINE_JUDGE
        freopen("test-cases/test-case-2.in", "r", stdin);
        freopen("test-cases/test-case-2.out", "w", stdout);
    #endif
    */
    int test;
    scanf("%d", &test);
    if(test < 1) {
        CONSTRAINTS_OUT_OF_BOUND_ERROR(test, test value cannot be 0 or -ve);
        exit(0);
    }
    while(test--) {
        int n;
        scanf("%d", &n);
        if(n < 1) {
            CONSTRAINTS_OUT_OF_BOUND_ERROR(n, n value cannot be 0 or -ve);
            exit(0);
        }
        int data[n];
        for(int i = 0; i < n; ++i) {
            scanf("%d", data + i);
        }
        ull_t inversion_count = 0;
        if(n > 1 && !check_sorted(data, n)) {
            inversion_count = compute_inversions(data, 0, n - 1);
        }
        printf("%llu\n", inversion_count);
    }
    return EXIT_SUCCESS;
}

static bool check_sorted(const int *const data, const int n) {
    bool is_sorted = true;
    for(int i = 0; i < (n - 1); ++i) {
        if(data[i] > data[i + 1]) {
            is_sorted = false;
            break;
        }
    }
    return is_sorted;
}

static ull_t compute_inversions(int *const data, const int start, const int end) {
    ull_t inversion_count = 0;
    if(start < end) {
        const int mid = FIND_MID(start, end);
        inversion_count = compute_inversions(data, start, mid);
        inversion_count += compute_inversions(data, mid + 1, end);
        inversion_count += merge_data(data, start, mid, end);
    }
    return inversion_count;
}

static ull_t merge_data(int *const data, const int start, const int mid, const int end) {
    const int left_size = mid - start + 1;
    int left_data[left_size];
    memcpy(left_data, &data[start], sizeof(int) * left_size);
    const int right_size = end - mid;
    int right_data[right_size];
    memcpy(right_data, &data[mid + 1], sizeof(int) * right_size);
    ull_t inversion_count = 0;
    for(int k = start, i = 0, j = 0; k <= end; ++k) {
        if(i == left_size) {
            data[k] = right_data[j++];
        } else if(j == right_size) {
            data[k] = left_data[i++];
        } else if(left_data[i] > right_data[j]) {
            inversion_count += (left_size - i);
            data[k] = right_data[j++];
        } else {
            data[k] = left_data[i++];
        }
    }
    return inversion_count;
}
