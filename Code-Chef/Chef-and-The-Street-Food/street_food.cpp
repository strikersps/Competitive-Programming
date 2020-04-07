/*
 * Problem Statement: https://www.codechef.com/LRNDSA02/problems/STFOOD
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

typedef struct street_food {
    int tot_stores;
    int price;
    int tot_customers;
} street_food_t;

int main(void) {
    FAST_IO(0);
    int test;
    std :: cin >> test;
    while(test--) {
        int n;
        std :: cin >> n;
        std :: vector <street_food_t> food_detail(n);
        ll_t max_profit = 0;
        for(int i = 0; i < n; ++i) {
            std :: cin >> food_detail[i].tot_stores >> food_detail[i].tot_customers >> food_detail[i].price;
            ll_t profit_earned = (food_detail[i].price) * (food_detail[i].tot_customers / (1 + food_detail[i].tot_stores));
            max_profit = std :: max(profit_earned, max_profit);
        }
        std :: cout << max_profit << '\n';
    }
    return 0;
}
