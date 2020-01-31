/*
 * Problem Statement: https://www.hackerrank.com/challenges/strong-password/problem
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
#include <ctype.h>
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

#define TOTAL_STRONG_PASSWORD_CONDITIONS 4

static int check_strong_password(char[]);

int main(void) {
    #ifndef ONLINE_JUDGE
        // freopen("test-cases/test-case-1.in", "r", stdin);
        // freopen("test-cases/test-case-1.out", "w", stdout);
    #endif
    int n;
    scanf("%d", &n);
    if(n < 1) {
        CONSTRAINTS_OUT_OF_BOUND_ERROR(n, string length cannot be 0 or -ve);
        exit(0);
    }
    char user_password[n];
    scanf("%s", user_password);
    printf("%d\n", check_strong_password(user_password));
    return EXIT_SUCCESS;
}

static int check_strong_password(char user_password[]) {
    unsigned int password_len = strlen(user_password);
    // printf("password-len: %d\n", password_len);
    bool existence[TOTAL_STRONG_PASSWORD_CONDITIONS];
    INITIALISE_INT_CONTAINER_ZERO(existence, TOTAL_STRONG_PASSWORD_CONDITIONS * sizeof(bool));
    const char *const special_characters = "!@#$%^&*()-+";
    for(int i = 0; '\0' != user_password[i]; ++i) {
        if(!existence[0] && isdigit(user_password[i])) {
            existence[0] = true;
            continue;
        }
        if(!existence[1] && isupper(user_password[i])) {
            existence[1] = true;
            continue;
        }
        if(!existence[2] && islower(user_password[i])) {
            existence[2] = true;
            continue;
        }
        if(!existence[3]) {
            for(int j = 0; '\0' != special_characters[j]; ++j) {
                if(user_password[i] == special_characters[j]) {
                    existence[3] = true;
                    break;
                }
            }
        }
    }
    int min_char_add = 0;
    for(int i = 0; i < TOTAL_STRONG_PASSWORD_CONDITIONS; ++i) {
        if(!existence[i]) {
            ++min_char_add;
        }
    }
    if((password_len + min_char_add) < 6) {
        min_char_add += (6 - (password_len + min_char_add));
    }
    return min_char_add;
}
