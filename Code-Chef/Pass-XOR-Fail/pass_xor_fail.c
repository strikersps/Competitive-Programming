/*
 * Problem Statement: https://www.codechef.com/HOCO2020/problems/HCODE01
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
#define FIND_MAX(a, b) (a) > (b) ? (a) : (b) // Use this macro when you want to find maximum out of two data rather than return value of function.
#define FIND_MIN(a, b) (a) < (b) ? (a) : (b) // Use this macro when you want to find minimum out of two data rather than return value of function.
#define FIND_MID(start, end) (((end) - (start)) >> 1) + (start)

#define MAX_NUMBER_OF_DIGITS 1000001

static void compute_addition_large(char[], char[]);

int main(void) {
    #ifndef ONLINE_JUDGE
        freopen("test-cases/test-case-1.in", "r", stdin);
        freopen("test-cases/test-case-1.out", "w", stdout);
    #endif
    char number_base_10[MAX_NUMBER_OF_DIGITS];
    scanf("%s", number_base_10);
    unsigned int number_of_digits = strlen(number_base_10);
    if(number_of_digits < 19) {
        ull_t number = strtoull(number_base_10, NULL, 10);
        if(!number || number % 4 == 3) {
            printf("0\n");
        } else if(number % 4 == 1) {
            printf("1\n");
        } else if(number % 4 == 2) {
            printf("%llu\n", number + 1);
        } else {
            printf("%llu\n", number);
        }
    } else {
        ull_t remainder = atoi(number_base_10 + (number_of_digits - 2)) % 4;
        if(!remainder) {
            puts(number_base_10);
        } else if(remainder == 1) {
            printf("1\n");
        } else if(remainder == 2) {
            compute_addition_large(number_base_10, "1");
            puts(number_base_10);
        } else {
            printf("0\n");
        }
    }
    return EXIT_SUCCESS;
}

static void compute_addition_large(char a[], char b[]) {
    unsigned int lsb = strlen(a) - 1;
    int digit_sum = (a[lsb] - '0') + (b[0] - '0');
    a[lsb] = (digit_sum % 10) + '0';
    if(digit_sum > 9) {
        int carry = digit_sum / 10;
        for(register int i = lsb - 1; i >= 0; --i) {
            digit_sum = carry + (a[i] - '0');
            a[i] = (digit_sum % 10) + '0';
            if(digit_sum > 9) {
                carry = digit_sum / 10;
                continue;
            }
            carry = 0;
            break;
        }
    }
}
