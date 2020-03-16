/*
 * Problem Statement: https://www.codechef.com/problems/COPS
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
} point_2d_t;

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

#define MAX_HOUSES 100

static int compute_safe_house(int[], const int, const int);

int main(void) {
    int test;
    if(1 == scanf("%d", &test)) {
        while(test--) {
            int tot_cops, x, y;
            if(3 == scanf("%d%d%d", &tot_cops, &x, &y)) {
                int cop_location[tot_cops];
                for(register int i = 0; i < tot_cops; ++i) {
                    if(1 != scanf("%d", cop_location + i)) {
                        SCANF_READ_ERROR(1);
                    }
                }
                printf("%d\n", compute_safe_house(cop_location, tot_cops, x * y));
            } else {
                SCANF_READ_ERROR(3);
            }
        }
    } else {
        SCANF_READ_ERROR(1);
    }
    return EXIT_SUCCESS;
}

static int compute_safe_house(int cop_location[], const int tot_cops, const int search_range) {
    bool cop_present[MAX_HOUSES];
    INITIALISE_INT_CONTAINER_ZERO(cop_present, MAX_HOUSES * sizeof(bool));
    for(register int i = 0; i < tot_cops; ++i) {
        int start = 0, end = MAX_HOUSES - 1;
        if((cop_location[i] - search_range) >= 1) {
            start = cop_location[i] - search_range - 1;
        }
        if((cop_location[i] + search_range < MAX_HOUSES)) {
            end = cop_location[i] + search_range - 1;
        }
        for(register int j = start; j <= end; cop_present[j] = true, ++j);
    }
    int count_safe_house = 0;
    for(register int i = 0; i < MAX_HOUSES; ++i) {
        if(!cop_present[i]) {
            ++count_safe_house;
            continue;
        }
    }
    return count_safe_house;
}
