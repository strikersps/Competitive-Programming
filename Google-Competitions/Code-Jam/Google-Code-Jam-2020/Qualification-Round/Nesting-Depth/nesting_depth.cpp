/*
 * Problem Statement: https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/0000000000209a9f
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

static std :: string construct_required_string(const std :: string &);

int main(void) {
    FAST_IO(0);
    int test;
    std :: cin >> test;
    for(int t = 1; t <= test; ++t) {
        std :: string digit_string;
        std :: cin >> digit_string;
        std :: cout << "Case #" << t << ": " << construct_required_string(digit_string) << std :: endl;
    }
    return 0;
}

static std :: string construct_required_string(const std :: string & digit_string) {
    std :: string required_string;
    int depth = 0;
    for(const char & digit: digit_string) {
        if((digit - '0') == depth) {
            required_string += digit;
            continue;
        }
        if(digit - '0' > depth) {
            int bracket_count = (digit - '0') - depth;
            for(int i = 0; i < bracket_count; ++i, ++depth) {
                required_string += '(';
            }
        } else {
            int bracket_count = depth - (digit - '0');
            for(int i = 0; i < bracket_count; ++i, --depth) {
                required_string += ')';
            }
        }
        required_string += digit;
    }
    for(int i = 0; i < depth; ++i) {
        required_string += ')';
    }
    return required_string;
}
