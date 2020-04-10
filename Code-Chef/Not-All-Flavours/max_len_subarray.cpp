/*
 * Problem Statement: https://www.codechef.com/LRNDSA02/problems/NOTALLFL
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
#include <stack>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <algorithm>
#include <cmath>

typedef unsigned long long ull_t;
typedef long long ll_t;

#define FAST_IO(value) std :: ios :: sync_with_stdio(value); std :: cin.tie(NULL)
#define MOD 1000000007 // Constant (prime number) used in most competitive programming problems to reduce the answer to a 32-bit integer.
#define PI 3.141592653589793 // Number of digits(15) of Pi which JPL uses for Interplanetary Caculations.
#define GOLDEN_RATIO 1.618033988749895 // Number of digits(15).

static int compute_length_of_subaray(const std :: vector <int> &, const int, const int);

int main(void) {
    FAST_IO(0);
    int test;
    std :: cin >> test;
    while(test--) {
        int n, k ;
        std :: cin >> n >> k;
        std :: vector <int> cake_flavour(n);
        for(int i = 0; i < n; ++i) {
            std :: cin >> cake_flavour[i];
        }
        std :: cout << compute_length_of_subaray(cake_flavour, n, k) << std :: endl;
    }
    return 0;
}

static int compute_length_of_subaray(const std :: vector <int> & cake_flavour, const int n, const int k) {
    if(k > n) {
        return n;
    }
    int subarray_len = 0, max_subarray_len = 0;
    std :: vector <int> freq_map(k, 0);
    for(int start = 0, end = 0, unique_number_count = 0; start < n; ++start, --subarray_len) {
        // If I can extend the size of the sub-array, then extend it.
        while(end < n && (freq_map[cake_flavour[end] - 1] || unique_number_count < (k - 1))) {
            ++subarray_len;
            if(!freq_map[cake_flavour[end] - 1]) {
                ++unique_number_count;
            }
            ++freq_map[cake_flavour[end] - 1];
            ++end;
        }
        max_subarray_len = std :: max(max_subarray_len, subarray_len);
        if(end == n) {
            break;
        }
        --freq_map[cake_flavour[start] - 1];
        if(!freq_map[cake_flavour[start] - 1]) {
            --unique_number_count;
        }
    }
    return max_subarray_len;
}
