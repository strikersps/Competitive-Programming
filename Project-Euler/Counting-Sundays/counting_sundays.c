/*
 * Problem Statement: https://www.hackerrank.com/contests/projecteuler/challenges/euler019/problem
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

// The below function macros refers to the GCC functions for doing computation directly on the bit-level of a number.
#define COMPUTE_SET_BITS(number) __builtin_popcountll(number) // Returns the number of set-bits in number (unsigned long long).
#define COMPUTE_PARITY(number) __builtin_parityll(number) // Returns the parity of the number (unsigned long long) i.e. True if 1's are odd else False.
#define COUNT_LEAD_ZEROES(number) __builtin_clzll(number) // Returns the count of lead zeroes before first set-bit from MSB in number (unsigned long long).
#define COUNT_TRAIL_ZEROES(number) __builtin_ctzll(number) // Return the count of trailing zeroes in number(unsigned long long).

typedef struct date {
    unsigned int day, month;
    ull_t year;
} date_t;

enum month_codes {JAN = 13, FEB = 14, MARCH = 3, APR, MAY, JUNE, JULY, AUG, SEPT, OCT, NOV, DEC};
enum day_of_week {Saturday, Sunday, Monday, Tuesday, Wednesday, Thursday, Friday};

static ull_t compute_number_of_sundays(const date_t*, const date_t*);
static unsigned int compute_day_of_week(ull_t, const unsigned int, const unsigned int);

int main(void) {
    /* Hacker-Rank doesn't have an ONLINE_JUDGE macro defined.
    #ifndef ONLINE_JUDGE
        freopen("test-cases/test-case-1.in", "r", stdin);
        freopen("test-cases/test-case-1.out", "w", stdout);
    #endif
    */
    int test;
    scanf("%d", &test);
    while(test--) {
        date_t start_date, end_date;
        scanf("%llu%u%u", &start_date.year, &start_date.month, &start_date.day);
        scanf("%llu%u%u", &end_date.year, &end_date.month, &end_date.day);
        printf("%llu\n", compute_number_of_sundays(&start_date, &end_date));
    }
    return EXIT_SUCCESS;
}

static ull_t compute_number_of_sundays(const date_t *start_date, const date_t *end_date) {
    ull_t count_sundays = 0;
    for(register ull_t year = (start_date->year); year <= (end_date->year); ++year) {
        for(register unsigned int month = (year == (start_date->year)) ? start_date->month : 1; month <= ((year == end_date->year) ? end_date->month : 12); ++month) {
            if(compute_day_of_week(year, month, 1) == Sunday) {
                ++count_sundays;
            }
        }
    }
    if((start_date->day > 1) && (compute_day_of_week(start_date->year, start_date->month, 1) == Sunday)) {
        count_sundays -= 1;
    }
    return count_sundays;
}

// Implementation of the Zeller Congruence Algorithm to find the day of week for arbitrary date.
// Refer to the Wikipedia article on Zeller Congruence: https://en.wikipedia.org/wiki/Zeller%27s_congruence.
static unsigned int compute_day_of_week(ull_t year, const unsigned int month, const unsigned int day) {
    if(month == 1 || month == 2) {
        year -= 1;
    }
    unsigned int year_code = (year % 100);
    unsigned int month_code;
    switch(month) {
        case 1:
            month_code = JAN;
            break;
        case 2:
            month_code = FEB;
            break;
        case 3:
            month_code = MARCH;
            break;
        case 4:
            month_code = APR;
            break;
        case 5:
            month_code = MAY;
            break;
        case 6:
            month_code = JUNE;
            break;
        case 7:
            month_code = JULY;
            break;
        case 8:
            month_code = AUG;
            break;
        case 9:
            month_code = SEPT;
            break;
        case 10:
            month_code = OCT;
            break;
        case 11:
            month_code = NOV;
            break;
        case 12:
            month_code = DEC;
            break;
    }
    ull_t century_code = year / 100;
    unsigned int day_of_month = (day + ((13 * (month_code + 1)) / 5) + year_code + (year_code >> 2) + (century_code >> 2) + (5 * century_code)) % 7;
    return day_of_month;
}
