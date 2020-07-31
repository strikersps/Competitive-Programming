/*
 * Problem Statement: https://www.codechef.com/LRNDSA02/problems/ZCO12002
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
#define PI 3.141592653589793 // Number of digits(15) of Pi which JPL uses for Interplanetary Calculations.
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

static int compute_minimum_time(const std :: vector <std :: pair <int, int>> &, const std :: vector <int> &, const std :: vector <int> &);

int main(void) {
    FAST_IO(0);
    int n, x, y;
    std :: cin >> n >> x >> y;
    std :: vector <std :: pair <int, int>> contest_schedules(n);
    for(std :: pair <int, int> & schedule: contest_schedules) {
        std :: cin >> schedule.first >> schedule.second;
    }
    std :: vector <int> home_to_centre_wormhole_open_times(x);
    for(int & open_time: home_to_centre_wormhole_open_times) {
        std :: cin >> open_time;
    }
    std :: sort(home_to_centre_wormhole_open_times.begin(), home_to_centre_wormhole_open_times.end());
    std :: vector <int> centre_to_home_wormhole_open_times(y);
    for(int & open_time: centre_to_home_wormhole_open_times) {
        std :: cin >> open_time;
    }
    std :: sort(centre_to_home_wormhole_open_times.begin(), centre_to_home_wormhole_open_times.end());
    std :: cout << compute_minimum_time(contest_schedules, home_to_centre_wormhole_open_times, centre_to_home_wormhole_open_times) << NEW_LINE;
    return 0;
}

static int compute_minimum_time(const std :: vector <std :: pair <int, int>> & contest_schedules, const std :: vector <int> & home_to_centre_wormhole_open_times, const std :: vector <int> & centre_to_home_wormhole_open_times) {
    int min_time = std :: numeric_limits <int> :: max();
    for(const std :: pair <int, int> & schedule: contest_schedules) {
        if(schedule.first < home_to_centre_wormhole_open_times.at(0)) {
            continue;
        }
        auto t1 = std :: lower_bound(home_to_centre_wormhole_open_times.begin(), home_to_centre_wormhole_open_times.end(), schedule.first);
        if(t1 == home_to_centre_wormhole_open_times.end() || *t1 != schedule.first) {
            --t1;
        }
        if(schedule.second > centre_to_home_wormhole_open_times.at(centre_to_home_wormhole_open_times.size() - 1)) {
            continue;
        }
        auto t2 = std :: lower_bound(centre_to_home_wormhole_open_times.begin(), centre_to_home_wormhole_open_times.end(), schedule.second);
        min_time = std :: min(min_time, *t2 - *t1 + 1);
    }
    return min_time;
}
