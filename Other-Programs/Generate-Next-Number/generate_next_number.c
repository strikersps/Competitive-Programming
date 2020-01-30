/*
 * Problem Statement: Refer to the readme.md file.
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

#define MAX_LIMIT 101

static void next_permutation(char[]);
static void swap_data(char *const, char *const);

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
        char number[MAX_LIMIT];
        scanf("%s", number);
        next_permutation(number);
        puts(number);
    }
    return EXIT_SUCCESS;
}

/*
 * Algorithm Explanation:
 * Step-1: First find out the largest index such that, number[index] < number[index + 1].
 * Step-2: If the index == 0, then the given number is already the largest number you can build, else if index > 0, then there is an existence of next largest number for the given number.
 * Step-3: Let's denote the found index in the Step-1 as 'start', if start > 0 then find the largest index such that, number[index] > number[start].
 * Step-4: Let's denote the found index in Step-3 as 'end', now swap the numbers which are present at number[start] and number[end].
 * Step-5: Sort the number from start to last-digit in increasing order. As I am representing the number in the form of a string, sort the string from start to last location of the string.
 * Step-6: For Step-5, you don't need to use any sorting algorithm, if you observe carefully, the string[start: last_element] is in decreasing order, so you just need to reverse the string to sort it in increasing order.
 * That's it, the resultant string which you will get after executing the above steps, will be the next-largest string you can build with the digits of N.
 * Refer to the function static void next_permutation(char number[]) for source-code, and try to run on a simple to understand how the code is working, then you would have better clarity over the algorithm explained in the above steps.
*/

static void next_permutation(char number[]) {
    int start, end, number_len = strlen(number);
    for(start = number_len - 1; start > 0 && number[start - 1] > number[start]; --start);
    if(start) {
        for(end = number_len - 1; end > 0 && number[end] < number[start - 1]; --end);
        swap_data(&number[start - 1], &number[end]);
        for(end = number_len - 1; start < end; ++start, --end) {
            swap_data(&number[start], &number[end]);
        }
    }
}

static void swap_data(char *const a, char *const b) {
    if(!(a == b)) {
        *a = (*a) ^ (*b);
        *b = (*a) ^ (*b);
        *a = (*a) ^ (*b);
    }
}
