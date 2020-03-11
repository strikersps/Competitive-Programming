/*
 * Problem Statement: https://www.spoj.com/problems/STAMPS/
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
#define SCANF_READ_ERROR(expected_return_val) fprintf(stderr, "Line number: %u: scanf() read error!\nExpected-Return-Value: %d.\n", __LINE__, expected_return_val); exit(0)
#define STREAM_LINK_ERROR(file_path, stream_name) fprintf(stderr, "Line number: %u: Stream Link Error! Not able to link <%s> file to <%s> stream.\n", __LINE__, #file_path, #stream_name);
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

static void merge_sort(int[], const int, const int);
static void merge_data(int[], const int, const int, const int);

int main(void) {
    int scenarios;
    if(1 == scanf("%d", &scenarios)) {
        for(register int scenario = 1; scenario <= scenarios; ++scenario) {
            int stamps_required, tot_lucy_friends;
            if(2 == scanf("%d%d", &stamps_required, &tot_lucy_friends)) {
                int stamp_offered[tot_lucy_friends], tot_stamps_offered = 0;
                for(register int i = 0; i < tot_lucy_friends; ++i) {
                    if(1 != scanf("%d", stamp_offered + i)) {
                        SCANF_READ_ERROR(1);
                    }
                    tot_stamps_offered += stamp_offered[i];
                }
                if(tot_stamps_offered < stamps_required) {
                    printf("Scenario #%d:\nimpossible\n", scenario);
                    continue;
                }
                merge_sort(stamp_offered, 0, tot_lucy_friends - 1); // Sort the array in decreasing order.
                int min_stamps_needed = 0;
                tot_stamps_offered = 0;
                for(register int i = 0; i < tot_lucy_friends; ++i) {
                    tot_stamps_offered += stamp_offered[i];
                    ++min_stamps_needed;
                    if(tot_stamps_offered >= stamps_required) {
                        break;
                    }
                }
                printf("Scenario #%d:\n%d\n", scenario, min_stamps_needed);
            } else {
                SCANF_READ_ERROR(2);
            }
        }
    } else {
        SCANF_READ_ERROR(1);
    }
    return EXIT_SUCCESS;
}

static void merge_sort(int data[], const int start, const int end) {
    if(start < end) {
        const int mid = FIND_MID(start, end);
        merge_sort(data, start, mid);
        merge_sort(data, mid + 1, end);
        merge_data(data, start, mid, end);
    }
}

static void merge_data(int data[], const int start, const int mid, const int end) {
    int left_size = (mid - start) + 1;
    int left_data[left_size];
    memcpy(left_data, &data[start], (unsigned long int) left_size * sizeof(int));
    int right_size = end - mid;
    int right_data[right_size];
    memcpy(right_data, &data[mid + 1], (unsigned long int) right_size * sizeof(int));
    for(register int i = 0, j = 0, k = start; k <= end; ++k) {
        if(i == left_size) {
            data[k] = right_data[j++];
        } else if(j == right_size) {
            data[k] = left_data[i++];
        } else if(left_data[i] > right_data[j]) {
            data[k] = left_data[i++];
        } else {
            data[k] = right_data[j++];
        }
    }
}
