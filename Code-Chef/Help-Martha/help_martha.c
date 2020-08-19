/*
 * Problem Statement: https://www.codechef.com/CENS2020/problems/CENS20G
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

#include <assert.h>
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

// Constant Macros.
#define MOD (1000000000 + 7) // Prime Number
#define PI 3.141592653589793 // Number of digits(15) of Pi which JPL uses for Interplanetary Caculations.
#define GOLDEN_RATIO 1.618033988749895 // Number of digits(15).

// Error-Handling Macros.
#define MEMORY_ALLOCATION_FAILED_ERROR(variable, bytes) fprintf(stderr, "Line number: %u: Not able to allocate <%lu> bytes of memory to <%s> variable.\n", __LINE__, (bytes), #variable)
#define CONSTRAINTS_OUT_OF_BOUND_ERROR(variable, constraints) fprintf(stderr, "Line number: %u: Constraints not satisfied for the variable <%s>, i.e. %s.\n", __LINE__, #variable, #constraints)
#define SCANF_READ_ERROR(expected_return_val) fprintf(stderr, "Line number: %u: scanf() read error!\nExpected-Return-Value: %d.\n", __LINE__, (expected_return_val)); exit(0)
#define STREAM_LINK_ERROR(file_path, stream_name) fprintf(stderr, "Line number: %u: Stream Link Error! Not able to link <%s> file to <%s> stream.\n", __LINE__, #file_path, #stream_name); exit(0)

// Initialisation Macros.
#define INITIALISE_INT_CONTAINER_ZERO(container, bytes) memset(container, 0, (bytes))
#define INITIALISE_CHAR_CONTAINER_ZERO(container, bytes) memset(container, '\0', (bytes))

// Mathematical Macros.
#define FIND_MAX(a, b) (a) > (b) ? (a) : (b)
#define FIND_MIN(a, b) (a) < (b) ? (a) : (b)
#define FIND_MID(start, end) (((end) - (start)) / 2) + (start)

// Bit-Manipulation Macros.
#define COMPUTE_SET_BITS(number) __builtin_popcountll(number) // Returns the number of set-bits in number (unsigned long long).
#define COMPUTE_PARITY(number) __builtin_parityll(number) // Returns the parity of the number (unsigned long long) i.e. True if 1's are odd else False.
#define COUNT_LEAD_ZEROES(number) __builtin_clzll(number) // Returns the count of lead zeroes before first set-bit from MSB in number (unsigned long long).
#define COUNT_TRAIL_ZEROES(number) __builtin_ctzll(number) // Return the count of trailing zeroes in number(unsigned long long).

/*END OF CODE-TEMPLATE*/

#define MAX_STRING_LENGTH 1000001

static void execute_queries(const char *, const point_2d_t *);

int main(void) {
    int test;
    if(1 != scanf("%d", &test)) {
        SCANF_READ_ERROR(1);
    }
    char *const direction = calloc(MAX_STRING_LENGTH, sizeof*direction);
    if(!direction) {
        MEMORY_ALLOCATION_FAILED_ERROR(direction, MAX_STRING_LENGTH * sizeof*direction);
        exit(0);
    }
    while(test--) {
        INITIALISE_CHAR_CONTAINER_ZERO(direction, MAX_STRING_LENGTH * sizeof*direction);
        if(1 != scanf("%s", direction)) {
            SCANF_READ_ERROR(1);
        }
        point_2d_t start_position;
        if(2 != scanf("%d%d", &start_position.x, &start_position.y)) {
            SCANF_READ_ERROR(2);
        }
        execute_queries(direction, &start_position);
    }
    free(direction);
    return EXIT_SUCCESS;
}

static void execute_queries(const char *direction, const point_2d_t *start_position) {
    int total_queries;
    if(1 != scanf("%d", &total_queries)) {
        SCANF_READ_ERROR(1);
    }
    int count_direction[] = {0, 0, 0, 0};
    for(int i = 0; direction[i]; ++i) {
        switch(direction[i]) {
            case 'R': {
                ++count_direction[0];
            }
            break;
            case 'L': {
                ++count_direction[1];
            }
            break;
            case 'U': {
                ++count_direction[2];
            }
            break;
            case 'D': {
                ++count_direction[3];
            }
            break;
        }
    }
    while(total_queries--) {
        point_2d_t final_position;
        if(2 != scanf("%d%d", &final_position.x, &final_position.y)) {
            SCANF_READ_ERROR(2);
        }
        int x_coordinate_diff = final_position.x - start_position->x;
        int y_coordinate_diff = final_position.y - start_position->y;
        if(((x_coordinate_diff > 0 && x_coordinate_diff <= count_direction[0]) || (x_coordinate_diff < 0 && abs(x_coordinate_diff) <= count_direction[1]) || !x_coordinate_diff) && ((y_coordinate_diff > 0 && y_coordinate_diff <= count_direction[2]) || (y_coordinate_diff < 0 && abs(y_coordinate_diff) <= count_direction[3]) || !y_coordinate_diff)) {
            printf("%s %d\n", "YES", abs(x_coordinate_diff) + abs(y_coordinate_diff));
        } else {
            printf("%s\n", "NO");
        }
    }
}

