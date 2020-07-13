/*
 * Problem Statement: https://www.codechef.com/JULY20B/problems/CHFNSWPS
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
#include <iomanip>
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

/*START OF CODE-TEMPLATE*/

typedef unsigned long long ull_t;
typedef long long ll_t;

#define FAST_IO(value) std :: ios :: sync_with_stdio(value); std :: cin.tie(NULL); std :: cout.tie(NULL)

#define MOD 1000000007 // Constant (prime number) used in most competitive programming problems to reduce the answer to a 32-bit integer.
#define PI 3.141592653589793 // Number of digits(15) of Pi which JPL uses for Interplanetary Caculations.
#define GOLDEN_RATIO 1.618033988749895 // Number of digits(15).
#define INF_32_BIT_US_INT 0xFFFFFFFF // Maximum value which can be stored in an unsigned int (32-Bit).
#define INF_64_BIT_US_INT 0xFFFFFFFFFFFFFFFF // Maximum value which can be stored in an unsigned long long (64-Bit).
#define NEW_LINE '\n' // Created because sometimes std :: endl makes the code slower due to clearance of buffer after printing new-line.

#define COMPUTE_GCD(a, b) std :: __gcd((a), (b))
#define COMPUTE_LCM(a, b) (a * ((b) / COMPUTE_GCD(a, b)))

// C and C++ "%" operator is not a modular arithmetic operator rather it's a remainder operator which gives remainder when a / b.
// Implementation is based on the fact that a % b = a - (b * (a / b)), where a = dividend, b = divisor, a / b = quotient.
// Refer: https://stackoverflow.com/questions/11720656/modulo-operation-with-negative-numbers
// Time Complexity: O(1).
ll_t compute_mod(ll_t a, ll_t b) {
    assert(b > 0); // Denominator must be positive.
    ll_t rem = a % b;
    return rem < 0 ? b + rem : rem;
}

// The function computes the total number of divisors for the given n. i.e. d(n).
// Time-Complexity: O(sqrt(n)).
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

// The code computes whether the given number (n) is a perfect square or not based on the fact that, a number is a perfect square if it has odd number of divisors.
// Refer: https://math.stackexchange.com/questions/906159/a-number-is-a-perfect-square-if-and-only-if-it-has-odd-number-of-positive-diviso
// Time-Complexity: O(sqrt(n)).
bool check_perfect_sequare(ll_t n) {
    return compute_total_divisors(n) % 2 ? true : false;
}

// Computes the number of set-bits in the binary representation of n (64-Bit).
#define COMPUTE_SET_BITS(number) __builtin_popcountll(number)

// Computes the parity of the number n (64-Bit) i.e. parity is 0 if the number of set-bits is even otherwise odd.
#define COMPUTE_PARITY(number) __builtin_parity(number)

// Computes the number of leading zeroes in the binary representation of n (64-Bit). The value will be 64 - (number of bits required to represent n).
#define COMPUTE_LEADING_ZEROES(number) __builtin_clzll(number)

// Computes the number of trailing zeroes in the binary representation of n (64-Bit). The value will always be zero if n is odd.
#define COMPUTE_TRAILING_ZEROES(number) __builtin_ctzll(number)

/*END-OF CODE-TEMPLATE*/

static ll_t compute_minimum_total_cost(const std :: vector <ll_t> &, const std :: vector <ll_t> &, const std :: map <ll_t, ll_t> &, const ll_t);

int main(void) {
    FAST_IO(0);
    int test;
    std :: cin >> test;
    while(test--) {
        int n;
        ll_t min_val_a_b = std :: numeric_limits <ll_t> :: max();
        std :: cin >> n;
        std :: vector <ll_t> sequence_a(n), sequence_b(n);
        std :: map <ll_t, ll_t> freq_map_a_b;
        for(ll_t & number: sequence_a) {
            std :: cin >> number;
            min_val_a_b = std :: min(min_val_a_b, number);
            ++freq_map_a_b[number];
        }
        for(ll_t & number: sequence_b) {
            std :: cin >> number;
            min_val_a_b = std :: min(min_val_a_b, number);
            ++freq_map_a_b[number];
        }
        std :: cout << compute_minimum_total_cost(sequence_a, sequence_b, freq_map_a_b, min_val_a_b) << NEW_LINE;
    }
    return 0;
}

static ll_t compute_minimum_total_cost(const std :: vector <ll_t> & sequence_a, const std :: vector <ll_t> & sequence_b, const std :: map <ll_t, ll_t> & freq_map_a_b, const ll_t min_val_a_b) {
    std :: map <ll_t, ll_t> map_a, map_b;
    bool is_possible = true;
    for(auto & mapping: freq_map_a_b) {
        if(mapping.second % 2LL) {
            is_possible = false;
            break;
        }
        map_a[mapping.first] = mapping.second >> 1LL;
    }
    if(!is_possible) {
        return -1;
    }
    map_b = map_a;
    std :: vector <ll_t> a_to_b, b_to_a;
    for(int i = 0; i < (int) sequence_a.size(); ++i) {
        if(map_a[sequence_a[i]]) {
            --map_a[sequence_a[i]];
            continue;
        }
        a_to_b.push_back(sequence_a[i]);
    }
    for(int i = 0; i < (int) sequence_b.size(); ++i) {
        if(map_b[sequence_b[i]]) {
            --map_b[sequence_b[i]];
            continue;
        }
        b_to_a.push_back(sequence_b[i]);
    }
    std :: sort(a_to_b.begin(), a_to_b.end());
    std :: sort(b_to_a.rbegin(), b_to_a.rend());
    ll_t len = a_to_b.size();
    if(!len) {
        return 0;
    }
    ll_t sum = 0LL;
    for(ll_t i = 0; i < len; ++i) {
        sum += std :: min(min_val_a_b << 1LL, std :: min(a_to_b[i], b_to_a[i]));
    }
    return sum;
}
