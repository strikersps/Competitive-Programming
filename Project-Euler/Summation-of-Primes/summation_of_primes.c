/*
 * Problem Statement: https://www.hackerrank.com/contests/projecteuler/challenges/euler010/problem
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

#define MAX_LIMIT 1000001

static ll_t * generate_prime_sum(void);

int main(void) {
    /* Hacker-Rank doesn't have ONLINE_JUDGE macro defined.
    #ifndef ONLINE_JUDGE
        freopen("test-cases/test-case-1.in", "r", stdin);
        freopen("test-cases/test-case-1.out", "w", stdout);
    #endif
    */
    int test;
    scanf("%d", &test);
    if(test < 1) {
        CONSTRAINTS_OUT_OF_BOUND_ERROR(test, test value cannot be 0 or -ve);
        exit(0);
    }
    ll_t *const prime_sum = generate_prime_sum(); // Function will return a array of sum of primes upto MAX_LIMIT.
    while(test--) {
        int n;
        scanf("%d", &n);
        printf("%llu\n", prime_sum[n - 1]);
    }
    return EXIT_SUCCESS;
}

static ll_t * generate_prime_sum(void) {
    bool prime[MAX_LIMIT];
    memset(prime, true, MAX_LIMIT * sizeof(bool));
    prime[0] = prime[1] = false;
    static ll_t prime_sum[MAX_LIMIT];
    for(ll_t i = 2; i < MAX_LIMIT; ++i) {
        if(prime[i]) {
            prime_sum[i - 1] = prime_sum[i - 2] + i;
            for(ll_t j = i * i; j < MAX_LIMIT; prime[j] = false, j += i);
            continue;
        }
        prime_sum[i - 1] = prime_sum[i - 2];
    }
    return prime_sum;
}
