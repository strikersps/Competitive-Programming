/*
 * Problem Statement: https://www.spoj.com/problems/BYTESM2
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

static int compute_maximum_element(const int *const, const int);
static int compute_maximum_path_cost(int **const, const int, const int);
static void free_dynamic_memory(int **const, const int);

int main(void) {
    int test;
    if(1 != scanf("%d", &test)) {
        SCANF_READ_ERROR(1);
    }
    while(test--) {
        int nrows, ncols;
        if(2 == scanf("%d%d", &nrows, &ncols)) {
            int **const matrix = calloc((size_t) nrows, sizeof*matrix);
            if(!matrix) {
                MEMORY_ALLOCATION_FAILED_ERROR(matrix, (size_t) nrows * sizeof*matrix);
                exit(0);
            }
            for(int i = 0; i < nrows; ++i) {
                matrix[i] = calloc((size_t) ncols, sizeof**matrix);
                if(!matrix[i]) {
                    MEMORY_ALLOCATION_FAILED_ERROR(matrix[i], (size_t) ncols * sizeof**matrix);
                    exit(0);
                }
                for(int j = 0; j < ncols; ++j) {
                    if(1 != scanf("%d", &matrix[i][j])) {
                        SCANF_READ_ERROR(1);
                    }
                }
            }
            printf("%d\n", compute_maximum_path_cost(matrix, nrows, ncols));
            free_dynamic_memory(matrix, nrows);
            continue;
        }
        SCANF_READ_ERROR(2);
    }
    return EXIT_SUCCESS;
}

static int compute_maximum_element(const int *const sequence, const int n) {
    int max_value = 0;
    for(int i = 0; i < n; ++i) {
        if(sequence[i] > max_value) {
            max_value = sequence[i];
        }
    }
    return max_value;
}

static int compute_maximum_path_cost(int **const matrix, const int nrows, const int ncols) {
    if(nrows == 1 && ncols == 1) {
        return matrix[0][0];
    }
    if(nrows == 1) {
        return compute_maximum_element(matrix[0], ncols);
    }
    if(ncols == 1) {
        int value_sum = 0;
        for(int i = 0; i < nrows; ++i) {
            value_sum += matrix[i][0];
        }
        return value_sum;
    }
    int *cost_matrix, *temp_matrix;
    cost_matrix = calloc((size_t) ncols, sizeof*cost_matrix);
    if(!cost_matrix) {
        MEMORY_ALLOCATION_FAILED_ERROR(cost_matrix, (size_t) ncols * sizeof*cost_matrix);
        exit(0);
    }
    temp_matrix = calloc((size_t) ncols, sizeof*temp_matrix);
    if(!temp_matrix) {
        MEMORY_ALLOCATION_FAILED_ERROR(temp_matrix, (size_t) ncols * sizeof*temp_matrix);
        exit(0);
    }
    for(int j = 0; j < ncols; ++j) {
        cost_matrix[j] = matrix[0][j];
    }
    for(int i = 1; i < nrows; ++i) {
        for(int j = 0; j < ncols; ++j) {
            if(!j) {
                temp_matrix[j] = FIND_MAX(cost_matrix[j] + matrix[i][j], cost_matrix[j + 1] + matrix[i][j]);
                continue;
            }
            if(j == ncols - 1) {
                temp_matrix[j] = FIND_MAX(cost_matrix[j] + matrix[i][j], cost_matrix[j - 1] + matrix[i][j]);
                continue;
            }
            temp_matrix[j] = FIND_MAX(FIND_MAX(cost_matrix[j - 1] + matrix[i][j], cost_matrix[j] + matrix[i][j]), cost_matrix[j + 1] + matrix[i][j]);
        }
        for(int j = 0; j < ncols; ++j) {
            cost_matrix[j] = temp_matrix[j];
        }
    }
    int max_cost = compute_maximum_element(cost_matrix, ncols);
    free(cost_matrix);
    free(temp_matrix);
    return max_cost;
}

static void free_dynamic_memory(int **const matrix, const int nrows) {
    for(int i = 0; i < nrows; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}
