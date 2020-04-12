/*
 * Problem Statement: https://www.codechef.com/problems/SWPDGT
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
#include <array>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <cstdio>

typedef unsigned long long ull_t;
typedef long long ll_t;

#define FAST_IO(value) std :: ios :: sync_with_stdio(value); std :: cin.tie(NULL)
#define MOD 1000000007 // Constant (prime number) used in most competitive programming problems to reduce the answer to a 32-bit integer.
#define PI 3.141592653589793 // Number of digits(15) of Pi which JPL uses for Interplanetary Caculations.
#define GOLDEN_RATIO 1.618033988749895 // Number of digits(15).

int main(void) {
    FAST_IO(0);
    int test;
    std :: cin >> test;
    while(test--) {
        int a, b;
        std :: cin >> a >> b;
        if(a < 10 && b < 10) {
            std :: cout << a + b << std :: endl;
            continue;
        }
        int a_ones_place = a % 10;
        int a_tens_place = a / 10;
        int b_ones_place = b % 10;
        int b_tens_place = b / 10;
        int max_1, max_2, max_3;
        max_1 = a + b;
        if(a < 10 && b >= 10) {
            max_2 = 0;
            max_3 = 10 * (a_ones_place + a_tens_place) + b_ones_place + b_tens_place;
        } else if(a >= 10 && b < 10) {
            max_2 = 10 * (b_ones_place + b_tens_place) + a_ones_place + a_tens_place;
            max_3 = 0;
        } else {
            max_2 = 10 * (b_ones_place + b_tens_place) + a_ones_place + a_tens_place;
            max_3 = 10 * (a_ones_place + a_tens_place) + b_ones_place + b_tens_place;
        }
        std :: cout << std :: max(std :: max(max_1, max_2), max_3) << std :: endl;
    }
    return 0;
}
