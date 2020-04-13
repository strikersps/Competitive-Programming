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
#include <cstdio>

typedef unsigned long long ull_t;
typedef long long ll_t;

#define FAST_IO(value) std :: ios :: sync_with_stdio(value); std :: cin.tie(NULL)
#define MOD 1000000007 // Constant (prime number) used in most competitive programming problems to reduce the answer to a 32-bit integer.
#define PI 3.141592653589793 // Number of digits(15) of Pi which JPL uses for Interplanetary Caculations.
#define GOLDEN_RATIO 1.618033988749895 // Number of digits(15).

static int compute_largest_value_smaller_than_n(const std :: vector <ll_t> &, int, int, const ll_t);
static int compute_smallest_value_larger_than_n(const std :: vector <ll_t> &, int, int, const ll_t);
static ll_t compute_minimum_time(const std :: vector <std :: pair <ll_t, ll_t>> &, std :: vector <ll_t> &, const int, std :: vector <ll_t> &, const int);

int main(void) {
    FAST_IO(0);
    int n, m, k;
    std :: cin >> n >> m >> k;
    std :: vector <std :: pair <ll_t, ll_t>> contest_schedule(n);
    for(int i = 0; i < n; ++i) {
        std :: cin >> contest_schedule[i].first >> contest_schedule[i].second;
    }
    std :: vector <ll_t> wormhole_open_time(m);
    for(int i = 0; i < m; ++i) {
        std :: cin >> wormhole_open_time[i];
    }
    std :: vector <ll_t> wormhole_close_time(k);
    for(int i = 0; i < k; ++i) {
        std :: cin >> wormhole_close_time[i];
    }
    std :: cout << compute_minimum_time(contest_schedule, wormhole_open_time, m, wormhole_close_time, k) << std :: endl;
    return 0;
}

static int compute_largest_value_smaller_than_n(const std :: vector <ll_t> & data, int start, int end, const ll_t key) {
    int found_index = -1;
    if(key < data[0]) {
        return found_index;
    }
    while(start <= end) {
        const int mid = start + ((end - start) >> 1);
        if(data[mid] == key) {
            found_index = mid;
            break;
        } else if(data[mid] > key) {
            end = mid - 1;
            continue;
        }
        found_index = mid;
        start = mid + 1;
    }
    return found_index;
}

static int compute_smallest_value_larger_than_n(const std :: vector <ll_t> & data, int start, int end, const ll_t key) {
    int found_index = -1;
    if(data[end] < key) {
        return found_index;
    }
    while(start <= end) {
        const int mid = start + ((end - start) >> 1);
        if(data[mid] == key) {
            found_index = mid;
            break;
        } else if(data[mid] < key) {
            start = mid + 1;
            continue;
        }
        found_index = mid;
        end = mid - 1;
    }
    return found_index;
}

static ll_t compute_minimum_time(const std :: vector <std :: pair <ll_t, ll_t>> & contest_schedule, std :: vector <ll_t> & wormhole_open_time, const int m, std :: vector <ll_t> & wormhole_close_time, const int k) {
    std :: sort(wormhole_open_time.begin(), wormhole_open_time.end());
    std :: sort(wormhole_close_time.begin(), wormhole_close_time.end());

    ll_t min_time = std :: numeric_limits <ll_t> :: max();

    for(const auto & schedule: contest_schedule) {
        int t1 = compute_largest_value_smaller_than_n(wormhole_open_time, 0, m - 1, schedule.first);
        if(t1 == -1) {
            continue;
        }
        int t2 = compute_smallest_value_larger_than_n(wormhole_close_time, 0, k - 1, schedule.second);
        if(t2 == -1) {
            continue;
        }
        min_time = std :: min(min_time, wormhole_close_time[t2] - wormhole_open_time[t1] + 1);
    }
    return min_time;
}
