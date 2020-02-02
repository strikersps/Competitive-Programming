/*
 * Problem Statement: https://www.hackerrank.com/challenges/hackerland-radio-transmitters/
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

static int compute_min_transmitter_setup(int[], const int, const int);
int comparator_callback(const void*, const void*);

int main(void) {
    /* Hacker-Rank doesn't have ONLINE_JUDGE macro defined.
    #ifndef ONLINE_JUDGE
        freopen("test-cases/test-case-1.in", "r", stdin);
        // freopen("test-cases/test-case-1.out", "w", stdout);
    #endif
    */
    int n, k;
    scanf("%d%d", &n, &k);
    if(n < 1) {
        CONSTRAINTS_OUT_OF_BOUND_ERROR(n, n value cannot be 0 or -ve);
        exit(0);
    }
    if(k < 1) {
        CONSTRAINTS_OUT_OF_BOUND_ERROR(k, range of transmitter cannot be 0 or -ve);
        exit(0);
    }
    int location[n];
    for(register int i = 0; i < n; ++i) {
        scanf("%d", location + i);
    }
    qsort(location, n, sizeof(int), comparator_callback);
    printf("%d\n", compute_min_transmitter_setup(location, n, k));
    return EXIT_SUCCESS;
}

int comparator_callback(const void *a, const void *b) {
    return (*(int*)a) > (*(int*)b);
}

static int compute_min_transmitter_setup(int location[], const int n, const int trans_range) {
    int min_transmitter = 0;
    for(register int i = 0; i < n; ) {
        register int j;
        for(j = i + 1; j < n && (location[j] - location[i]) <= trans_range; ++j); // Finding the house on which the transmitter should be installed.
        ++min_transmitter;
        for(i = j; i < n && (location[i] - location[j - 1]) <= trans_range; ++i); // Finding the last-house which will recieve the signal from the transmitter installed at location[j - 1] house in the +ve direction.
    }
    return min_transmitter;
}
