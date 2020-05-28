/*
 * Problem Statement: Refer to the readme.md file.
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

static void generate_sorted_square_sequence(int * const, const int);

int main(void) {
    int test;
    if(1 != scanf("%d", &test)) {
        SCANF_READ_ERROR(1);
    }
    while(test--) {
        int n;
        if(1 != scanf("%d", &n)) {
            SCANF_READ_ERROR(1);
        }
        int *const sequence = calloc((size_t) n, sizeof*sequence);
        if(!sequence) {
            MEMORY_ALLOCATION_FAILED_ERROR(sequence, (size_t) n * sizeof*sequence);
            exit(0);
        }
        for(int i = 0; i < n; ++i) {
            if(1 != scanf("%d", sequence + i)) {
                SCANF_READ_ERROR(1);
            }
        }
        if(n > 1) {
            generate_sorted_square_sequence(sequence, n);
        }
        for(int i = 0; i < n; ++i) {
            printf("%d ", sequence[i]);
        }
        printf("\n");
        free(sequence);
    }
    return EXIT_SUCCESS;
}

static void generate_sorted_square_sequence(int * const sequence, const int n) {
    int count_negative_nos = 0, count_positive_nos = 0;
    int positive_nos_start_index = -1;
    for(int i = 0; i < n; ++i) {
        if(sequence[i] < 0) {
            ++count_negative_nos;
            continue;
        }
        if(positive_nos_start_index == -1) {
            positive_nos_start_index = i;
        }
        ++count_positive_nos;
    }
    if(count_negative_nos && count_positive_nos) {
        int *const negative_sequence = calloc((size_t) count_negative_nos, sizeof*negative_sequence);
        if(!negative_sequence) {
            MEMORY_ALLOCATION_FAILED_ERROR(negative_sequence, (size_t) count_negative_nos * sizeof*negative_sequence);
            exit(0);
        }
        memcpy(negative_sequence, sequence, (size_t) positive_nos_start_index * sizeof(int));
        int *const positive_sequence = calloc((size_t) count_positive_nos, sizeof*positive_sequence);
        if(!positive_sequence) {
            MEMORY_ALLOCATION_FAILED_ERROR(positive_sequence, (size_t) count_positive_nos * sizeof*positive_sequence);
            exit(0);
        }
        memcpy(positive_sequence, sequence + positive_nos_start_index, (size_t) (n - positive_nos_start_index) * sizeof(int));
        for(int i = count_negative_nos - 1, j = 0, k = 0; k < n; ++k) {
            if(i < 0) {
                sequence[k] = positive_sequence[j] * positive_sequence[j];
                ++j;
                continue;
            }
            if(j == count_positive_nos) {
                sequence[k] = negative_sequence[i] * negative_sequence[i];
                --i;
                continue;
            }
            if((negative_sequence[i] * negative_sequence[i]) < (positive_sequence[j] * positive_sequence[j])) {
                sequence[k] = negative_sequence[i] * negative_sequence[i];
                --i;
                continue;
            }
            sequence[k] = positive_sequence[j] * positive_sequence[j];
            ++j;
        }
        free(negative_sequence); free(positive_sequence);
    }
}
