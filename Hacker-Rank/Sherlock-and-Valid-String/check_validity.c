/*
 * Problem Statement: https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem
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
#define PI 3.141592653589793 // Number of digits(15) of Pi which JPL uses for Interplanetary Calculations.
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

#define MAX_STRING_LIMIT 100001 // Max-Limit on the string size of 10^5 as per the problem.
#define TOTAL_ALPHABETS 26 // In English their are 26 alphabets.

int comparator_callback(const void*, const void*);
static int compute_unique_numbers(const int*);
static int compute_max_value(const int*);
static int compute_min_value(const int*);
static bool check_validity(const int*);

int main(void) {
    char *const data_string = calloc(MAX_STRING_LIMIT, sizeof*data_string);
    if(!data_string) {
        MEMORY_ALLOCATION_FAILED_ERROR(data_string, MAX_STRING_LIMIT * sizeof*data_string);
        exit(0);
    }
    if(1 != scanf("%s", data_string)) {
        SCANF_READ_ERROR(1);
    }
    int *const freq_map = calloc(TOTAL_ALPHABETS, sizeof*freq_map);
    if(!freq_map) {
        MEMORY_ALLOCATION_FAILED_ERROR(freq_map, TOTAL_ALPHABETS * sizeof*freq_map);
        exit(0);
    }
    INITIALISE_INT_CONTAINER_ZERO(freq_map, TOTAL_ALPHABETS * sizeof*freq_map);
    for(int i = 0; data_string[i]; freq_map[data_string[i++] - 'a'] += 1);
    qsort(freq_map, TOTAL_ALPHABETS, sizeof*freq_map, comparator_callback);
    printf("%s\n", check_validity(freq_map) ? "YES" : "NO");
    free(freq_map);
    free(data_string);
    return EXIT_SUCCESS;
}

int comparator_callback(const void *a, const void *b) {
    return *((int*) a) > *((int*) b);
}

// The sequence must be sorted before passing it to the compute_unique_numbers function.
static int compute_unique_numbers(const int *sequence) {
    int count_unique_items = 0;
    for(int i = 1; i < TOTAL_ALPHABETS; ++i) {
        if(sequence[i] != sequence[i - 1]) {
            ++count_unique_items;
        }
    }
    return count_unique_items;
}

static int compute_min_value(const int *sequence) {
    int min_val = MAX_STRING_LIMIT;
    for(int i = 0; i < TOTAL_ALPHABETS; ++i) {
        if(sequence[i] && sequence[i] < min_val) {
            min_val = sequence[i];
        }
    }
    return min_val;
}

static int compute_max_value(const int *sequence) {
    int max_val = 0;
    for(int i = 0; i < TOTAL_ALPHABETS; ++i) {
        if(sequence[i] > max_val) {
            max_val = sequence[i];
        }
    }
    return max_val;
}

static bool check_validity(const int *freq_map) {
    int count_unique_numbers = compute_unique_numbers(freq_map);
    int freq_map_actual_size = 0;
    for(int i = 0; i < TOTAL_ALPHABETS; ++i) {
        if(freq_map[i]) {
            ++freq_map_actual_size;
        }
    }
    if(count_unique_numbers > 2) {
        return false;
    }
    if(count_unique_numbers == 2) {
        int max_val = compute_max_value(freq_map);
        int min_val = compute_min_value(freq_map);
        int count_max_val = 0;
        for(int i = 0; i < TOTAL_ALPHABETS; ++i) {
            if(freq_map[i] == max_val) {
                ++count_max_val;
            }
        }
        if((count_max_val == freq_map_actual_size - 1 && min_val == 1) || (count_max_val == 1 && max_val - min_val == 1)) {
            return true;
        }
        return false;
    }
    return true;
}
