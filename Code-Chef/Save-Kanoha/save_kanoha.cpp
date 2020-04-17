/*
 * Problem Statement: https://www.codechef.com/LRNDSA03/problems/SAVKONO
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

static void compute_minimum_soldier(std :: priority_queue <int> &, int);

int main(void) {
    FAST_IO(0);
    int test;
    std :: cin >> test;
    while(test--) {
        int n, z;
        std :: cin >> n >> z;
        std :: priority_queue <int> soldier_power;
        for(int i = 0; i < n; ++i) {
            int read_data;
            std :: cin >> read_data;
            soldier_power.push(read_data);
        }
        compute_minimum_soldier(soldier_power, z);
    }
    return 0;
}

static void compute_minimum_soldier(std :: priority_queue <int> & soldier_power, int z) {
    int min_soldiers = 0;
    while(z > 0 && !soldier_power.empty()) {
        ++min_soldiers;
        z -= soldier_power.top();
        int current_soldier_power = soldier_power.top() >> 1;
        soldier_power.pop();
        if(current_soldier_power > 0) {
            soldier_power.push(current_soldier_power);
        }
    }
    if(z > 0) {
        std :: cout << "Evacuate";
    } else {
        std :: cout << min_soldiers;
    }
    std :: cout << std :: endl;
}
