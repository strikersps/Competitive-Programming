/*
 * Problem Statement: https://bit.ly/2AdCSua
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

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

/*START OF CODE-TEMPLATE*/

typedef unsigned long long ull_t;
typedef long long ll_t;

typedef struct Point2D {
    int x, y;
} point_2d_t;

#define MOD (1000000000 + 7) // Prime Number
#define PI 3.141592653589793 // Number of digits(15) of Pi which JPL uses for Interplanetary Caculations.
#define GOLDEN_RATIO 1.618033988749895 // Number of digits(15).

#define MEMORY_ALLOCATION_FAILED_ERROR(variable, bytes) fprintf(stderr, "Line number: %u: Not able to allocate <%lu> bytes of memory to <%s> variable.\n", __LINE__, (bytes), #variable)
#define CONSTRAINTS_OUT_OF_BOUND_ERROR(variable, constraints) fprintf(stderr, "Line number: %u: Constraints not satisfied for the variable <%s>, i.e. %s.\n", __LINE__, #variable, #constraints)
#define SCANF_READ_ERROR(expected_return_val) fprintf(stderr, "Line number: %u: scanf() read error!\nExpected-Return-Value: %d.\n", __LINE__, expected_return_val); exit(0)
#define STREAM_LINK_ERROR(file_path, stream_name) fprintf(stderr, "Line number: %u: Stream Link Error! Not able to link <%s> file to <%s> stream.\n", __LINE__, #file_path, #stream_name); exit(0);
#define INITIALISE_INT_CONTAINER_ZERO(container, bytes) memset(container, 0, (bytes))
#define INITIALISE_CHAR_CONTAINER_ZERO(container, bytes) memset(container, '0', (bytes))
#define FIND_MAX(a, b) (a) > (b) ? (a) : (b)
#define FIND_MIN(a, b) (a) < (b) ? (a) : (b)
#define FIND_MID(start, end) (((end) - (start)) >> 1) + (start)

// The below function macros refers to the GCC functions for doing computation directly on the bit-level of a number.
#define COMPUTE_SET_BITS(number) __builtin_popcountll(number) // Returns the number of set-bits in number (unsigned long long).
#define COMPUTE_PARITY(number) __builtin_parityll(number) // Returns the parity of the number (unsigned long long) i.e. True if 1's are odd else False.
#define COUNT_LEAD_ZEROES(number) __builtin_clzll(number) // Returns the count of lead zeroes before first set-bit from MSB in number (unsigned long long).
#define COUNT_TRAIL_ZEROES(number) __builtin_ctzll(number) // Return the count of trailing zeroes in number(unsigned long long).

/*END OF CODE-TEMPLATE*/

static void take_input_array(int *const, const int);
static int compute_minimum_operations(const int *const, const int *const, const int);

int main(void) {
    int n;
    if(1 != scanf("%d", &n)) {
        SCANF_READ_ERROR(1);
    }
    int *const s1 = calloc((size_t) n, sizeof*s1);
    if(!s1) {
        MEMORY_ALLOCATION_FAILED_ERROR(s1, (size_t) n * sizeof*s1);
        exit(0);
    }
    int *const s2 = calloc((size_t) n, sizeof*s2);
    if(!s2) {
        MEMORY_ALLOCATION_FAILED_ERROR(s2, (size_t) n * sizeof*s2);
        exit(0);
    }
    take_input_array(s1, n);
    take_input_array(s2, n);
    printf("%d\n", compute_minimum_operations(s1, s2, n));
    free(s1);
    free(s2);
    return EXIT_SUCCESS;
}

static void take_input_array(int *const data, const int n) {
    for(int i = 0; i < n; ++i) {
        if(1 != scanf("%d", data + i)) {
            SCANF_READ_ERROR(1);
        }
    }
}

static int compute_minimum_value_array(const int *const data, const int n) {
    int min_value = INT_MAX;
    for(int i = 0; i < n; ++i) {
        if(data[i] < min_value) {
            min_value = data[i];
        }
    }
    return min_value;
}

static int compute_minimum_operations(const int *const s1, const int *const s2, const int n) {
    if(n == 1) {
        return 0;
    }
    int min_a = compute_minimum_value_array(s1, n);
    int min_operations;
    for(int target = min_a; target >= 0; --target) {
        min_operations = 0;
        for(int i = 0; i < n; ++i) {
            if(target == s1[i]) {
                continue;
            }
            if(s2[i] > 0 && !((s1[i] - target) % s2[i])) {
                min_operations += (s1[i] - target) / s2[i];
                continue;
            }
            min_operations = -1;
            break;
        }
        if(min_operations > -1) {
            break;
        }
    }
    return min_operations;
}
