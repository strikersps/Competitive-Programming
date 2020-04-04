/*
 * Problem Statement: https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020993c?show=progress
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
#include <set>
#include <algorithm>
#include <cmath>

typedef unsigned long long ull_t;
typedef long long ll_t;

#define FAST_IO(value) std :: ios :: sync_with_stdio(value); std :: cin.tie(value)
#define MOD 10000000007 // Constant (prime number) used in most competitive programming problems to reduce the answer to a 32-bit integer.
#define PI 3.141592653589793 // Number of digits(15) of Pi which JPL uses for Interplanetary Caculations.
#define GOLDEN_RATIO 1.618033988749895 // Number of digits(15).

static void compute_answer(const int, std :: vector<std :: vector<int>> &, const int);

int main(void) {
    FAST_IO(0);
    int test;
    std :: cin >> test;
    for(register int t = 1; t <= test; ++t) {
        int n;
        std :: cin >> n;
        std :: vector <std :: vector <int>> matrix;
        matrix.resize(n, std :: vector<int> (n, 0));
        for(register int i = 0; i < n; ++i) {
            for(register int j = 0; j < n; ++j) {
                std :: cin >> matrix[i][j];
            }
        }
        compute_answer(t, matrix, n);
    }
    return 0;
}

static void compute_answer(const int test_number, std :: vector <std :: vector <int>> & matrix, const int n) {
    int trace = 0;
    for(register int i = 0; i < n; ++i) {
        trace += matrix[i][i];
    }
    int count_duplicate_rows = 0;
    for(register int i = 0; i < n; ++i) {
        std :: set <int> duplicate_set;
        for(register int j = 0; j < n; ++j) {
            if(duplicate_set.find(matrix[i][j]) == duplicate_set.end()) {
                duplicate_set.insert(matrix[i][j]);
                continue;
            }
            ++count_duplicate_rows;
            break;
        }
    }
    int count_duplicate_cols = 0;
    for(register int i = 0; i < n; ++i) {
        std :: set <int> duplicate_set;
        for(register int j = 0; j < n; ++j) {
            if(duplicate_set.find(matrix[j][i]) == duplicate_set.end()) {
                duplicate_set.insert(matrix[j][i]);
                continue;
            }
            ++count_duplicate_cols;
            break;
        }
    }
    std :: cout << "Case #" << test_number << ": " << trace << " " << count_duplicate_rows << " " << count_duplicate_cols << std :: endl;
}
