/*
 * Problem Statement: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
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

#define MEMORY_ALLOCATION_FAILED_ERROR(variable, bytes) fprintf(stderr, "Line number: %u: Not able to allocate <%lu> bytes of memory to <%s> variable.\n", __LINE__, (bytes), #variable)
#define CONSTRAINTS_OUT_OF_BOUND_ERROR(variable, constraints) fprintf(stderr, "Line number: %u: Constraints not satisfied for the variable <%s>, i.e. %s.\n", __LINE__, #variable, #constraints)
#define INITIALISE_CONTAINER_ZERO(container, bytes) memset(container, 0, (bytes))
#define FIND_MAX(a, b) (a) > (b) ? (a) : (b)
#define FIND_MIN(a, b) (a) < (b) ? (a) : (b)
#define FIND_MID(start, end) (((end) - (start)) >> 1) + (start)

static int find_first_occurrence(const int *const, int, int, const int);
static int find_last_occurrence(const int *const, int, int, const int);

int main(void) {
    #ifndef ONLINE_JUDGE
        freopen("test-cases/test-case-1.in", "r", stdin);
        // freopen("test-cases/test-case-1.out", "w", stdout);
    #endif
    int test;
    scanf("%d", &test);
    while(test--) {
        int n;
        scanf("%d", &n);
        int *const data = calloc(n, sizeof *data);
        if(data) {
            for(int i = 0; i < n; ++i) {
                scanf("%d", &data[i]);
            }
            int search_data, first_occurrence_index, last_occurrence_index;
            scanf("%d", &search_data);
            first_occurrence_index = find_first_occurrence(data, 0, n - 1, search_data);
            last_occurrence_index = find_last_occurrence(data, 0, n - 1, search_data);
            printf("[%d, %d]\n", first_occurrence_index, last_occurrence_index);
        } else {
            MEMORY_ALLOCATION_FAILED_ERROR(data, n * sizeof *data);
            exit(0);
        }
    }
    return EXIT_SUCCESS;
}

static int find_first_occurrence(const int *const data, int start, int end, const int search_data) {
    int first_occurrence_index = -1;
    while(start <= end) {
        const int mid = FIND_MID(start, end);
        if(search_data == data[mid]) {
            first_occurrence_index = mid;
            end = mid - 1;
        } else if(search_data > data[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return first_occurrence_index;
}

static int find_last_occurrence(const int *const data, int start, int end, const int search_data) {
    int last_occurrence_index = -1;
    while(start <= end) {
        const int mid = FIND_MID(start, end);
        if(search_data == data[mid]) {
            last_occurrence_index = mid;
            start = mid + 1;
        } else if(search_data > data[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return last_occurrence_index;
}
