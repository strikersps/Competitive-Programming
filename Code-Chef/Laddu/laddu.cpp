/*
 * Problem Statement: https://www.codechef.com/LRNDSA01/problems/LADDU
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
#include <set>
#include <algorithm>
#include <cmath>

typedef unsigned long long ull_t;
typedef long long ll_t;

#define FAST_IO(value) std :: ios :: sync_with_stdio(value); std :: cin.tie(value)
#define MOD 1000000007 // Constant (prime number) used in most competitive programming problems to reduce the answer to a 32-bit integer.
#define PI 3.141592653589793 // Number of digits(15) of Pi which JPL uses for Interplanetary Caculations.
#define GOLDEN_RATIO 1.618033988749895 // Number of digits(15).

int main(void) {
    FAST_IO(0);
    int test;
    std :: cin >> test;
    while(test--) {
        int tot_activities;
        std :: string user_origin;
        std :: cin >> tot_activities >> user_origin;
        int tot_laddus = 0;
        for(int i = 0; i < tot_activities; ++i) {
            std :: string activity_name;
            std :: cin >> activity_name;
            if(activity_name == "CONTEST_WON") {
                tot_laddus += 300;
                int rank;
                std :: cin >> rank;
                if(rank <= 20) {
                    tot_laddus += (20 - rank);
                }
                continue;
            }
            if(activity_name == "TOP_CONTRIBUTOR") {
                tot_laddus += 300;
                continue;
            }
            if(activity_name == "BUG_FOUND") {
                int bug_severity;
                std :: cin >> bug_severity;
                tot_laddus += bug_severity;
                continue;
            }
            if(activity_name == "CONTEST_HOSTED") {
                tot_laddus += 50;
            }
        }
        std :: cout << (user_origin == "INDIAN" ? tot_laddus / 200 : tot_laddus / 400) << std :: endl;
    }
    return 0;
}
