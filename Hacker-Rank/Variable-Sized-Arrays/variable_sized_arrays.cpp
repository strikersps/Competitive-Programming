/*
 * Problem Statement: https://www.hackerrank.com/challenges/variable-sized-arrays/problem
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
#include <set>
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

int main(void) {
    FAST_IO(0);
    int n, q;
    std :: cin >> n >> q;
    std :: vector <std :: vector<int>> variable_sized_array;
    for(int i = 0; i < n; ++i) {
        int row_size;
        std :: cin >> row_size;
        std :: vector <int> temp_row(row_size);
        for(int j = 0; j < row_size; ++j) {
            std :: cin >> temp_row[j];
        }
        variable_sized_array.push_back(temp_row);
    }
    for(int i = 0; i < q; ++i) {
        int row_index, col_index;
        std :: cin >> row_index >> col_index;
        std :: cout << variable_sized_array[row_index][col_index] << std :: endl;
    }
    return 0;
}
