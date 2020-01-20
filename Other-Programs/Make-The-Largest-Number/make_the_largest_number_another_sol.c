/*
 * Problem Statement: Refer to the readme.md
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

#define MAX_STRING_LENGTH 40

int comparator_callback(const void*, const void*);

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
        ull_t sequence[n];
        bool is_zero = true;
        for(int i = 0; i < n; ++i) {
            scanf("%llu", (sequence + i));
            if(is_zero && 0 != sequence[i]) {
                is_zero = false;
            }
        }
        if(is_zero) {
            printf("0");
        } else {
            qsort(sequence, n, sizeof(ull_t), comparator_callback);
            for(int i = 0; i < n; ++i) {
                printf("%llu", sequence[i]);
            }
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}

int comparator_callback(const void *a, const void *b) {
    char string_a[MAX_STRING_LENGTH], string_b[MAX_STRING_LENGTH];
    snprintf(string_a, MAX_STRING_LENGTH, "%llu%llu", (*(ull_t*) a), (*(ull_t*) b));
    snprintf(string_b, MAX_STRING_LENGTH, "%llu%llu", (*(ull_t*) b), (*(ull_t*) a));
    if(strcmp(string_a, string_b) < 0) {
        return true;
    }
    return false;
}
