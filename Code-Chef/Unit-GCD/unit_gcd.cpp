/*
 * Problem Statement: https://www.codechef.com/APRIL20B/problems/UNITGCD
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

static void compute_minimum_days(const int);

int main(void) {
    FAST_IO(0);
    int test;
    std :: cin >> test;
    while(test--) {
        int n;
        std :: cin >> n;
        compute_minimum_days(n);
    }
    return 0;
}

static void compute_minimum_days(const int n) {
    int min_days = (n == 1) ? 1 : n >> 1;
    std :: cout << min_days << '\n';
    if(n < 4) {
        std :: cout << n << " ";
        printf("%d ", n);
        for(register int i = 1; i <= n; ++i) {
            std :: cout << i << " ";
        }
        std :: cout << '\n';
    } else {
        for(register int i = 1, j = 1; i <= min_days; ++i, j += 2) {
            if(i < min_days) {
                std :: cout << 2 << " " << j << " " << j + 1 << '\n';
                continue;
            }
            if(n % 2) {
                std :: cout << 3 << " " << j << " " << j + 1 << " " << j + 2 << '\n';
            } else {
                std :: cout << 2 << " " << j << " " << j + 1 << '\n';
            }
        }
    }
}
