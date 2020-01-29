/*
 * Problem Statement: https://www.hackerrank.com/challenges/between-two-sets/problem
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

static ll_t compute_gcd(const ll_t, const ll_t);
static ll_t compute_lcm(const ll_t, const ll_t);

int main(void) {
    /* Hacker-Rank doesn't have ONLINE_JUDGE macro defined.
    #ifndef ONLINE_JUDGE
        freopen("test-cases/test-case-1.in", "r", stdin);
        freopen("test-cases/test-case-1.out", "w", stdout);
    #endif
    */
    int n, m;
    scanf("%d%d", &n, &m);
    int sequence1[n], sequence2[m];
    ll_t lcm, gcd;
    lcm = 1;
    gcd = 0;
    for(int i = 0; i < n; ++i) {
        scanf("%d", sequence1 + i);
        lcm = compute_lcm(sequence1[i], lcm);
    }
    for(int i = 0; i < m; ++i) {
        scanf("%d", sequence2 + i);
        gcd = compute_gcd(sequence2[i], gcd);
    }
    ll_t tot_numbers = 0;
    for(ll_t i = 1; i * i <= gcd; ++i) {
        if(!(gcd % i)) {
            if(!(i % lcm)) {
                ++tot_numbers;
            }
            if(!((gcd / i) == i)) {
                if(!((gcd / i) % lcm)) {
                    ++tot_numbers;
                }
            }
        }
    }
    printf("%lld\n", tot_numbers);
    return EXIT_SUCCESS;
}

static ll_t compute_gcd(const ll_t a, const ll_t b) {
    if(!b) {
        return a;
    } else if(!a) {
        return b;
    }
    return compute_gcd(b, a % b);
}

static ll_t compute_lcm(const ll_t a, const ll_t b) {
    return (a * b) / compute_gcd(a, b);
}
