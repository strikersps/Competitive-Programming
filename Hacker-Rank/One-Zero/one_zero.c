/*
 * Problem Statement: https://www.hackerrank.com/contests/mnnit-opc-2k20-2-0/challenges/one-zero-2
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

static ll_t compute_maximum_binary_value(const char *, const long int);

int main(void) {
    long int n;
    if(1 != scanf("%ld", &n)) {
        SCANF_READ_ERROR(1);
    }
    char binary_string[n];
    if(1 != scanf("%s", binary_string)) {
        SCANF_READ_ERROR(1);
    }
    printf("%lld\n", compute_maximum_binary_value(binary_string, n));
    return EXIT_SUCCESS;
}

static ll_t compute_maximum_binary_value(const char *binary_string, const long int n) {
    long int b_size = 1 + (2 * n);
    char *const updated_binary_string = calloc((size_t) b_size, sizeof*updated_binary_string);
    if(!updated_binary_string) {
        MEMORY_ALLOCATION_FAILED_ERROR(updated_binary_string, b_size);
        exit(0);
    }
    memcpy(updated_binary_string, binary_string, (size_t) n * sizeof*binary_string);
    memcpy(updated_binary_string + n, binary_string, (size_t) n * sizeof*binary_string);
    updated_binary_string[b_size - 1] = '\0';
    long int i, pos;
    for(i = n - 1, pos = n; i >= 0; --i) {
        if(memcmp(updated_binary_string + i, updated_binary_string + pos, (size_t) n * sizeof(char)) > 0) {
            pos = i;
        }
    }
    ll_t decimal_equivalent = 0;
    for(i = 0; i < n; ++i) {
        decimal_equivalent = ((2LL * decimal_equivalent) + (updated_binary_string[pos + i] - '0')) % MOD;
    }
    free(updated_binary_string);
    return decimal_equivalent;
}
