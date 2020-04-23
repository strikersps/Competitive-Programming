/*
 * Problem Statement: https://www.codechef.com/JAN20B/problems/BRKBKS/
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
#include <cassert>

typedef unsigned long long ull_t;
typedef long long ll_t;

#define FAST_IO(value) std :: ios :: sync_with_stdio(value); std :: cin.tie(NULL)
#define MOD 1000000007 // Constant (prime number) used in most competitive programming problems to reduce the answer to a 32-bit integer.
#define PI 3.141592653589793 // Number of digits(15) of Pi which JPL uses for Interplanetary Caculations.
#define GOLDEN_RATIO 1.618033988749895 // Number of digits(15).

// C and C++ % operator is not a modular arithmethic operator rather its a remainder operator which gives remainder when a / b;
// Refer: https://stackoverflow.com/questions/11720656/modulo-operation-with-negative-numbers
ll_t compute_mod(ll_t a, ll_t b) {
    assert(b != 0); // Modulus is not defined when denominator is zero.
    ll_t rem = a % b;
    return rem < 0 ? b + rem : rem;
}

static int compute_minimum_hits(const int, const std :: array <int, 3> &);

int main(void) {
    FAST_IO(0);
    int test;
    std :: cin >> test;
    while(test--) {
        int ada_strength;
        std :: cin >> ada_strength;
        std :: array <int, 3> brick_wt;
        for(int i = 0; i < 3; ++i) {
            std :: cin >> brick_wt[i];
        }
        std :: cout << compute_minimum_hits(ada_strength, brick_wt) << std :: endl;
    }
    return 0;
}

static int compute_minimum_hits(const int ada_strength, const std :: array <int, 3> & brick_wt) {
    if(ada_strength >= brick_wt[0] + brick_wt[1] + brick_wt[2]) {
        return 1;
    }
    if((ada_strength >= brick_wt[0] + brick_wt[1]) || (ada_strength >= brick_wt[1] + brick_wt[2])) {
        return 2;
    }
    return 3;
}
