/*
 * Problem Statement: https://www.spoj.com/problems/HPYNOS/
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

typedef struct node {
    int data;
    struct node *next;
} node_t;

#define MOD (1000000000 + 7) // Prime Number
#define PI 3.141592653589793 // Number of digits(15) of Pi which JPL uses for Interplanetary Caculations.

#define MEMORY_ALLOCATION_FAILED_ERROR(variable, bytes) fprintf(stderr, "Line number: %u: Not able to allocate <%lu> bytes of memory to <%s> variable.\n", __LINE__, (bytes), #variable)
#define CONSTRAINTS_OUT_OF_BOUND_ERROR(variable, constraints) fprintf(stderr, "Line number: %u: Constraints not satisfied for the variable <%s>, i.e. %s.\n", __LINE__, #variable, #constraints)
#define INITIALISE_CONTAINER_ZERO(container, bytes) memset(container, 0, (bytes))
#define FIND_MAX(a, b) (a) > (b) ? (a) : (b)
#define FIND_MIN(a, b) (a) < (b) ? (a) : (b)
#define FIND_MID(start, end) (((end) - (start)) >> 1) + (start)

static node_t* list_make_node(const int);
static void list_insert_node(node_t*, node_t *const);
static bool list_find_data(node_t *const, const int);
static void delete_list(node_t*);
static int check_happy_number(int);
static int compute_sum_of_digit_square(int);

int main(void) {
    int n;
    scanf("%d", &n);
    if(n < 2) {
        CONSTRAINTS_OUT_OF_BOUND_ERROR(n, 2 <= n <= 2147483647);
        exit(0);
    }
    printf("%d\n", check_happy_number(n));
    return EXIT_SUCCESS;
}

static node_t* list_make_node(const int n) {
    node_t *const new_node = malloc(sizeof *new_node);
    if(new_node) {
        new_node->data = n;
        new_node->next = NULL;
    } else {
        MEMORY_ALLOCATION_FAILED_ERROR(new_node, sizeof *new_node);
        exit(0);
    }
    return new_node;
}

static void list_insert_node(node_t *traverse, node_t *const new_node) {
    for(; traverse->next; traverse = traverse->next);
    traverse->next = new_node;
}

static bool list_find_data(node_t *traverse, const int search_data) {
    bool is_found = false;
    for(; traverse; traverse = traverse->next) {
        if(search_data == (traverse->data)) {
            is_found = true;
            break;
        }
    }
    return is_found;
}

static void delete_list(node_t *traverse) {
    while(traverse) {
        node_t *delete_node = traverse;
        traverse = traverse->next;
        free(delete_node);
    }
}

static int check_happy_number(int n) {
    n = compute_sum_of_digit_square(n);
    node_t *list_head = list_make_node(n);
    int number_of_steps = 1;
    while(1 != n) {
        ++number_of_steps;
        n = compute_sum_of_digit_square(n);
        if(!list_find_data(list_head, n)) {
            list_insert_node(list_head, list_make_node(n));
            continue;
        }
        number_of_steps = -1;
        break;
    }
    delete_list(list_head);
    return number_of_steps;
}

static int compute_sum_of_digit_square(int n) {
    int sum_of_digit_square = 0;
    while(n) {
        sum_of_digit_square += ((n % 10) * (n % 10));
        n /= 10;
    }
    return sum_of_digit_square;
}
