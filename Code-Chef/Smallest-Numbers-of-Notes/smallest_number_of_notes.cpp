/*
 * Problem Statement: https://www.codechef.com/problems/FLOW005
 * Author: striker
 *
 * Copyright 2020 striker
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version TWO of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
*/

#include <iostream>
#include <cmath>

typedef unsigned long long ull_t;
typedef long long ll_t;

#define FAST_IO(value) std :: ios :: sync_with_stdio(value); std :: cin.tie(value)
#define MOD 10000000007 // Constant (prime number) used in most competitive programming problems to reduce the answer to a 32-bit integer.
#define PI 3.141592653589793 // Number of digits(15) of Pi which JPL uses for Interplanetary Caculations.
#define GOLDEN_RATIO 1.618033988749895 // Number of digits(15).

enum denominations {HUNDRED = 100, FIFTY = 50, TEN = 10, FIVE = 5, TWO = 2, ONE = 1};

static int compute_smallest_number_of_notes(int);

int main(void) {
    FAST_IO(0);
    int test;
    std :: cin >> test;
    while(test--) {
        int n;
        std :: cin >> n;
        std :: cout << compute_smallest_number_of_notes(n) << std :: endl;
    }
    return 0;
}

static int compute_smallest_number_of_notes(int n) {
    int total_notes = 0;
    while(n) {
        if(n >= HUNDRED) {
            total_notes += (n / HUNDRED);
            n %= HUNDRED;
        } else if(n >= FIFTY) {
            total_notes += (n / FIFTY);
            n %= FIFTY;
        } else if(n >= TEN) {
            total_notes += (n / TEN);
            n %= TEN;
        } else if(n >= FIVE) {
            total_notes += (n / FIVE);
            n %= FIVE;
        } else if(n >= TWO) {
            total_notes += (n >> 1);
            n %= TWO;
        } else {
            total_notes += n;
            n = 0;
        }
    }
    return total_notes;
}
