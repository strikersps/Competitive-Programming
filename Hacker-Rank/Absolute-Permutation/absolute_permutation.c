/*
 * Problem Statement: https://www.hackerrank.com/challenges/absolute-permutation/problem
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

#define MAX_LIMIT 100000

static int find_min(const int a, const int b) {
    return a < b ? a : b;
}

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
    while(test--) {
        int n, k;
        scanf("%d%d", &n, &k);
        if(n < 1) {
            CONSTRAINTS_OUT_OF_BOUND_ERROR(n, size of array cannot be 0 or -ve);
            exit(0);
        }
        if(!k) {
            for(int i = 0; i < n; ++i) {
                printf("%d ", i + 1);
            }
            printf("\n");
        } else if(n % 2) {
            printf("-1\n");
        } else {
            bool existence[MAX_LIMIT], is_possible = true;
            INITIALISE_INT_CONTAINER_ZERO(existence, MAX_LIMIT * sizeof(bool));
            int final_seq[MAX_LIMIT];
            for(int i = 0; i < n; ++i) {
                int choice1 = k + i + 1;
                int choice2 = abs(k - (i + 1));
                if(choice1 > n) {
                    choice1 %= n;
                }
                if(choice1 && choice2 && abs(choice1 - (i + 1)) == k && abs(choice2 - (i + 1)) == k) {
                    if(!existence[choice1 - 1] && !existence[choice2 - 1]) {
                        final_seq[i] = find_min(choice1, choice2); // Because we need to generate smallest lexicographic permutation.
                    } else if(existence[choice1 - 1]) {
                        final_seq[i] = choice2;

                    } else {
                        final_seq[i] = choice1;
                    }
                } else {
                    if((!choice1 && abs(choice2 - (i + 1)) != k) || (!choice2 && abs(choice1 - (i + 1)) != k) || (existence[choice1 - 1] && existence[choice2 - 1]) || (abs(choice1 - (i + 1)) != k && abs(choice2 - (i + 1)) != k)){
                        is_possible = false;
                        break;
                    } else if(abs(choice1 - (i + 1)) != k) {
                        final_seq[i] = choice2;
                    } else {
                        final_seq[i] = choice1;
                    }
                }
                existence[final_seq[i] - 1] = true;
            }
            if(is_possible) {
                for(int i = 0; i < n; ++i) {
                    printf("%d ", final_seq[i]);
                }
                printf("\n");
            } else {
                printf("-1\n");
            }
        }
    }
    return EXIT_SUCCESS;
}
