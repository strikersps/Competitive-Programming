/*
 * Problem Statement: https://www.codechef.com/LRNDSA05/problems/HMAPPY2
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

// C and C++ % operator is not a modular arithmethic operator rather its a remainder operator which gives remainder when a / b;
// Refer: https://stackoverflow.com/questions/11720656/modulo-operation-with-negative-numbers
ll_t compute_mod(ll_t a, ll_t b) {
    assert(b != 0); // Modulus is not defined when denominator is zero.
    ll_t rem = a % b;
    return rem < 0 ? b + rem : rem;
}

static int compute_gcd(const int a, const int b) {
    if(a == 0) {
        return b;
    }
    if(b == 0) {
        return a;
    }
    return compute_gcd(b, a % b);
}

int main(void) {
    FAST_IO(0);
    int test;
    std :: cin >> test;
    while(test--) {
        ll_t n, a, b, k;
        std :: cin >> n >> a >> b >> k;
        ll_t divisors_of_a = n / a;
        ll_t divisors_of_b = n / b;
        ll_t divisors_of_a_b = n / ((a * b) / compute_gcd(a, b));
        ll_t tot_problem_solved = (divisors_of_a - divisors_of_a_b) + (divisors_of_b - divisors_of_a_b);
        std :: cout << (tot_problem_solved >= k ? "Win" : "Lose") << std :: endl;
    }
    return 0;
}
