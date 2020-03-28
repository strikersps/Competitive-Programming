/*
 * Problem Statement: https://www.spoj.com/problems/ONP/
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

#define MAX_EXPRESSION_LENGTH 401

typedef struct node {
    char operator;
    struct node *next;
} node_t;

static int operator_priority(const char);
static node_t * make_node_list(const char);
static node_t * push_back_list(node_t*, node_t*);
static char * expression_to_rpn_form(const char*);

int main(void) {
    int test;
    if(1 != scanf("%d", &test)) {
        SCANF_READ_ERROR(1);
    }
    while(test--) {
        char expression[MAX_EXPRESSION_LENGTH];
        if(1 != scanf("%s", expression)) {
            SCANF_READ_ERROR(1);
        }
        char *const rpn_expression = expression_to_rpn_form(expression);
        puts(rpn_expression);
        free(rpn_expression);
    }
    return EXIT_SUCCESS;
}

static int operator_priority(const char operator) {
    int priority_val = 0;
    switch(operator) {
        case '^':
            priority_val = 5;
            break;
        case '/':
            priority_val = 4;
            break;
        case '*':
            priority_val = 3;
            break;
        case '-':
            priority_val = 2;
            break;
        case '+':
            priority_val = 1;
            break;
    }
    return priority_val;
}

static node_t * make_node_list(const char data) {
    node_t *new_node = malloc(sizeof*new_node);
    if(!new_node) {
        MEMORY_ALLOCATION_FAILED_ERROR(new_node, sizeof*new_node);
        exit(0);
    }
    new_node->operator = data;
    new_node->next = NULL;
    return new_node;
}

static node_t * push_back_list(node_t *head_node, node_t *new_node) {
    if(!head_node) {
        return new_node;
    }
    new_node->next = head_node;
    head_node = new_node;
    return head_node;
}

static char * expression_to_rpn_form(const char *expression) {
    size_t rpn_expression_len = 0;
    for(register int i = 0; expression[i] != '\0'; ++i) {
        if(expression[i] == '(' || expression[i] == ')') {
            ++rpn_expression_len;
            continue;
        }
    }
    rpn_expression_len = (1 + strlen(expression)) - rpn_expression_len;
    char *rpn_expression = calloc(rpn_expression_len, sizeof*rpn_expression);
    if(!rpn_expression) {
        MEMORY_ALLOCATION_FAILED_ERROR(rpn_expression, (rpn_expression_len * sizeof*rpn_expression));
        exit(0);
    }
    node_t *head_node = NULL;
    register int i, j;
    for(i = 0, j = 0; expression[i] != '\0'; ++i) {
        if(expression[i] == '(') {
            head_node = push_back_list(head_node, make_node_list(expression[i]));
            continue;
        }
        if(expression[i] == '^' || expression[i] == '/' || expression[i] == '*' || expression[i] == '-' || expression[i] == '+') {
            if(head_node && operator_priority(head_node->operator) > operator_priority(expression[i])) {
                while(head_node && (operator_priority(head_node->operator) > operator_priority(expression[i]) || head_node->operator != '(')) {
                    rpn_expression[j++] = head_node->operator;
                    node_t *del_node = head_node;
                    head_node = head_node->next;
                    free(del_node);
                }
            }
            head_node = push_back_list(head_node, make_node_list(expression[i]));
            continue;
        }
        if(expression[i] == ')') {
            node_t *del_node = NULL;
            for(; head_node->operator != '('; head_node = head_node->next, free(del_node)) {
                rpn_expression[j++] = head_node->operator;
                del_node = head_node;
            }
            del_node = head_node;
            head_node = head_node->next;
            free(del_node);
            continue;
        }
        rpn_expression[j++] = expression[i];
    }
    while((size_t) j < (rpn_expression_len - 1)) {
        rpn_expression[j++] = head_node->operator;
        node_t *del_node = head_node;
        head_node = head_node->next;
        free(del_node);
    }
    rpn_expression[j] = '\0';
    return rpn_expression;
}
