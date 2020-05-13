/*
 * Problem Statement: https://cses.fi/problemset/task/1071
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

#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

typedef unsigned long long ull_t;
typedef long long ll_t;

#define FAST_IO(value) std :: ios :: sync_with_stdio(value); std :: cin.tie(NULL)

#define MOD 1000000007 // Constant (prime number) used in most competitive programming problems to reduce the answer to a 32-bit integer.
#define PI 3.141592653589793 // Number of digits(15) of Pi which JPL uses for Interplanetary Caculations.
#define GOLDEN_RATIO 1.618033988749895 // Number of digits(15).
#define INF_32_BIT_US 0xFFFFFFFF // Maximum value which can be stored in an unsigned int (32-Bit).
#define INF_64_BIT_US 0xFFFFFFFFFFFFFFFF // Maximum value which can be stored in an unsigned long long (64-Bit).

#define COMPUTE_GCD(a, b) std :: __gcd((a), (b))
#define COMPUTE_LCM(a, b) (a * ((b) / COMPUTE_GCD(a, b)))

// C and C++ % operator is not a modular arithmetic operator rather it's a remainder operator which gives remainder when a / b;
// Refer: https://stackoverflow.com/questions/11720656/modulo-operation-with-negative-numbers
ll_t compute_mod(ll_t a, ll_t b) {
    assert(b > 0); // Denominator must be positive.
    ll_t rem = a % b;
    return rem < 0 ? b + rem : rem;
}

ll_t compute_total_divisors(ll_t n) {
    ll_t total_divisors = 0;
    for(ll_t i = 1; i <= (n / i); ++i) {
        if(!(n % i)) {
            if((n / i) == i) {
                ++total_divisors;
                continue;
            }
            total_divisors += 2;
        }
    }
    return total_divisors;
}

// Refer: https://math.stackexchange.com/questions/906159/a-number-is-a-perfect-square-if-and-only-if-it-has-odd-number-of-positive-diviso
bool check_perfect_sequare(ll_t n) {
    return compute_total_divisors(n) % 2 ? true : false;
}

static ll_t find_value_in_grid(const std :: pair <int, int> &);

int main(void) {
    FAST_IO(0);
    int test;
    std :: cin >> test;
    while(test--) {
        std :: pair <int, int> grid_loc;
        std :: cin >> grid_loc.first >> grid_loc.second;
        std :: cout << find_value_in_grid(grid_loc) << std :: endl;
    }
    return 0;
}

static ll_t find_value_in_grid(const std :: pair <int, int> & grid_loc) {
    ll_t diagonal_index = std :: max(grid_loc.first, grid_loc.second);
    ll_t diagonal_element = 1LL + (diagonal_index * (diagonal_index - 1));
    if(diagonal_index % 2) {
        if(grid_loc.first > grid_loc.second) {
            return diagonal_element - (grid_loc.first - grid_loc.second);
        }
        return diagonal_element + (grid_loc.second - grid_loc.first);
    }
    if(grid_loc.first > grid_loc.second) {
        return diagonal_element + (grid_loc.first - grid_loc.second);
    }
    return diagonal_element - (grid_loc.second - grid_loc.first);
}


