/*
 * Problem Statement: https://www.codechef.com/problems/RECNDNOS
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
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cassert>

typedef unsigned long long ull_t;
typedef long long ll_t;

#define FAST_IO(value) std :: ios :: sync_with_stdio(value); std :: cin.tie(NULL)
#define MOD 1000000007 // Constant (prime number) used in most competitive programming problems to reduce the answer to a 32-bit integer.
#define PI 3.141592653589793 // Number of digits(15) of Pi which JPL uses for Interplanetary Caculations.
#define GOLDEN_RATIO 1.618033988749895 // Number of digits(15).

#define COMPUTE_GCD(a, b) std :: __gcd((a), (b))
#define COMPUTE_LCM(a, b) (a * ((b) / COMPUTE_GCD(a, b)))

// C and C++ % operator is not a modular arithmethic operator rather its a remainder operator which gives remainder when a / b;
// Refer: https://stackoverflow.com/questions/11720656/modulo-operation-with-negative-numbers
ll_t compute_mod(ll_t a, ll_t b) {
    assert(b != 0); // Modulus is not defined when denominator is zero.
    ll_t rem = a % b;
    return rem < 0 ? b + rem : rem;
}

static int compute_dish_type(const std :: vector <int> &, const int);

int main(void) {
    FAST_IO(0);
    int test;
    std :: cin >> test;
    while(test--) {
        int n;
        std :: cin >> n;
        std :: vector <int> dish_type(n);
        for(int & type: dish_type) {
            std :: cin >> type;
        }
        std :: cout << compute_dish_type(dish_type, n) << std :: endl;
    }
    return 0;
}

static int compute_dish_type(const std :: vector <int> & sequence, const int n) {
    int max_dish_type = *std :: max_element(sequence.begin(), sequence.end());
    std :: map <int, int> dish_type_frequency;
    for(int dish_type = 1; dish_type <= max_dish_type; ++dish_type) {
        int dish_type_count = 0;
        for(int i = 0; i < n; ++i) {
            if(sequence[i] == dish_type) {
                ++dish_type_count;
                if(i < (n - 1) && sequence[i] == sequence[i + 1]) {
                    ++i;
                }
            }
        }
        dish_type_frequency[dish_type] = dish_type_count;
    }
    int dish_type, max_value = 0;
    for(const std :: pair <int, int> mapping: dish_type_frequency) {
        if(mapping.second > max_value) {
            max_value = mapping.second;
            dish_type = mapping.first;
        }
    }
    return dish_type;
}
