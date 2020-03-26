/*
 * Problem Statement: https://www.spoj.com/problems/MMASS/
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

#define MAX_STRING_LENGTH 101

typedef struct node {
    int data;
    struct node *next;
} node_t;

static int compute_mass_of_atom(const char);
static node_t * make_node_list(const int);
static node_t * push_back_list(node_t*, node_t*);
static int compute_molecular_mass(char[]);

int main(void) {
    char molecular_formula[MAX_STRING_LENGTH];
    if(1 != scanf("%s", molecular_formula)) {
        SCANF_READ_ERROR(1);
    }
    printf("%d\n", compute_molecular_mass(molecular_formula));
    return EXIT_SUCCESS;
}

static int compute_mass_of_atom(const char atom_name) {
    int atomic_mass = 0;
    switch(atom_name) {
        case 'H':
            atomic_mass = 1;
            break;
        case 'C':
            atomic_mass = 12;
            break;
        case 'O':
            atomic_mass = 16;
            break;
    }
    return atomic_mass;
}

static node_t * make_node_list(const int d) {
    node_t *new_node = malloc(sizeof*new_node);
    if(!new_node) {
        MEMORY_ALLOCATION_FAILED_ERROR(new_node, sizeof*new_node);
        exit(0);
    }
    new_node->data = d;
    new_node->next = NULL;
    return new_node;
}

static node_t * push_back_list(node_t *head, node_t *new_node) {
    new_node->next = head;
    head = new_node;
    return head;
}

static int compute_molecular_mass(char molecular_formula[]) {
    node_t *head, *del_node;
    head = del_node = NULL;
    for(register int i = 0; molecular_formula[i] != '\0'; ++i) {
        if(molecular_formula[i] == ')') {
            int intermediate_mass = 0;
            for(del_node = NULL; head->data != '('; head = head->next, free(del_node)) {
                del_node = head;
                intermediate_mass += head->data;
            }
            del_node = head;
            head = head->next;
            free(del_node);
            head = push_back_list(head, make_node_list(intermediate_mass));
            continue;
        }
        if(molecular_formula[i] == '(') {
            head = push_back_list(head, make_node_list('('));
            continue;
        }
        if(molecular_formula[i] >= '2' && molecular_formula[i] <= '9') {
            head->data *= (molecular_formula[i] - '0');
            continue;
        }
        head = push_back_list(head, make_node_list(compute_mass_of_atom(molecular_formula[i])));
    }
    int molecular_mass = 0;
    for(del_node = NULL; head; head = head->next, free(del_node)) {
        del_node = head;
        molecular_mass += head->data;
    }
    return molecular_mass;
}
