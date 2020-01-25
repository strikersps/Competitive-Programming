/*
 * Problem Statement: https://www.codechef.com/LTIME80B/problems/BFRIEND
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

int comparator_callback(const void*, const void*);
static unsigned int compute_total_time(const int, const int, const int, const int);
static int find_closest_floor(const int *const, int, int, const int, const int);

int main(void) {
    #ifndef ONLINE_JUDGE
        freopen("test-cases/test-case-1.in", "r", stdin);
        freopen("test-cases/test-case-1.out", "w", stdout);
    #endif
    int test;
    scanf("%d", &test);
    if(test < 1) {
        CONSTRAINTS_OUT_OF_BOUND_ERROR(test, test value cannot be 0 or -ve);
        exit(0);
    }
    while(test--) {
        int total_floors, alice_floor, bob_floor, time_to_change;
        scanf("%d%d%d%d", &total_floors, &alice_floor, &bob_floor, &time_to_change);
        int friend_floor[total_floors];
        for(int i = 0; i < total_floors; ++i) {
            scanf("%d", &friend_floor[i]);
        }
        int closest_floor = 0;
        if(total_floors > 1) {
            qsort(friend_floor, total_floors, sizeof(int), comparator_callback);
            closest_floor = find_closest_floor(friend_floor, 0, total_floors - 1, bob_floor, alice_floor);
        }
        printf("%u\n", compute_total_time(friend_floor[closest_floor], bob_floor, time_to_change, alice_floor));
    }
    return EXIT_SUCCESS;
}

int comparator_callback(const void *a, const void *b) {
    return (*(int*) a) > (*(int*) b);
}

static unsigned int compute_total_time(const int friend_floor, const int bob_floor, const int time_to_change, const int alice_floor) {
    return abs(friend_floor - bob_floor) + time_to_change + abs(friend_floor - alice_floor);
}

static int find_closest_floor(const int *const friend_floor, int start, int end, const int bob_floor, const int alice_floor) {
    while(start <= end) {
        const int mid = FIND_MID(start, end);
        if(alice_floor < friend_floor[mid]) {
            end = mid - 1;
            continue;
        }
        start = mid + 1;
    }
    if(end != -1) {
        if(abs(friend_floor[start] - bob_floor) < abs(friend_floor[end] - bob_floor)) {
            return start;
        }
        return end;
    }
    return start;
}
