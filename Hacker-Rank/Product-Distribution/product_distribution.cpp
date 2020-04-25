/*
 * Problem Statement: https://www.hackerrank.com/contests/hack-the-interview-ii-global/challenges/distribution-in-m-bins
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

static int compute_maximum_score(const std :: vector <int> &, const int, const int);

int main(void) {
    FAST_IO(0);
    int n, m;
    std :: cin >> n >> m;
    std :: vector <int> product_value(n);
    for(int i = 0; i < n; ++i) {
        std :: cin >> product_value[i];
    }
    std :: sort(product_value.begin(), product_value.end());
    std :: cout << compute_maximum_score(product_value, n, m) << std :: endl;
    return 0;
}

static int compute_maximum_score(const std :: vector <int> & product_value, const int n, const int m) {
    int tot_segment = n / m;
    ll_t curr_segment_score;
    int max_score;
    curr_segment_score = max_score = 0;
    for(int item_count = 0, end = 0, segment_count = 1; segment_count <= tot_segment; ) {
        if(segment_count < tot_segment && item_count < m) {
            ++item_count;
            curr_segment_score += product_value[end++];
            continue;
        }
        max_score = (max_score + (segment_count * curr_segment_score)) % MOD;
        curr_segment_score = 0;
        if(segment_count == tot_segment) {
            while(end < n) {
                curr_segment_score += product_value[end++];
            }
            max_score = (max_score + (segment_count * curr_segment_score)) % MOD;
        }
        item_count = 0;
        ++segment_count;
    }
    return max_score;
}
