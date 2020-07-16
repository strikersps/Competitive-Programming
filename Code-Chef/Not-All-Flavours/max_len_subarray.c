/*
 * Problem Statement: https://www.codechef.com/LRNDSA02/problems/NOTALLFL
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
#include <ctype.h>
#include <limits.h>
#include <time.h>

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

static int compute_length_of_subaray(int[], const int, const int);

int main(void) {
    int test;
    if(1 != scanf("%d", &test)) {
        SCANF_READ_ERROR(1);
    }
    while(test--) {
        int n, k;
        if(2 != scanf("%d%d", &n, &k)) {
            SCANF_READ_ERROR(2);
        }
        int *const cake_flavour = calloc((size_t) n, sizeof*cake_flavour);
        if(!cake_flavour) {
            MEMORY_ALLOCATION_FAILED_ERROR(cake_flavour, (size_t) n * sizeof*cake_flavour);
            exit(0);
        }
        for(int i = 0; i < n; ++i) {
            if(1 != scanf("%d", cake_flavour + i)) {
                SCANF_READ_ERROR(1);
            }
        }
        printf("%d\n", compute_length_of_subaray(cake_flavour, n, k));
        free(cake_flavour);
    }
    return EXIT_SUCCESS;
}

static int compute_length_of_subaray(int cake_flavour[], const int n, const int k) {
    if(k > n) {
        return n;
    }
    int subarray_len, max_subarray_len;
    subarray_len = max_subarray_len = 0;
    int *const freq_map = calloc((size_t) k, sizeof*freq_map);
    if(!freq_map) {
        MEMORY_ALLOCATION_FAILED_ERROR(freq_map, (size_t) k * sizeof*freq_map);
        exit(0);
    }
    INITIALISE_INT_CONTAINER_ZERO(freq_map, (size_t) k * sizeof(int));
    for(int start = 0, end = 0, unique_number_count = 0; start < n; ++start, --subarray_len) {
        while(end < n && (freq_map[cake_flavour[end] - 1] || unique_number_count < (k - 1))) {
            ++subarray_len;
            if(!freq_map[cake_flavour[end] - 1]) {
                ++unique_number_count;
            }
            ++freq_map[cake_flavour[end] - 1];
            ++end;
        }
        max_subarray_len = FIND_MAX(subarray_len, max_subarray_len);
        if(end == n) {
            break;
        }
        --freq_map[cake_flavour[start] - 1];
        if(!freq_map[cake_flavour[start] - 1]) {
            --unique_number_count;
        }
    }
    free(freq_map);
    return max_subarray_len;
}
