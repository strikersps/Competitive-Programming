/*
 * Problem Statement: https://cses.fi/problemset/task/1092/
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

static void generate_set(ll_t, const ll_t);
static void print_set(const std :: unordered_set <ll_t> &);

int main(void) {
    FAST_IO(0);
    ll_t n;
    std :: cin >> n;
    ll_t sum_of_n_numbers = (n * (n + 1)) / 2;
    if(sum_of_n_numbers % 2) {
        std :: cout << "NO" << std :: endl;
    } else {
        std :: cout << "YES" << std :: endl;
        generate_set(sum_of_n_numbers / 2, n);
    }
    return 0;
}

static void generate_set(ll_t set_sum, const ll_t n) {
    std :: unordered_set <ll_t> s1, s2;
    for(ll_t i = 0; set_sum > 0; set_sum -= (n - i), ++i) {
        if(set_sum > n) {
            s1.insert(n - i);
        } else {
            if(s1.count(set_sum)) {
                s1.insert(n - i);
            } else {
                s1.insert(set_sum);
                break;
            }
        }
    }
    for(ll_t i = 1; i <= n; ++i) {
        if(!s1.count(i)) {
            s2.insert(i);
            continue;
        }
    }
    std :: cout << s1.size() << std :: endl;
    print_set(s1);
    std :: cout << s2.size() << std :: endl;
    print_set(s2);
    assert(std :: accumulate(s1.begin(), s1.end(), 0) == std :: accumulate(s2.begin(), s2.end(), 0));
}

static void print_set(const std :: unordered_set <ll_t> & s) {
    for(const int & number: s) {
        std :: cout << number << " ";
    }
    std :: cout << std :: endl;
}
