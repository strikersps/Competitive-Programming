/*
 * Problem Statement: https://www.codechef.com/LRNDSA03/problems/DPAIRS
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

typedef unsigned long long ull_t;
typedef long long ll_t;

#define FAST_IO(value) std :: ios :: sync_with_stdio(value); std :: cin.tie(NULL)
#define MOD 1000000007 // Constant (prime number) used in most competitive programming problems to reduce the answer to a 32-bit integer.
#define PI 3.141592653589793 // Number of digits(15) of Pi which JPL uses for Interplanetary Caculations.
#define GOLDEN_RATIO 1.618033988749895 // Number of digits(15).

static void compute_distinct_pairs(const std :: vector <int> &, const int, const std :: vector <int> &, const int);

int main(void) {
    FAST_IO(0);
    int n, m;
    std :: cin >> n >> m;
    std :: vector <int> sequence1(n);
    std :: vector <int> sequence2(m);
    for(int i = 0; i < n; ++i) {
        std :: cin >> sequence1[i];
    }
    for(int i = 0; i < m; ++i) {
        std :: cin >> sequence2[i];
    }
    compute_distinct_pairs(sequence1, n, sequence2, m);
    return 0;
}

static void compute_distinct_pairs(const std :: vector <int> & sequence1, const int n, const std :: vector <int> & sequence2, const int m) {
    int min_index_s1 = std :: min_element(sequence1.begin(), sequence1.end()) - sequence1.begin();
    int max_index_s2 = std :: max_element(sequence2.begin(), sequence2.end()) - sequence2.begin();
    for(int i = 0; i < m; ++i) {
        std :: cout << min_index_s1 << " " << i << std :: endl;
    }
    for(int i = 0; i < n; ++i) {
        if(i == min_index_s1) {
            continue;
        }
        std :: cout << i << " " << max_index_s2 << std :: endl;
    }
}
