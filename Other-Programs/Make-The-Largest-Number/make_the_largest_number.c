/*
 * Problem Statement: Refer to the readme.md file.
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
#define INITIALISE_INT_CONTAINER_ZERO(container, bytes) memset(container, 0, (bytes))
#define INITIALISE_CHAR_CONTAINER_ZERO(container, bytes) memset(container, '0', (bytes))
#define FIND_MAX(a, b) (a) > (b) ? (a) : (b)
#define FIND_MIN(a, b) (a) < (b) ? (a) : (b)
#define FIND_MID(start, end) (((end) - (start)) >> 1) + (start)

#define MAX_STRING_LENGTH 40 // As I am dealing with integer array.

static void compute_largest_number(ull_t *const, const int);
static void merge_sort(ull_t *const, const int, const int);
static void merge_data(ull_t *const, const int, const int, const int);
static bool comparator(const ull_t, const ull_t);

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
        ull_t *const sequence = calloc(n, sizeof*sequence);
        if(sequence) {
            for(int i = 0; i < n; ++i) {
                scanf("%llu", (sequence + i));
            }
            compute_largest_number(sequence, n); // Compute the largest number that can be built from the numbers of the sequence.
            free(sequence);
        } else {
            MEMORY_ALLOCATION_FAILED_ERROR(sequence, n * sizeof*sequence);
            exit(0);
        }
    }
    return EXIT_SUCCESS;
}

static void compute_largest_number(ull_t *const sequence, const int n) {
    merge_sort(sequence, 0, n - 1);
    for(int i = 0; i < n; ++i) {
        printf("%llu", sequence[i]);
    }
    printf("\n");
}

static void merge_sort(ull_t *const data, const int start, const int end) {
    if(start < end) {
        const int mid = FIND_MID(start, end);
        merge_sort(data, start, mid);
        merge_sort(data, mid + 1, end);
        merge_data(data, start, mid, end);
    }
}

static void merge_data(ull_t *const data, const int start, const int mid, const int end) {
    const int left_size = (end - mid) + 1;
    ull_t left_data[left_size];
    memcpy(left_data, &data[start], left_size * sizeof(ull_t));
    const int right_size = end - mid;
    ull_t right_data[right_size];
    memcpy(right_data, &data[mid + 1], right_size * sizeof(ull_t));
    for(int i = 0, j = 0, k = start; k <= end; ++k) {
        if(i == left_size) {
            data[k] = right_data[j++];
        } else if(j == right_size) {
            data[k] = left_data[i++];
        } else if(comparator(left_data[i], right_data[j])) {
            data[k] = left_data[i++];
        } else {
            data[k] = right_data[j++];
        }
    }
}

static bool comparator(const ull_t a, const ull_t b) {
    char string_a[MAX_STRING_LENGTH], string_b[MAX_STRING_LENGTH];
    INITIALISE_CHAR_CONTAINER_ZERO(string_a, MAX_STRING_LENGTH * sizeof(char));
    INITIALISE_CHAR_CONTAINER_ZERO(string_b, MAX_STRING_LENGTH * sizeof(char));
    snprintf(string_a, MAX_STRING_LENGTH, "%llu%llu", a, b);
    snprintf(string_b, MAX_STRING_LENGTH, "%llu%llu", b, a);
    if(strcmp(string_a, string_b) > 0) {
        return true;
    }
    return false;
}
