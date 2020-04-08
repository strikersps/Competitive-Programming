/*
 * Problem Statement: https://www.codechef.com/LRNDSA02/problems/STUPMACH
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
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <string>
#include <cmath>

typedef unsigned long long ull_t;
typedef long long ll_t;

#define FAST_IO(value) std :: ios :: sync_with_stdio(value); std :: cin.tie(NULL)
#define MOD 1000000007 // Constant (prime number) used in most competitive programming problems to reduce the answer to a 32-bit integer.
#define PI 3.141592653589793 // Number of digits(15) of Pi which JPL uses for Interplanetary Caculations.
#define GOLDEN_RATIO 1.618033988749895 // Number of digits(15).

static ll_t compute_maximum_token(const std :: vector <ll_t> &, const int);

int main(void) {
    FAST_IO(0);
    int test;
    std :: cin >> test;
    while(test--) {
        int n;
        std :: cin >> n;
        std :: vector <ll_t> box(n, 0LL);
        for(int i = 0; i < n; ++i) {
            std :: cin >> box[i];
        }
        std :: cout << compute_maximum_token(box, n) << std :: endl;
    }
    return 0;
}

static ll_t compute_maximum_token(const std :: vector <ll_t> & box, const int n) {
    std :: stack <std :: pair <int, ll_t>> min_elements;
    min_elements.push(std :: make_pair(0, box[0]));
    ll_t min_val = box[0];
    for(int i = 1; i < n; ++i) {
        if(box[i] < min_val) {
            min_elements.push(std :: make_pair(i, box[i]));
            min_val = box[i];
        }
    }
    ll_t new_size = n, substractor = 0;
    ll_t max_token = 0;
    while(!min_elements.empty()) {
        min_val = min_elements.top().second - substractor;
        substractor += min_val;
        max_token += (new_size * min_val);
        new_size = min_elements.top().first;
        min_elements.pop();
    }
    return max_token;
}
