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
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

typedef unsigned long long ull_t;
typedef long long ll_t;

#define FAST_IO(value) std :: ios :: sync_with_stdio(value); std :: cin.tie(value)
#define MOD 10000000007 // Constant (prime number) used in most competitive programming problems to reduce the answer to a 32-bit integer.
#define PI 3.141592653589793 // Number of digits(15) of Pi which JPL uses for Interplanetary Caculations.
#define GOLDEN_RATIO 1.618033988749895 // Number of digits(15).

static int compute_sum_of_square_of_digit(int);
static bool check_happy_number(int);

int main(void) {
    FAST_IO(0);
    int test;
    std :: cin >> test;
    while(test--) {
        int n;
        std :: cin >> n;
        std :: cout << (check_happy_number(n) ? "YES" : "NO") << std :: endl;
    }
    return 0;
}

static int compute_sum_of_square_of_digit(int n) {
    int digit_square_sum = 0;
    while(n) {
        int last_digit = n % 10;
        digit_square_sum += (last_digit * last_digit);
        n /= 10;
    }
    return digit_square_sum;
}

static bool check_happy_number(int n) {
    bool is_happy = true;
    std :: set <int> visited_number;
    visited_number.insert(n);
    while(true) {
        n = compute_sum_of_square_of_digit(n);
        if(n == 1) {
            break;
        }
        if(visited_number.count(n)) {
            is_happy = false;
            break;
        }
        visited_number.insert(n);
    }
    return is_happy;
}
