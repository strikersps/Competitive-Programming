/*
 * Problem Statement: https://www.hackerrank.com/challenges/palindrome-index/problem
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

#define MAX_STRING_LENGTH 100006

static bool check_palindrome(char[], int, int);
static int find_delete_index(char[]);

int main(void) {
    /* Hacker-Rank doesn't have ONLINE-JUDGE macro defined.
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
        char string_data[MAX_STRING_LENGTH];
        scanf("%s", string_data);
        if(!check_palindrome(string_data, 0, strlen(string_data) - 1)) {
            printf("%d\n", find_delete_index(string_data));
            continue;
        }
        printf("-1\n");
    }
    return EXIT_SUCCESS;
}

static bool check_palindrome(char string_data[], int start, int end) {
    bool is_palindrome = true;
    while(start < end) {
        if(string_data[start] != string_data[end]) {
            is_palindrome = false;
            break;
        }
        ++start; --end;
    }
    return is_palindrome;
}

static int find_delete_index(char string_data[]) {
    int found_index = -1;
    for(int start = 0, end = strlen(string_data) - 1; start < end; ++start, --end) {
        if(string_data[start] != string_data[end]) {
            if(!check_palindrome(string_data, start, end - 1)) {
                found_index = start;
                break;
            }
            found_index = end;
            break;
        }
    }
    return found_index;
}
