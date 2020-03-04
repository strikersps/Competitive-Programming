/*
 * Problem Statement: https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/anagrams-651/
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
#define SCANF_READ_ERROR(return_val) fprintf(stderr, "Line number: %u: scanf() read error.\nExpected-Return-Value: %d\n", __LINE__, return_val); exit(0)
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

#define MAX_STRING_LENGTH 10001
#define NUMBER_OF_ALPHABETS 26

static int compute_min_deletions(char[], char[]);

int main(void) {
    /* Hacker-Earth doesn't have an ONLINE_JUDGE macro defined.
    #ifndef ONLINE_JUDGE
        freopen("test-cases/test-case-1.in", "r", stdin);
        freopen("test-cases/test-case-1.out", "w", stdout);
    #endif
    */
    int test;
    if(1 == scanf("%d", &test)) {
        if(test < 1) {
            CONSTRAINTS_OUT_OF_BOUND_ERROR(test, test value cannot be 0 or -ve);
            exit(0);
        }
        while(test--) {
            char word1[MAX_STRING_LENGTH], word2[MAX_STRING_LENGTH];
            if(2 == scanf("%s%s", word1, word2)) {
                printf("%d\n", compute_min_deletions(word1, word2));
            } else {
                SCANF_READ_ERROR(2);
            }
        }
    } else {
        SCANF_READ_ERROR(1);
    }
    return EXIT_SUCCESS;
}

static int compute_min_deletions(char word1[], char word2[]) {
    int freq_map_word1[NUMBER_OF_ALPHABETS], freq_map_word2[NUMBER_OF_ALPHABETS];
    INITIALISE_INT_CONTAINER_ZERO(freq_map_word1, NUMBER_OF_ALPHABETS * sizeof(int));
    INITIALISE_INT_CONTAINER_ZERO(freq_map_word2, NUMBER_OF_ALPHABETS * sizeof(int));
    for(register int i = 0; word1[i] != '\0'; ++freq_map_word1[word1[i] - 'a'], ++i);
    for(register int i = 0; word2[i] != '\0'; ++freq_map_word2[word2[i] - 'a'], ++i);
    int min_deletions = 0;
    for(register int i = 0; i < NUMBER_OF_ALPHABETS; ++i) {
        min_deletions += abs(freq_map_word1[i] - freq_map_word2[i]);
    }
    return min_deletions;
}
