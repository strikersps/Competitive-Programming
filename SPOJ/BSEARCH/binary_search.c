/*
 * Problem Statement: https://www.spoj.com/problems/BSEARCH1/
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
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
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

static int binary_search(const int *const, int, int, const int);

int main(void) {
    // This code-fragment is defined only for Online Judges where ONLINE_JUDGE macro is defined.
    #ifndef  ONLINE_JUDGE
        freopen("test-cases/test-case-1.in", "r", stdin);
        // freopen("test-cases/test-case-1.out", "w", stdout);
    #endif
    int n, queries;
    scanf("%d%d", &n, &queries);
    int data[n];
    for(int i = 0; i < n; ++i) {
        scanf("%d", &data[i]);
    }
    while(queries--) {
        int find_value, found_index;
        scanf("%d", &find_value);
        printf("%d\n", (-1 == (found_index = binary_search(data, 0, n - 1, find_value)) ? -1 : found_index));
    }
    return EXIT_SUCCESS;
}

static int binary_search(const int *const data, int start, int end, const int search_value) {
    int first_occurence_index = -1;
    while(start <= end) {
        const int mid = FIND_MID(start, end);
        if(search_value == data[mid]) {
            first_occurence_index = mid;
            end = mid - 1;
        } else if(search_value < data[mid]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return first_occurence_index;
}
