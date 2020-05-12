/*
 * Problem Statement: https://codeforces.com/contest/1350/problem/A
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

static ll_t compute_minimum_divisor(ll_t);

int main(void) {
    FAST_IO(0);
    int test;
    std :: cin >> test;
    while(test--) {
        ll_t n, k;
        std :: cin >> n >> k;
        if(k == 1) {
            std :: cout << n + compute_minimum_divisor(n) << std :: endl;
            continue;
        }
        if(!(n % 2)) {
            std :: cout << n + (2 * k) << std :: endl;
            continue;
        }
        int operations = 1;
        ll_t n_copy = n;
        for(; operations <= k; ++operations) {
            n_copy = n_copy + compute_minimum_divisor(n_copy);
            if(!(n_copy % 2)) {
                break;
            }
        }
        std :: cout << n_copy + (2 * (k - operations)) << std :: endl;
    }
    return 0;
}

static ll_t compute_minimum_divisor(ll_t n) {
    if(!(n % 2)) {
        return 2;
    }
    ll_t min_divisor = n;
    for(ll_t i = 3; i <= (n / i); ++i) {
        if(!(n % i)) {
            min_divisor = i;
            break;
        }
    }
    return min_divisor;
}

