/*
 * Problem Statement: https://codeforces.com/contest/1343/problem/B
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

int main(void) {
    FAST_IO(0);
    int test;
    std :: cin >> test;
    while(test--) {
        int n;
        std :: cin >> n;
        if(n == 2 || (n / 2) % 2) {
            std :: cout << "NO" << std :: endl;
            continue;
        }
        std :: cout << "YES" << std :: endl;
        for(int i = 0, even_number = 2, odd_number = 1, even_number_sum = 0; i < n; ++i) {
            if(i < (n / 2)) {
                std :: cout << even_number << " ";
                even_number_sum += even_number;
                even_number += 2;
                continue;
            }
            if(i < (n - 1)) {
                std :: cout << odd_number << " ";
            } else {
                std :: cout << even_number_sum << " ";
            }
            even_number_sum -= odd_number;
            odd_number += 2;
        }
        std :: cout << std :: endl;
    }
    return 0;
}
