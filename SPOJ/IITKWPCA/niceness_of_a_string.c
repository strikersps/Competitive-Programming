/*
 * Problem Statement: https://www.spoj.com/problems/IITKWPCA/
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

#define MAX_STRING_LENGTH 10002

typedef struct node {
    char *word;
    struct node *next;
} node_t;

static int compute_niceness_value(char*);
static node_t * makenode_list(char[]);
static void insert_node_list(node_t*, node_t*);
static bool search_data_list(const node_t*, char[]);
static int compute_list_length(node_t*);

int main(void) {
    int test;
    if(1 == scanf("%d", &test)) {
        getchar_unlocked();
        while(test--) {
            char sentence[MAX_STRING_LENGTH];
            if(fgets(sentence, MAX_STRING_LENGTH, stdin)) {
                char *const enter_char_loc = strchr(sentence, '\n');
                if(enter_char_loc) {
                    *enter_char_loc = '\0';
                }
                printf("%d\n", !strchr(sentence, ' ') ? 1 : compute_niceness_value(sentence));
            } else {
                fprintf(stderr, "Line number: %u: Not able to read the string from stdin.\n", __LINE__);
                exit(0);
            }
        }
    } else {
        SCANF_READ_ERROR(1);
    }
    return EXIT_SUCCESS;
}

static node_t * makenode_list(char data[]) {
    node_t *new_node = malloc(sizeof*new_node);
    if(new_node) {
        new_node->word = data;
        new_node->next = NULL;
    } else {
        MEMORY_ALLOCATION_FAILED_ERROR(new_node, sizeof*new_node);
        exit(0);
    }
    return new_node;
}

static void insert_node_list(node_t *traverse_ptr, node_t *new_node) {
    for(; traverse_ptr->next; traverse_ptr = traverse_ptr->next);
    traverse_ptr->next = new_node;
}

static bool search_data_list(const node_t *traverse_ptr, char search_data[]) {
    bool is_present = false;
    for(; traverse_ptr; traverse_ptr = traverse_ptr->next) {
        if(!strcmp(traverse_ptr->word, search_data)) {
            is_present = true;
            break;
        }
    }
    return is_present;
}

static int compute_list_length(node_t *traverse_ptr) {
    int list_length = 0;
    for(node_t *del_node = traverse_ptr; traverse_ptr; ++list_length) {
        traverse_ptr = traverse_ptr->next;
        free(del_node->word);
        free(del_node);
        del_node = traverse_ptr;
    }
    return list_length;
}

static int compute_niceness_value(char *sentence) {
    node_t *head_ptr = NULL;
    char *start_loc = sentence;
    unsigned long int whitespace_count, read_char_count;
    whitespace_count = read_char_count = 0;
    for(register int i = 0; sentence[i]; ++i) {
        if(sentence[i] == ' ') {
            ++whitespace_count;
            if(read_char_count && whitespace_count == 1) {
                char *token = calloc((size_t) (1 + read_char_count), sizeof*token);
                if(token) {
                    memcpy(token, start_loc, (read_char_count * sizeof*token));
                    token[read_char_count] = '\0';
                    read_char_count = 0;
                    if(!head_ptr) {
                        head_ptr = makenode_list(token);
                        continue;
                    }
                    if(!search_data_list(head_ptr, token)) {
                        insert_node_list(head_ptr, makenode_list(token));
                        continue;
                    }
                    free(token);
                } else {
                    MEMORY_ALLOCATION_FAILED_ERROR(token, 1 + read_char_count * sizeof*token);
                    exit(0);
                }
            }
            continue;
        }
        whitespace_count = 0;
        ++read_char_count;
        if(read_char_count == 1) {
            start_loc = sentence + i;
        }
    }
    if(read_char_count) {
        char *token = calloc((size_t) (1 + read_char_count), sizeof*token);
        if(token) {
            token[read_char_count] = '\0';
            memcpy(token, start_loc, read_char_count * sizeof*token);
            if(!search_data_list(head_ptr, token)) {
                insert_node_list(head_ptr, makenode_list(token));
            } else {
                free(token);
            }
        } else {
            MEMORY_ALLOCATION_FAILED_ERROR(token, 1 + read_char_count* sizeof*token);
        }
    }
    return compute_list_length(head_ptr);
}
