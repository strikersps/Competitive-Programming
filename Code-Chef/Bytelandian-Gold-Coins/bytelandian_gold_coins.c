/*
 * Problem Statement: https://www.codechef.com/problems/COINS
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

#define MEMORY_ALLOCATION_FAILED_ERROR(variable, bytes) fprintf(stderr, "Line number: %u: Not able to allocate <%llu> bytes of memory to <%s> variable.\n", __LINE__, (bytes), #variable)
#define CONSTRAINTS_OUT_OF_BOUND_ERROR(variable, constraints) fprintf(stderr, "Line number: %u: Constraints not satisfied for the variable <%s>, i.e. %s.\n", __LINE__, #variable, #constraints)
#define INITIALISE_INT_CONTAINER_ZERO(container, bytes) memset(container, 0, (bytes))
#define INITIALISE_CHAR_CONTAINER_ZERO(container, bytes) memset(container, '0', (bytes))
#define FIND_MAX(a, b) (a) > (b) ? (a) : (b)
#define FIND_MIN(a, b) (a) < (b) ? (a) : (b)
#define FIND_MID(start, end) (((end) - (start)) >> 1) + (start)

static ull_t compute_max_amount_dollars(const ull_t, ull_t *const);
static ull_t find_max(const ull_t, const ull_t);

int main(void) {
    #ifndef ONLINE_JUDGE
        freopen("test-cases/test-case-1.in", "r", stdin);
        freopen("test-cases/test-case-1.out", "w", stdout);
    #endif
    for(int test = 1; test <= 10; ++test) {
        ull_t n;
        scanf("%llu", &n);
        ull_t *const cache = calloc(n, sizeof*cache);
        if(cache) {
            printf("%llu\n", compute_max_amount_dollars(n, cache));
            free(cache);
        } else {
            MEMORY_ALLOCATION_FAILED_ERROR(cache, n * sizeof*cache);
            exit(0);
        }
    }
    return EXIT_SUCCESS;
}

static ull_t find_max(const ull_t a, const ull_t b) {
    return a > b ? a : b;
}

static ull_t compute_max_amount_dollars(const ull_t n, ull_t *const cache) {
    if(!n) {
        return 0;
    } else if((1 == n) || (2 == n) || (3 == n) || (4 == n)) {
        cache[n - 1] = n;
    } else if(!cache[n - 1]) {
        cache[n - 1] = find_max(n, (compute_max_amount_dollars(n >> 1, cache) + compute_max_amount_dollars(n / 3, cache) + cache[(n >> 2) - 1]));
    }
    return cache[n - 1];
}
