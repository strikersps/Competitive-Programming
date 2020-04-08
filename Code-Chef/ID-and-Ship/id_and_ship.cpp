/*
 * Problem Statement: https://www.codechef.com/problems/FLOW010/
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
#include <map>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <string>

typedef unsigned long long ull_t;
typedef long long ll_t;

#define FAST_IO(value) std :: ios :: sync_with_stdio(value); std :: cin.tie(value)
#define MOD 1000000007 // Constant (prime number) used in most competitive programming problems to reduce the answer to a 32-bit integer.
#define PI 3.141592653589793 // Number of digits(15) of Pi which JPL uses for Interplanetary Caculations.
#define GOLDEN_RATIO 1.618033988749895 // Number of digits(15).

int main(void) {
    FAST_IO(0);
    std :: map <char, std :: string> data;
    data.insert(std :: pair <char, std :: string> ('B', "BattleShip"));
    data.insert(std :: pair <char, std :: string> ('C', "Cruiser"));
    data.insert(std :: pair <char, std :: string> ('D', "Destroyer"));
    data.insert(std :: pair <char, std :: string> ('F', "Frigate"));
    int test;
    std :: cin >> test;
    while(test--) {
        char data_id;
        std :: cin >> data_id;
        const auto & itr = data.find(toupper(data_id));
        if(itr != data.end()) {
            std :: cout << itr->second << std :: endl;
        }
    }
    return 0;
}
