/*
 * Problem Statement: https://www.spoj.com/problems/YODANESS/
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
#define INTIALISE_CHAR_CONTAINER_ZERO(container, bytes) memset(container, '0', (bytes))
#define FIND_MAX(a, b) (a) > (b) ? (a) : (b)
#define FIND_MIN(a, b) (a) < (b) ? (a) : (b)
#define FIND_MID(start, end) (((end) - (start)) >> 1) + (start)

#define MAX_WORD_LENGTH 21

typedef struct Sentence {
    char word[MAX_WORD_LENGTH];
    unsigned int index;
} sentence_t;

int comparator_callback(const void*, const void*);
static int string_binary_search(const sentence_t *const, int, int, const char *const);
static ull_t compute_yodaness_level_of_sentence(sentence_t *const, const int, sentence_t *const, const int, const int);
static ull_t compute_inversion_of_words(sentence_t *const, const int, sentence_t *const, const int, const int, const int);

int main(void) {
    #ifndef ONLINE_JUDGE
        freopen("test-cases/test-case-1.in", "r", stdin);
        freopen("test-cases/test-case-1.out", "w", stdout);
    #endif
    int test;
    scanf("%d", &test);
    while(test--) {
        int number_of_words;
        scanf("%d", &number_of_words);
        sentence_t said_sentence[number_of_words];
        sentence_t actual_sentence[number_of_words];
        for(int i = 0; i < number_of_words; ++i) {
            scanf("%s", said_sentence[i].word);
            said_sentence[i].index = i;
        }
        for(int i = 0; i < number_of_words; ++i) {
            scanf("%s", actual_sentence[i].word);
            actual_sentence[i].index = i;
        }
        qsort(actual_sentence, number_of_words, sizeof*actual_sentence, comparator_callback);
        printf("%llu\n", compute_yodaness_level_of_sentence(actual_sentence, number_of_words, said_sentence, 0, number_of_words - 1));
    }
    return EXIT_SUCCESS;
}

int comparator_callback(const void *d1, const void *d2) {
    return strcmp(((sentence_t*) d1)->word, ((sentence_t*) d2)->word);
}

static int string_binary_search(const sentence_t *const sentence, int start, int end, const char *const search_word) {
    int found_index = -1;
    while(start <= end) {
        const int mid = FIND_MID(start, end);
        if(!strcmp(sentence[mid].word, search_word)) {
            found_index = mid;
            break;
        } else if(strcmp(search_word, sentence[mid].word) > 0) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    if(!(-1 == found_index)) {
        return sentence[found_index].index;
    } else {
        return -1;
    }
}

static ull_t compute_yodaness_level_of_sentence(sentence_t *const actual_sentence, const int len_of_actual_sentence, sentence_t *const said_sentence, const int start, const int end) {
    ull_t inversion_count = 0;
    if(start < end) {
        const int mid = FIND_MID(start, end);
        inversion_count = compute_yodaness_level_of_sentence(actual_sentence, len_of_actual_sentence, said_sentence, start, mid);
        inversion_count += compute_yodaness_level_of_sentence(actual_sentence, len_of_actual_sentence, said_sentence, mid + 1, end);
        inversion_count += compute_inversion_of_words(actual_sentence, len_of_actual_sentence, said_sentence, start, mid, end);
    }
    return inversion_count;
}

static ull_t compute_inversion_of_words(sentence_t *const actual_sentence, const int len_of_actual_sentence, sentence_t *const said_sentence, const int start, const int mid, const int end) {
    const int left_size = (mid - start) + 1;
    sentence_t left_data[left_size];
    memcpy(left_data, &said_sentence[start], left_size * sizeof(sentence_t));
    const int right_size = end - mid;
    sentence_t right_data[right_size];
    memcpy(right_data, &said_sentence[mid + 1], right_size * sizeof(sentence_t));
    ull_t inversion_count = 0;
    for(int i = 0, j = 0, k = start; k <= end; ++k) {
        if(i == left_size) {
            memcpy(&said_sentence[k], &right_data[j], sizeof(sentence_t));
            ++j;
        } else if(j == right_size) {
            memcpy(&said_sentence[k], &left_data[i], sizeof(sentence_t));
            ++i;
        } else if(string_binary_search(actual_sentence, 0, len_of_actual_sentence - 1, left_data[i].word) > string_binary_search(actual_sentence, 0, len_of_actual_sentence, right_data[j].word)) {
            inversion_count += (left_size - i);
            memcpy(&said_sentence[k], &right_data[j], sizeof(sentence_t));
            ++j;
        } else {
            memcpy(&said_sentence[k], &left_data[i], sizeof(sentence_t));
            ++i;
        }
    }
    return inversion_count;
}
