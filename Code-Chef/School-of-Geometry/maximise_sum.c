/*
 * Problem Statement: https://www.codechef.com/problems/SNUG_FIT
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
#define SCANF_ERROR(return_val) fprintf(stderr, "Line number: %u: Read Error!\n", __LINE__); exit(return_val)
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

static void take_input(int*, const int);
static void merge_sort(int *const, const unsigned int, const unsigned int);
static void merge_data(int *const , const unsigned int, const unsigned int, const unsigned int);

int main(void) {
    #ifndef ONLINE_JUDGE
        freopen("test-cases/test-case-1.in", "r", stdin);
        freopen("test-cases/test-case-1.out", "w", stdout);
    #endif
    int test;
    if(1 == scanf("%d", &test)) {
        if(test < 1) {
            CONSTRAINTS_OUT_OF_BOUND_ERROR(test, test value cannot be 0 or -ve);
            exit(0);
        }
        while(test--) {
            int n;
            if(1 == scanf("%d", &n)) {
                int sequence_1[n], sequence_2[n];
                take_input(sequence_1, n);
                take_input(sequence_2, n);
                merge_sort(sequence_1, 0, n - 1);
                merge_sort(sequence_2, 0, n - 1);
                ll_t max_sum = 0;
                for(register int i = 0; i < n; ++i) {
                    max_sum += FIND_MIN(sequence_1[i], sequence_2[i]);
                }
                printf("%lld\n", max_sum);
            } else {
                SCANF_ERROR(0);
            }
        }
    } else {
        SCANF_ERROR(0);
    }
    return EXIT_SUCCESS;
}

static void take_input(int *data, const int n) {
    for(int *traverse_ptr = data; traverse_ptr < data + n; ) {
        scanf("%d", traverse_ptr++);
    }
}

static void merge_sort(int *const data, const unsigned int start, const unsigned int end) {
    if(start < end) {
        const int mid = FIND_MID(start, end);
        merge_sort(data, start, mid);
        merge_sort(data, mid + 1, end);
        merge_data(data, start, mid, end);
    }
}

static void merge_data(int *const data, const unsigned int start, const unsigned int mid, const unsigned int end) {
    unsigned int left_size = (mid - start) + 1;
    int left_data[left_size];
    memcpy(left_data, &data[start], left_size * sizeof*data);
    unsigned int right_size = end - mid;
    int right_data[right_size];
    memcpy(right_data, &data[mid + 1], right_size * sizeof*data);
    for(register unsigned int i = 0, j = 0, k = start; k <= end; ++k) {
        if(i == left_size) {
            data[k] = right_data[j++];
        } else if(j == right_size) {
            data[k] = left_data[i++];
        } else if(left_data[i] <  right_data[j]) {
            data[k] = left_data[i++];
        } else {
            data[k] = right_data[j++];
        }
    }
}
