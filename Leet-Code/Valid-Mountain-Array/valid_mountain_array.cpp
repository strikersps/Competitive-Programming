/*
 * Problem Statement: https://leetcode.com/problems/valid-mountain-array/
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

typedef unsigned long long ull_t;
typedef long long ll_t;

#define FAST_IO(value) std :: ios :: sync_with_stdio(value); std :: cin.tie(NULL)
#define MOD 1000000007 // Constant (prime number) used in most competitive programming problems to reduce the answer to a 32-bit integer.
#define PI 3.141592653589793 // Number of digits(15) of Pi which JPL uses for Interplanetary Caculations.
#define GOLDEN_RATIO 1.618033988749895 // Number of digits(15).

static bool check_valid_mountain_array(const std :: vector <int> &, const int);

int main(void) {
    FAST_IO(0);
    int test;
    std :: cin >> test;
    while(test--) {
        int n;
        std :: cin >> n;
        std :: vector <int> sequence(n);
        for(int i = 0; i < n; ++i) {
            std :: cin >> sequence[i];
        }
        std :: cout << (check_valid_mountain_array(sequence, n) ? "true" : "false") << std :: endl;
    }
    return 0;
}

// The function implements the logic for the solution.
static bool check_valid_mountain_array(const std :: vector <int> & sequence, const int n) {
    if(n < 3) {
        return false;
    }
    int left_end = 0, right_end = n - 1;
    for(; left_end < (n - 1) && sequence[left_end] < sequence[left_end + 1]; ++left_end);
    for(; right_end > 0 && sequence[right_end] < sequence[right_end - 1]; --right_end);
    return (left_end == n - 1 || right_end == 0 || left_end != right_end) ? false : true;
}
