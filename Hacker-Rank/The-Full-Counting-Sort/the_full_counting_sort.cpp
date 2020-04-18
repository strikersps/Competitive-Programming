/*
 * Problem Statement: https://www.hackerrank.com/challenges/countingsort4/problem
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
    int n;
    std :: cin >> n;
    std :: map <int, std :: vector <std :: string>> int_string_map;
    for(int i = 0; i < n; ++i) {
        int key;
        std :: string value;
        std :: cin >> key >> value;
        if(i < (n >> 1)) {
            int_string_map[key].push_back("-");
            continue;
        }
        int_string_map[key].push_back(value);
    }
    for(auto itr = int_string_map.begin(); itr != int_string_map.end(); ++itr) {
        for(size_t i = 0; i < itr->second.size(); ++i) {
            std :: cout << itr->second[i] << " ";
        }
    }
    std :: cout << std :: endl;
    return 0;
}
