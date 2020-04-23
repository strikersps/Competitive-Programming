/*
 * Problem Statement: https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020993c
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

static void solve(const std :: vector <std :: vector <int>> &, const int);

int main(void) {
    FAST_IO(0);
    int test;
    std :: cin >> test;
    for(int t = 1; t <= test; ++t) {
        int n;
        std :: cin >> n;
        std :: vector <std :: vector <int>> matrix(n, std :: vector <int> (n));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                std :: cin >> matrix[i][j];
            }
        }
        std :: cout << "Case #" << t << ": ";
        solve(matrix, n);
        std :: cout << std :: endl;
    }
    return 0;
}

static void solve(const std :: vector <std :: vector <int>> & matrix, const int n) {
    int matrix_trace = 0;
    for(int i = 0; i < n; ++i) {
        matrix_trace += matrix[i][i];
    }
    int duplicate_row_count = 0;
    for(int i = 0; i < n; ++i) {
        std :: unordered_set <int> duplicate;
        for(int j = 0; j < n; ++j) {
            if(duplicate.count(matrix[i][j]) == 1) {
                ++duplicate_row_count;
                break;
            }
            duplicate.insert(matrix[i][j]);
        }
    }
    int duplicate_col_count = 0;
    for(int i = 0; i < n; ++i) {
        std :: unordered_set <int> duplicate;
        for(int j = 0; j < n; ++j) {
            if(duplicate.count(matrix[j][i]) == 1) {
                ++duplicate_col_count;
                break;
            }
            duplicate.insert(matrix[j][i]);
        }
    }
    std :: cout << matrix_trace << " " << duplicate_row_count << " " << duplicate_col_count;
}
