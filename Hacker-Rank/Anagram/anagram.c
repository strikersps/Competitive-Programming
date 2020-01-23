/*
 * Problem Statement: https://www.hackerrank.com/challenges/anagram/problem
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

#define MEMORY_ALLOCATION_FAILED_ERROR(variable, bytes) fprintf(stderr, "Line number: %u: Not able to allocate <%lu> bytes of memory to <%s> variable.\n", __LINE__, (bytes), #variable)
#define CONSTRAINTS_OUT_OF_BOUND_ERROR(variable, constraints) fprintf(stderr, "Line number: %u: Constraints not satisfied for the variable <%s>, i.e. %s.\n", __LINE__, #variable, #constraints)
#define INITIALISE_INT_CONTAINER_ZERO(container, bytes) memset(container, 0, (bytes))
#define INITIALISE_CHAR_CONTAINER_ZERO(container, bytes) memset(container, '0', (bytes))
#define FIND_MAX(a, b) (a) > (b) ? (a) : (b)
#define FIND_MIN(a, b) (a) < (b) ? (a) : (b)
#define FIND_MID(start, end) (((end) - (start)) >> 1) + (start)

#define MAX_STRING_LENGTH 10001
#define NUMBER_OF_ALPHABETS 26

static int compute_min_characters(char[]);

int main(void) {
    /* Hacker-Rank Online Judge doesn't have ONLINE_JUDGE macro defined.
    #ifndef ONLINE_JUDGE
        freopen("test-cases/test-case-1.in", "r", stdin);
        freopen("test-cases/test-case-1.out", "w", stdout);
    #endif
    */
    int test;
    scanf("%d", &test);
    while(test--) {
        char word[MAX_STRING_LENGTH];
        scanf("%s", word);
        printf("%d\n", compute_min_characters(word));
    }
    return EXIT_SUCCESS;
}

static int compute_min_characters(char word[]) {
    unsigned int word_len = strlen(word);
    if(word_len % 2) {
        return -1;
    }
    int size = (word_len >> 1);
    int char_freq[NUMBER_OF_ALPHABETS];
    INITIALISE_INT_CONTAINER_ZERO(char_freq, NUMBER_OF_ALPHABETS * sizeof(int));
    for(int i = 0; i < size; ++i) {
        ++char_freq[word[i] - 'a'];
    }
    for(int i = size; '\0' != word[i]; ++i) {
        if(char_freq[word[i] - 'a']) {
            --char_freq[word[i] - 'a'];
        }
    }
    unsigned int min_ops = 0;
    for(int i = 0; i < NUMBER_OF_ALPHABETS; ++i) {
        if(!char_freq[i]) {
            continue;
        }
        min_ops += char_freq[i];
    }
    return min_ops;
}
