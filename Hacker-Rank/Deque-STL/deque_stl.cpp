/*
 * Problem Statement: https://www.hackerrank.com/challenges/deque-stl/problem
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

static std :: vector <int> compute_maximum_in_subarray(const std :: vector<int> &, const int, const int);
static void display_vector(const std :: vector <int> &);

int main(void) {
    FAST_IO(0);
    int test;
    std :: cin >> test;
    while(test--) {
        int n, k;
        std :: cin >> n >> k;
        std :: vector <int> sequence(n);
        for(int i = 0; i < n; ++i) {
            std :: cin >> sequence[i];
        }
        if(k == 1) {
            display_vector(sequence);
            continue;
        }
        if(k == n) {
            std :: cout << (*std :: max_element(sequence.begin(), sequence.end())) << std :: endl;
            continue;
        }
        display_vector(compute_maximum_in_subarray(sequence, n, k));
    }
    return 0;
}

static void display_vector(const std :: vector <int> & sequence) {
    for(const int & value: sequence) {
        std :: cout << value << " ";
    }
    std :: cout << std :: endl;
}

static std :: vector <int> compute_maximum_in_subarray(const std :: vector <int> & sequence, const int n, const int k) {
    std :: vector <int> max_subarray_value;
    std :: deque <int> max_index_queue;
    for(int i = 0; i < k; ++i) {
        while(!max_index_queue.empty() && sequence[i] >= sequence[max_index_queue.back()]) {
            max_index_queue.pop_back();
        }
        max_index_queue.push_back(i);
    }
    for(int i = k; i < n; ++i) {
        max_subarray_value.push_back(sequence[max_index_queue.front()]);
        while(!max_index_queue.empty() && i - max_index_queue.front() >= k) {
            max_index_queue.pop_front();
        }
        while(!max_index_queue.empty() && sequence[i] >= sequence[max_index_queue.back()]) {
            max_index_queue.pop_back();
        }
        max_index_queue.push_back(i);
    }
    max_subarray_value.push_back(sequence[max_index_queue.front()]);
    return max_subarray_value;
}
