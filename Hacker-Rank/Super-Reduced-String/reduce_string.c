/*
 * Problem Statement: https://www.hackerrank.com/challenges/reduced-string/problem
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

#define MAX_STRING_LENGTH 101

typedef struct node {
    char data;
    struct node *prev, *next;
} node_t;

static node_t * reduce_string(char[]);
static node_t * make_node_list(const char);
static node_t * insert_node_list(node_t*, node_t *const);
static node_t * find_tail_list(const node_t*);
static void traverse_list(const node_t*);
static void free_memory(node_t*);

int main(void) {
    /* Hacker-Rank doesn't have a ONLINE_JUDGE macro defined.
    #ifndef ONLINE_JUDGE
        freopen("test-cases/test-case-1.in", "r", stdin);
        freopen("test-cases/test-case-1.out", "w", stdout);
    #endif
    */
    char string_data[MAX_STRING_LENGTH];
    scanf("%s", string_data);
    node_t *const list_head = reduce_string(string_data);
    if(list_head) {
        node_t *list_tail = find_tail_list(list_head);
        traverse_list(list_tail);
        printf("\n");
        free_memory(list_head);
    } else {
        printf("Empty String\n");
    }
    return EXIT_SUCCESS;
}

static node_t * reduce_string(char string_data[]) {
    node_t *list_head = NULL;
    for(int i = 0; '\0' != string_data[i]; ++i) {
        if(list_head && string_data[i] == (list_head->data)) {
            node_t *const tmp_ptr = list_head->next;
            if(tmp_ptr) {
                tmp_ptr->prev = list_head->prev;
            }
            free(list_head);
            list_head = tmp_ptr;
            continue;
        }
        list_head = insert_node_list(list_head, make_node_list(string_data[i]));
    }
    return list_head;
}

static node_t * make_node_list(const char letter) {
    node_t *const new_node = malloc(sizeof*new_node);
    if(new_node) {
        new_node->data = letter;
        new_node->prev = NULL;
        new_node->next = NULL;
    } else {
        MEMORY_ALLOCATION_FAILED_ERROR(new_node, sizeof*new_node);
        exit(0);
    }
    return new_node;
}

static node_t * insert_node_list(node_t *list_head, node_t *const new_node) {
    if(list_head) {
        new_node->next = list_head;
        list_head->prev = new_node;
        list_head = new_node;
    } else {
        list_head = new_node;
    }
    return list_head;
}

static node_t * find_tail_list(const node_t *traverse_ptr) {
    for(; traverse_ptr->next; traverse_ptr = traverse_ptr->next);
    return (node_t*) traverse_ptr;
}

static void traverse_list(const node_t *traverse_ptr) {
    for(; traverse_ptr; traverse_ptr = traverse_ptr->prev) {
        printf("%c", traverse_ptr->data);
    }
}

static void free_memory(node_t *traverse_ptr) {
    node_t *del_node = NULL;
    for(; traverse_ptr; ) {
        del_node = traverse_ptr;
        traverse_ptr = traverse_ptr->next;
        free(del_node);
    }
}
