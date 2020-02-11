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

// The below function macros refers to the GCC functions for doing computation directly on the bit-level of a number.
#define COMPUTE_SET_BITS(number) __builtin_popcountll(number) // Returns the number of set-bits in number (unsigned long long).
#define COMPUTE_PARITY(number) __builtin_parityll(number) // Returns the parity of the number (unsigned long long) i.e. True if 1's are odd else False.
#define COUNT_LEAD_ZEROES(number) __builtin_clzll(number) // Returns the count of lead zeroes before first set-bit from MSB in number (unsigned long long).
#define COUNT_TRAIL_ZEROES(number) __builtin_ctzll(number) // Return the count of trailing zeroes in number(unsigned long long).

typedef struct sequence {
    int number;
    bool is_ignore;
} sequence_t;

static void display_data(const sequence_t*, const int, const char*);

int main(void) {
    int n;
    scanf("%d", &n);
    if(n < 1) {
        CONSTRAINTS_OUT_OF_BOUND_ERROR(n, size of array cannot be 0 or -ve);
        exit(0);
    }
    sequence_t data[n];
    int max_val = INT_MIN, first_index = -1;
    for(register int i = 0; i < n; ++i) {
        scanf("%d", &data[i].number);
        if(data[i].number > max_val) {
            max_val = data[i].number;
            first_index = i;
        }
        data[i].is_ignore = false;
    }
    unsigned int count_max = 0;
    for(register int i = 0; i < n; ++i) {
        if(data[i].number == max_val) {
            ++count_max;
        }
        if(count_max == 3) {
            data[i].is_ignore = true;
            break;
        }
    }
    if(count_max < 3) {
        data[first_index].is_ignore = true;
    }
    display_data(data, n, " ");
    return EXIT_SUCCESS;
}

static void display_data(const sequence_t *data, const int n, const char *delimiter) {
    if(!data[0].is_ignore) {
        printf("%d", data[0].number);
    }
    for(register int i = 1; i < n; ++i) {
        if(!data[i].is_ignore) {
            printf("%s%d", delimiter, data[i].number);
        }
    }
    printf("\n");
}
