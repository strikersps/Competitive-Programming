/*
 * Problem Statement: https://practice.geeksforgeeks.org/problems/collection-of-pens/0
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

#define MAX_LIMIT 5001
#define TOTAL_PRIMES_UNDER_MAX_LIMIT 669 // This value is subject to change if you change the MAX_LIMIT.

static void prime_generator(int[]);
static int find_smallest_prime_larger_than_n(int[], const int);

int main(void) {
    int test;
    if(1 != scanf("%d", &test)) {
        SCANF_READ_ERROR(1);
    }
    int prime_list[TOTAL_PRIMES_UNDER_MAX_LIMIT];
    prime_generator(prime_list);
    while(test--) {
        int a, b;
        if(2 != scanf("%d%d", &a, &b)) {
            SCANF_READ_ERROR(2);
        }
        printf("%d\n", find_smallest_prime_larger_than_n(prime_list, a + b) - (a + b));
    }
    return EXIT_SUCCESS;
}

static void prime_generator(int prime_list[]) {
    int prime_sieve[MAX_LIMIT];
    memset(prime_sieve, true, MAX_LIMIT * sizeof(int));
    prime_sieve[0] = prime_sieve[1] = false;
    int prime_count = 0;
    for(register int i = 2, k = 0; i < MAX_LIMIT; ++i) {
        if(prime_sieve[i]) {
            prime_list[k++] = i;
            ++prime_count;
            for(register int j = i * i; j < MAX_LIMIT; prime_sieve[j] = false, j += i);
        }
    }
}

static int find_smallest_prime_larger_than_n(int prime_list[], const int search_data) {
    int found_index = -1;
    for(register int start = 0, end = TOTAL_PRIMES_UNDER_MAX_LIMIT; start <= end; ) {
        const int mid = FIND_MID(start, end);
        if(prime_list[mid] <= search_data) {
            start = mid + 1;
            found_index = start;
            continue;
        }
        end = mid - 1;
    }
    return prime_list[found_index];
}
