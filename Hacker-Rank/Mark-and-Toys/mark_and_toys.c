/*
 * Problem Statement: https://www.hackerrank.com/challenges/mark-and-toys/problem
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

int comparator_callback(const void*, const void*);
static ll_t compute_max_toys(ll_t [], const ll_t, const ll_t);

int main(void) {
    /* Hacker-Rank doesn't have ONLINE_JUDGE macro defined.
    #ifndef ONLINE_JUDGE
        freopen("test-cases/test-case-1.in", "r", stdin);
        freopen("test-cases/test-case-1.out", "w", stdout);
    #endif
    */
    ll_t total_toys, mark_budget;
    scanf("%lld%lld", &total_toys, &mark_budget);
    ll_t toy_price[total_toys];
    for(int i = 0; i < total_toys; ++i) {
        scanf("%lld", toy_price + i);
    }
    qsort(toy_price, total_toys, sizeof(ll_t), comparator_callback);
    printf("%lld\n", compute_max_toys(toy_price, total_toys, mark_budget));
    return EXIT_SUCCESS;
}

int comparator_callback(const void *a, const void *b) {
    return (*(ll_t *) a) > (*(ll_t *) b);
}

static ll_t compute_max_toys(ll_t price[], const ll_t total_toys, const ll_t mark_budget) {
    ll_t money_spent, max_toys;
    money_spent = max_toys = 0;
    for(int i = 0; i < total_toys; ++i) {
        money_spent += price[i];
        if(money_spent <= mark_budget) {
            ++max_toys;
            continue;
        }
        break;
    }
    return max_toys;
}
