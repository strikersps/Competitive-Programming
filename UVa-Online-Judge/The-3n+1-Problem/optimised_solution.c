/*
 * Problem Statement: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=36
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
#include <string.h>
#include <stdbool.h>
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

/* ANSI C 5.3.0 - GNU C Compiler doesn't have following GCC functions defined.
// The below function macros refers to the GCC functions for doing computation directly on the bit-level of a number.
#define COMPUTE_SET_BITS(number) __builtin_popcountll(number) // Returns the number of set-bits in number (unsigned long long).
#define COMPUTE_PARITY(number) __builtin_parityll(number) // Returns the parity of the number (unsigned long long) i.e. True if 1's are odd else False.
#define COUNT_LEAD_ZEROES(number) __builtin_clzll(number) // Returns the count of lead zeroes before first set-bit from MSB in number (unsigned long long).
#define COUNT_TRAIL_ZEROES(number) __builtin_ctzll(number) // Return the count of trailing zeroes in number(unsigned long long).
*/

#define MAX_SIZE 10000

static ll_t compute_maximum_cycle_length(ll_t, ll_t);
static void swap_data(ll_t *const, ll_t *const);
static ll_t compute_cycle_length(ll_t);

int main(void) {
    #ifndef ONLINE_JUDGE
        freopen("test-cases/test-case-1.in", "r", stdin);
        freopen("test-cases/test-case-1.out", "w", stdout);
    #endif
    ll_t start, end;
    while(EOF != scanf("%lld%lld", &start, &end)) {
        printf("%lld %lld %lld\n", start, end, compute_maximum_cycle_length(start, end));
    }
    return EXIT_SUCCESS;
}

static ll_t compute_maximum_cycle_length(ll_t start, ll_t end) {
    static ll_t cache[MAX_SIZE];
    if(start > end) {
        swap_data(&start, &end);
    }
    ll_t max_cycle_length = 0;
    for(; start <= end; ++start) {
        if(!cache[start - 1]) {
            cache[start - 1] = compute_cycle_length(start);
        }
        if(max_cycle_length < cache[start - 1]) {
            max_cycle_length = cache[start - 1];
        }
    }
    return max_cycle_length;
}

static void swap_data(ll_t *const a, ll_t *const b) {
    if(a != b) {
        *a = (*a) ^ (*b);
        *b = (*a) ^ (*b);
        *a = (*a) ^ (*b);
    }
}

static ll_t compute_cycle_length(ll_t n) {
    ll_t cycle_length = 1;
    while(1 != n) {
        ++cycle_length;
        if(n % 2) {
            n = (3 * n) + 1;
            continue;
        }
        n >>= 1;
    }
    return cycle_length;
}
