/*
 * Problem Statement: https://www.codechef.com/APRIL20B/problems/COVIDLQ
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
#define MOD 10000000007 // Constant (prime number) used in most competitive programming problems to reduce the answer to a 32-bit integer.
#define PI 3.141592653589793 // Number of digits(15) of Pi which JPL uses for Interplanetary Caculations.
#define GOLDEN_RATIO 1.618033988749895 // Number of digits(15).

static bool check_social_distancing(const std :: vector <int> & , const int);

int main(void) {
    FAST_IO(0);
    int test;
    std :: cin >> test;
    while(test--) {
        int n;
        std :: cin >>  n;
        std :: vector <int> people_queue(n);
        for(register int i = 0; i < n; ++i) {
            std :: cin >> people_queue[i];
        }
        std :: cout << (check_social_distancing(people_queue, n) ? "YES" : "NO") << '\n';
    }
    return 0;
}

static bool check_social_distancing(const std :: vector <int> & people_queue, const int n) {
    bool is_social_distancing_followed = true;
    int last_person_loc = 0;
    for(register int i = 0; i < n; ++i) {
        if(!last_person_loc && people_queue[i]) {
            last_person_loc = i + 1;
            continue;
        }
        if(last_person_loc && people_queue[i]) {
            if(((i + 1) - last_person_loc) < 6) {
                is_social_distancing_followed = false;
                break;
            }
            last_person_loc = i + 1;
        }
    }
    return is_social_distancing_followed;
}

