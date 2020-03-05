/*
 * Problem Statement: https://www.linkedin.com/posts/gcnit_projecteuler-code-coding-activity-6636246267817226240-5lgK
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
#define SCANF_READ_ERROR(return_val) fprintf(stderr, "Line number: %u: scanf() read error!\nExpected-Return-Value: %d\n", __LINE__, return_val); exit(0)
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

// Solution to the problem starts from below.

#define TOTAL_PRIMES 78498
#define LIMIT 1000001

unsigned int prime_number[TOTAL_PRIMES];

static void generate_primes(void);

int main(void) {
    int test;
    if(1 == scanf("%d", &test)) {
        generate_primes(); // Generate all the primes upto given n i.e. 10^5.
        while(test--) {
            int n;
            if(1 == scanf("%d", &n)) {
                printf("%d\n", prime_number[n - 1]); // After generating the prime, you can calculate the nth prime in O(1) time.
            } else {
                SCANF_READ_ERROR(1);
            }
        }
    } else {
        SCANF_READ_ERROR(1);
    }
    return EXIT_SUCCESS;
}

static void generate_primes(void) {
    bool sieve_table[LIMIT];
    memset(sieve_table, 1, LIMIT * sizeof(bool)); // Initialise every location of sieve_table array to true.
    // Sieve of Eratosthenes algorithm.
    sieve_table[0] = sieve_table[1] = false; // As 0 and 1 are not prime numbers.
    for(register ll_t i = 2, k = 0; i < LIMIT; ++i) {
        if(sieve_table[i]) {
            prime_number[k++] = i;
            for(register ll_t j = i * i; j < LIMIT; j += i) {
                sieve_table[j] = false;
                continue;
            }
        }
    }
}
