/*
 * Problem Statement: https://www.codechef.com/LRNDSA04/problems/EURON/
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

static ll_t compute_inversion(int[], const int, const int);
static ll_t merge_data(int[], const int, const int, const int);

int main(void) {
    FAST_IO(0);
    int n;
    std :: cin >> n;
    int sequence[n];
    for(int i = 0; i < n; ++i) {
        std :: cin >> sequence[i];
    }
    std :: cout << compute_inversion(sequence, 0, n - 1) << std :: endl;
    return 0;
}

static ll_t compute_inversion(int sequence[], const int start, const int end) {
    ll_t inversion_count = 0;
    if(start < end) {
        const int mid = start + ((end - start) >> 1);
        inversion_count += compute_inversion(sequence, start, mid);
        inversion_count += compute_inversion(sequence, mid + 1, end);
        inversion_count += merge_data(sequence, start, mid, end);
    }
    return inversion_count;
}

static ll_t merge_data(int sequence[], const int start, const int mid, const int end) {
    int left_size = mid - start + 1;
    int left_data[left_size];
    memcpy(left_data, &sequence[start], left_size * sizeof(int));
    int right_size = end - mid;
    int right_data[right_size];
    memcpy(right_data, &sequence[mid + 1], right_size * sizeof(int));
    ll_t inversion_count = 0;
    for(int k = start, i = 0, j = 0; k <= end; ++k) {
        if(i == left_size) {
            sequence[k] = right_data[j++];
            continue;
        }
        if(j == right_size) {
            sequence[k] = left_data[i++];
            continue;
        }
        if(left_data[i] > right_data[j]) {
            inversion_count += (left_size - i);
            sequence[k] = right_data[j++];
            continue;
        }
        sequence[k] = left_data[i++];
    }
    return inversion_count;
}
