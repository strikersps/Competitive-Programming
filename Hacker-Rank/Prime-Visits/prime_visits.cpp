/*
 * Problem Statement: https://www.hackerrank.com/contests/launchpad-1-winter-challenge/challenges/prime-visits
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

#define MAX_LIMIT 1000000

static void prime_generator(std :: vector <int> &);

int main(void) {
    FAST_IO(0);
    int test;
    std :: cin >> test;
    std :: vector <int> prime_sequence; // Store all the primes upto MAX_LIMIT.
    prime_generator(prime_sequence);
    while(test--) {
        int a, b;
        std :: cin >> a >> b;
        std :: vector <int> :: iterator itr1 = std :: lower_bound(prime_sequence.begin(), prime_sequence.end(), a);
        std :: vector <int> :: iterator itr2 = std :: lower_bound(prime_sequence.begin(), prime_sequence.end(), b);
        if((*itr1 == a && *itr2 == b) || (*itr1 != a && *itr2 == b)) {
            std :: cout << 1 + (itr2 - itr1) << std :: endl;
            continue;
        }
        std :: cout << itr2 - itr1 << std :: endl;
    }
    return 0;
}

static void prime_generator(std :: vector <int> & prime_sequence) {
    bool is_prime[MAX_LIMIT];
    memset(is_prime, true, MAX_LIMIT * sizeof(bool));
    is_prime[0] = is_prime[1] = false;
    for(ll_t i = 2; i < MAX_LIMIT; ++i) {
        if(is_prime[i]) {
            prime_sequence.push_back(i);
            for(ll_t j = i * i; j < MAX_LIMIT; is_prime[j] = false, j += i);
        }
    }
}
