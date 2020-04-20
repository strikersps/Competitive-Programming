/*
 * Problem Statement: https://www.codechef.com/problems/SHKNUM
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

static void precomputation(std :: vector <ll_t> &);

int main(void) {
    FAST_IO(0);
    int test;
    std :: cin >> test;
    std :: vector <ll_t> number;
    precomputation(number);
    while(test--) {
        int n;
        std :: cin >> n;
        std :: vector <ll_t> :: iterator itr = std :: lower_bound(number.begin(), number.end(), n);
        if(*itr == n) {
            std :: cout << 0 << std :: endl;
            continue;
        }
        if(itr == number.end()) {
            std :: cout << n - *prev(itr, 1) << std :: endl;
            continue;
        }
        if(itr == number.begin()) {
            std :: cout << *itr - n << std :: endl;
            continue;
        }
        std :: cout << std :: min(n - *prev(itr, 1), *itr - n) << std :: endl;
    }
    return 0;
}

static void precomputation(std :: vector <ll_t> & number) {
    for(ll_t i = 0; i < 31; ++i) {
        for(ll_t j = i + 1; j < 31; ++j) {
            number.push_back((1LL << i) + (1LL << j));
        }
    }
    std :: sort(number.begin(), number.end());
}
