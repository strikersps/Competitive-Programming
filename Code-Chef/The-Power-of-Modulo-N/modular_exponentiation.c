/*
 * Problem Statement: https://www.codechef.com/problems/CGPOWN
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
#define INITIALISE_INTEGER_CONTAINER_ZERO(container, bytes) memset(container, 0, (bytes))
#define INITIALISE_CHAR_CONTAINER_ZERO(container, bytes) memset(container, '0', (bytes))
#define FIND_MAX(a, b) (a) > (b) ? (a) : (b)
#define FIND_MIN(a, b) (a) < (b) ? (a) : (b)
#define FIND_MID(start, end) (((end) - (start)) >> 1) + (start)

#define MAX_DIGITS 14
#define MAX_RESULT_LENGTH 27

static ull_t compute_modular_exponentiation(ull_t, ull_t, const ull_t);
static char* naive_multiplication_algorithm(ull_t, ull_t);
static ull_t compute_mod(char[], const ull_t);

int main(void) {
    #ifndef ONLINE_JUDGE
        freopen("test-cases/test-case-1.in", "r", stdin);
        freopen("test-cases/test-case-1.out", "w", stdout);
    #endif
    int test;
    scanf("%d", &test);
    while(test--) {
        ull_t base, exponent, mod;
        scanf("%llu%llu%llu", &base, &exponent, &mod);
        printf("%llu\n", compute_modular_exponentiation(base, exponent, mod));
    }
    return EXIT_SUCCESS;
}

static ull_t compute_modular_exponentiation(ull_t base, ull_t exponent, const ull_t mod) {
    if(1 == mod) {
        return 0;
    }
    ull_t result = 1;
    while(exponent) {
        if(exponent & 1) {
            if(result > 1000000000) {
                char *const mul_result = naive_multiplication_algorithm(result, base);
                result = compute_mod(mul_result, mod);
            } else {
                result = ((result % mod) * base) % mod;
            }
        }
        exponent >>= 1;
        if(base > 1000000000) {
            char *const mul_result = naive_multiplication_algorithm(base, base);
            base = compute_mod(mul_result, mod);
        } else {
            base = (base * base) % mod;
        }
    }
    return result;
}

static char* naive_multiplication_algorithm(ull_t a, ull_t b) {
    char num1[MAX_DIGITS], num2[MAX_DIGITS];
    INITIALISE_CHAR_CONTAINER_ZERO(num1, MAX_DIGITS * sizeof(char));
    num1[MAX_DIGITS - 1] = '\0';
    INITIALISE_CHAR_CONTAINER_ZERO(num2, MAX_DIGITS * sizeof(char));
    num2[MAX_DIGITS - 1] = '\0';
    // Storing the number a and b in reverse order.
    for(int i = 0; a; num1[i++] = (a % 10) + '0', a /= 10);
    for(int i = 0; b; num2[i++] = (b % 10) + '0', b /= 10);
    char *const mul_result = calloc(MAX_RESULT_LENGTH, sizeof *mul_result);
    INITIALISE_CHAR_CONTAINER_ZERO(mul_result, MAX_RESULT_LENGTH * sizeof *mul_result);
    mul_result[MAX_RESULT_LENGTH - 1] = '\0';
    if(mul_result) {
        for(int i = 0; '\0' != num1[i]; ++i) {
            int k = (MAX_RESULT_LENGTH - 2) - i;
            int intermediate_value, intermediate_carry, sum_carry;
            intermediate_carry = sum_carry = 0;
            for(int j = 0; ('\0' != num2[j]) && (k > 0); ++j, --k) {
                intermediate_value = intermediate_carry + (num1[i] - '0') * (num2[j] - '0');
                if(intermediate_value > 9) {
                    intermediate_carry = intermediate_value / 10;
                    intermediate_value %= 10;
                } else {
                    intermediate_carry = 0;
                }
                mul_result[k] = ((mul_result[k] - '0') + intermediate_value + sum_carry) + '0';
                if(mul_result[k] > '9') {
                    sum_carry = (mul_result[k] - '0') / 10;
                    mul_result[k] = ((mul_result[k] - '0') % 10) + '0';
                } else {
                    sum_carry = 0;
                }
            }
            if(sum_carry > 0) {
                mul_result[k] = sum_carry + '0';
            }
        }
    } else {
        MEMORY_ALLOCATION_FAILED_ERROR(mul_result, MAX_RESULT_LENGTH * sizeof *mul_result);
        exit(0);
    }
    return mul_result;
}

static ull_t compute_mod(char number[], const ull_t modulus) {
    if(1 == modulus) {
        return 0;
    }
    ull_t result = 0;
    for(int i = 0; '\0' != number[i]; ++i) {
        result = ((10 * result) + number[i] - '0') % modulus;
    }
    free(number);
    return result;
}
