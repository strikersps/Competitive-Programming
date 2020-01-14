/*
 * Problem Statement: https://www.codechef.com/problems/HORSES
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

int comparator_callback(const void*, const void*);

int main(void) {
    #ifndef ONLINE_JUDGE
        freopen("test-cases/test-case-1.in", "r", stdin);
        freopen("test-cases/test-case-1.out", "w", stdout);
    #endif
    int test;
    scanf("%d", &test);
    if(test < 1) {
        CONSTRAINTS_OUT_OF_BOUND_ERROR(test, 1 <= test <= 10);
        exit(0);
    }
    while(test--) {
        int n;
        scanf("%d", &n);
        if(n < 2) {
            CONSTRAINTS_OUT_OF_BOUND_ERROR(n, 2 <= n <= 5000);
            exit(0);
        }
        int *const horse_skill = calloc(n, sizeof *horse_skill);
        if(horse_skill) {
            for(int i = 0; i < n; ++i) {
                scanf("%d", &horse_skill[i]);
            }
            qsort(horse_skill, n, sizeof *horse_skill, comparator_callback);
            int min_diff = INT_MAX;
            for(int i = 0; i < (n - 1); ++i) {
                int curr_diff = horse_skill[i + 1] - horse_skill[i];
                if(curr_diff < min_diff) {
                    min_diff = curr_diff;
                }
            }
            printf("%d\n", min_diff);
            free(horse_skill);
        } else {
            MEMORY_ALLOCATION_FAILED_ERROR(horse_skill, n * sizeof *horse_skill);
            exit(0);
        }
    }
    return EXIT_SUCCESS;
}

int comparator_callback(const void *a, const void *b) {
    return (*(int*) a) > (*(int*) b);
}
