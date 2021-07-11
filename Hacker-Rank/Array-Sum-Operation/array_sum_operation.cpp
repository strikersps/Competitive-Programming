/*
 * Problem Statement: https://www.hackerrank.com/contests/hack-the-interview-vi-asia-pacific/challenges/maximum-sum-10-1
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

// Constant Macros.
#define MOD 1000000007 // Constant (prime number) used in most competitive programming problems to reduce the answer to a 32-bit integer.
#define PI 3.141592653589793 // Number of digits(15) of Pi which JPL uses for Interplanetary Calculations.
#define GOLDEN_RATIO 1.618033988749895 // Number of digits(15).
#define MAX_32_BIT_US_INT 0xFFFFFFFF // Maximum value which can be stored in an unsigned int (32-Bit).
#define MAX_64_BIT_US_INT 0xFFFFFFFFFFFFFFFF // Maximum value which can be stored in an unsigned long long (64-Bit).
#define NEW_LINE '\n' // Created because sometimes std :: endl makes the code slower due to clearance of buffer after printing new-line.

// Debugging Macros.
#define WATCH(x) std :: cerr << "Line Number: " << __LINE__ << ": " << #x << "-value: " << (x) << NEW_LINE

// Mathematical Macros.
#define COMPUTE_GCD(a, b) std :: __gcd((a), (b))
#define COMPUTE_LCM(a, b) (a * ((b) / COMPUTE_GCD(a, b)))

// Bit-Manipulation Macros.
// Computes the number of set-bits in the binary representation of n (64-Bit).
#define COMPUTE_SET_BITS(number) __builtin_popcountll(number)

// Computes the parity of the number n (64-Bit) i.e. parity is 0 if the number of set-bits is even otherwise odd.
#define COMPUTE_PARITY(number) __builtin_parity(number)

// Computes the number of leading zeroes in the binary representation of n (64-Bit). The value will be 64 - (number of bits required to represent n).
#define COMPUTE_LEADING_ZEROES(number) __builtin_clzll(number)

// Computes the number of trailing zeroes in the binary representation of n (64-Bit). The value will always be zero if n is odd.
#define COMPUTE_TRAILING_ZEROES(number) __builtin_ctzll(number)

// C and C++ "%" operator is not a modular arithmetic operator rather it's a remainder operator which gives remainder when a / b.
// Implementation is based on the fact that a % b = a - (b * (a / b)), where a = dividend, b = divisor, a / b = quotient.
// Refer: https://stackoverflow.com/questions/11720656/modulo-operation-with-negative-numbers
// Time Complexity: O(1).
ll_t compute_mod(ll_t a, ll_t b) {
    assert(b > 0LL); // Denominator must be positive.
    ll_t rem = a % b;
    return rem < 0LL ? b + rem : rem;
}

// The function computes the total number of divisors for the given n.
// Time-Complexity: O(sqrt(n)). NOTE: O(logn) algorithm also exist for computing the divisors of a number using Sieve.
ll_t compute_total_divisors(ll_t n) {
    ll_t total_divisors = 0LL;
    for(ll_t i = 1; i <= (n / i); ++i) {
        if(!(n % i)) {
            if((n / i) == i) {
                ++total_divisors;
                continue;
            }
            total_divisors += 2LL;
        }
    }
    return total_divisors;
}

// The code computes whether the given number (n) is a perfect square or not based on the fact that, a number is a perfect square if it has odd number of divisors.
// Refer: https://math.stackexchange.com/questions/906159/a-number-is-a-perfect-square-if-and-only-if-it-has-odd-number-of-positive-diviso
// Time-Complexity: O(sqrt(n)).
bool check_perfect_sequare(ll_t n) {
    return compute_total_divisors(n) % 2LL ? true : false;
}

/*END-OF CODE-TEMPLATE*/

static void execute_queuries(std :: vector <int> &, const int, int);

int main(void) {
    FAST_IO(0);
    int n, m;
    std :: cin >> n >> m;
    std :: vector <int> sequence(n);
    std :: iota(sequence.begin(), sequence.end(), 1);
    execute_queuries(sequence, n, m);
    return 0;
}

static void execute_queuries(std :: vector <int> & sequence, const int n, int m) {
    ll_t sequence_sum = std :: accumulate(sequence.begin(), sequence.end(), 0LL);
    while(m--) {
        int q_val;
        std :: cin >> q_val;
        if(sequence.at(0) == q_val || sequence.at(n - 1) == q_val || std :: binary_search(sequence.begin() + 1, sequence.end() - 1, q_val)) {
            int temp_data = sequence.at(0);
            sequence.at(0) = sequence.at(n - 1);
            sequence.at(n - 1) = temp_data;
        } else {
            sequence_sum -= sequence.at(n - 1);
            sequence.pop_back(); sequence.push_back((ll_t) q_val);
            sequence_sum += q_val;
        }
        std :: cout << sequence_sum << NEW_LINE;
    }
}
