/*
 * Problem Statement: https://www.codechef.com/problems/SUBGCD/
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
#define INTIALISE_CHAR_CONTAINER_ZERO(container, bytes) memset(container, '0', (bytes))
#define FIND_MAX(a, b) (a) > (b) ? (a) : (b)
#define FIND_MIN(a, b) (a) < (b) ? (a) : (b)
#define FIND_MID(start, end) (((end) - (start)) >> 1) + (start)

static int compute_subarray_length(int[], const int);
static int compute_gcd(int, int);

int main(void) {
    #ifndef ONLINE_JUDGE
        freopen("test-cases/test-case-1.in", "r", stdin);
        freopen("test-cases/test-case-1.out", "w", stdout);
    #endif
    int test;
    scanf("%d", &test);
    if(test < 1) {
        CONSTRAINTS_OUT_OF_BOUND_ERROR(test, test value cannot be -ve);
        exit(0);
    }
    while(test--) {
        int n;
        scanf("%d", &n);
        if(n < 1) {
            CONSTRAINTS_OUT_OF_BOUND_ERROR(n, size of the sequence cannot be -ve);
            exit(0);
        }
        int data[n];
        for(int i = 0; i < n; ++i) {
            scanf("%d", (data + i));
        }
        printf("%d\n", compute_subarray_length(data, n));
    }
    return EXIT_SUCCESS;
}

static int compute_subarray_length(int data[], const int n) {
    int seq_gcd = 0;
    for(int i = 0; i < n; ++i) {
        seq_gcd = compute_gcd(data[i], seq_gcd);
    }
    if(1 == seq_gcd) {
        return n;
    }
    return -1;
}

static int compute_gcd(const int a, const int b) {
    if(!b) {
        return a;
    } else if(!a) {
        return b;
    }
    return compute_gcd(b, (a % b));
}
