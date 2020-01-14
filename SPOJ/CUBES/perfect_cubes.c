/*
 * Problem Statement: https://www.spoj.com/problems/CUBES/
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
#define INITIALISE_CONTAINER_ZERO(container, bytes) memset(container, 0, (bytes))
#define FIND_MAX(a, b) (a) > (b) ? (a) : (b)
#define FIND_MIN(a, b) (a) < (b) ? (a) : (b)
#define FIND_MID(start, end) (((end) - (start)) >> 1) + (start)

#define LIMIT 100

int main(void) {
    bool freq_number[LIMIT];
    for(int a = 2; a <= LIMIT; ++a) {
        INITIALISE_CONTAINER_ZERO(freq_number, LIMIT * sizeof(bool));
        for(int b = 2; b < a; ++b) {
            int a_b = (a * a * a) - (b * b * b);
            int start = 1, end = LIMIT - 1;
            while(start < end) {
                if(a_b == ((start + 1) * (start + 1) * (start + 1)) + ((end + 1) * (end + 1) * (end + 1))) {
                    if(!freq_number[b - 1] || !freq_number[start] || !freq_number[end]) {
                        freq_number[b - 1] = freq_number[start] = freq_number[end] = true;
                        printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, start + 1, end + 1);
                    }
                    break;
                } else if(a_b > (((start + 1) * (start + 1) * (start + 1)) + ((end + 1) * (end + 1) * (end + 1)))) {
                    ++start;
                } else {
                    --end;
                }
            }
        }
    }
    return EXIT_SUCCESS;
}
