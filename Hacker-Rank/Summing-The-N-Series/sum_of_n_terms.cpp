/*
 * Problem Statement: https://www.hackerrank.com/challenges/summing-the-n-series/problem
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
#include <stack>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <algorithm>
#include <cmath>

typedef unsigned long long ull_t;
typedef long long ll_t;

#define FAST_IO(value) std :: ios :: sync_with_stdio(value); std :: cin.tie(NULL)
#define MOD 1000000007 // Constant (prime number) used in most competitive programming problems to reduce the answer to a 32-bit integer.
#define PI 3.141592653589793 // Number of digits(15) of Pi which JPL uses for Interplanetary Caculations.
#define GOLDEN_RATIO 1.618033988749895 // Number of digits(15).

static ll_t modular_exponentiation(ll_t, ll_t);

int main(void) {
    FAST_IO(0);
    int test;
    std :: cin >> test;
    while(test--) {
        ll_t n;
        std :: cin >> n;
        std :: cout << modular_exponentiation(n, 2LL) << std :: endl;
    }
    return 0;
}

static ll_t modular_exponentiation(ll_t base, ll_t exponent) {
    if(base == 1) {
        return base;
    }
    ll_t result = 1;
    while(exponent) {
        if(exponent & 1) {
            result = (result * base) % MOD;
        }
        exponent >>= 1;
        base = ((base % MOD)* (base % MOD)) % MOD;
    }
    return result;
}
