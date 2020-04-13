/*
 * Problem Statement: https://www.codechef.com/LRNDSA02/problems/ZCO12002
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
#include <cstdlib>
#include <cstdio>

typedef unsigned long long ull_t;
typedef long long ll_t;

#define FAST_IO(value) std :: ios :: sync_with_stdio(value); std :: cin.tie(NULL)
#define MOD 1000000007 // Constant (prime number) used in most competitive programming problems to reduce the answer to a 32-bit integer.
#define PI 3.141592653589793 // Number of digits(15) of Pi which JPL uses for Interplanetary Caculations.
#define GOLDEN_RATIO 1.618033988749895 // Number of digits(15).

static ll_t compute_minimum_time(const std :: vector <std :: pair <ll_t, ll_t>> &, std :: vector <ll_t> &, std :: vector <ll_t> &);

int main(void) {
    FAST_IO(0);
    int n, x, y;
    std :: cin >> n >> x >> y;
    std :: vector <std :: pair <ll_t, ll_t>> contest_schedule(n);
    for(int i = 0; i < n; ++i) {
        std :: cin >> contest_schedule[i].first >> contest_schedule[i].second;
    }
    std :: vector <ll_t> wormhole_open_time(x, 0), wormhole_close_time(y, 0);
    for(int i = 0; i < x; ++i) {
        std :: cin >> wormhole_open_time[i];
    }
    for(int i = 0; i < y; ++i) {
        std :: cin >> wormhole_close_time[i];
    }
    std :: cout << compute_minimum_time(contest_schedule, wormhole_open_time, wormhole_close_time) << std :: endl;
    return 0;
}

static ll_t compute_minimum_time(const std :: vector <std :: pair <ll_t, ll_t>> & contest_schedule, std :: vector <ll_t> & wormhole_open_time, std :: vector <ll_t> & wormhole_close_time) {

    std :: sort(wormhole_open_time.begin(), wormhole_open_time.end());
    std :: sort(wormhole_close_time.begin(), wormhole_close_time.end());

    ll_t min_time = 1e10;

    for(const auto & schedule: contest_schedule) {
        std :: vector <ll_t> :: iterator t1 = std :: upper_bound(wormhole_open_time.begin(), wormhole_open_time.end(), schedule.first);
        if(t1 == wormhole_open_time.begin()) {
            continue;
        }
        // t1 = wormhole_open_time.begin() + (t1 - wormhole_open_time.begin()) - 1;
        --t1;
        std :: vector <ll_t> :: iterator t2 = std :: lower_bound(wormhole_close_time.begin(), wormhole_close_time.end(), schedule.second);
        if(t2 == wormhole_close_time.end()) {
            continue;
        }
        min_time = std :: min(min_time, 1 + ((*t2) - (*t1)));
    }
    return min_time;
}
