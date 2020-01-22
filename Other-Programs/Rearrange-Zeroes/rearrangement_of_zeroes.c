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

static void rearrange_zeroes(int *const, const int);
static void display_sequence(const int *const, const int, const char *const);

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
        if(n < 1) {
            CONSTRAINTS_OUT_OF_BOUND_ERROR(n, size of array cannot be 0 or -ve);
            exit(0);
        }
        int *const sequence = calloc(n, sizeof*sequence);
        if(sequence) {
            for(int i = 0; i < n; ++i) {
                scanf("%d", sequence + i);
            }
            rearrange_zeroes(sequence, n);
            display_sequence(sequence, n, " ");
            free(sequence);
        } else {
            MEMORY_ALLOCATION_FAILED_ERROR(sequence, n * sizeof*sequence);
            exit(0);
        }
    }
    return EXIT_SUCCESS;
}

static void display_sequence(const int *const data, const int n, const char *const delimiter) {
    printf("%d", data[0]);
    for(int i = 1; i < n; ++i) {
        printf("%s%d", delimiter, data[i]);
    }
    printf("\n");
}

static void rearrange_zeroes(int *const data, const int n) {
    int index = 0;
    for(int i = 0; i < n; ++i) {
        if(data[i]) {
            data[index++] = data[i];
        }
    }
    while(index < n) {
        data[index++] = 0;
    }
}
