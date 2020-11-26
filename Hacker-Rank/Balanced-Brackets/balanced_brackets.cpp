/*
 * Problem Statement: https://www.hackerrank.com/challenges/balanced-brackets/problem
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

static bool check_balance_bracket(const std :: string &);

int main(void) {
    FAST_IO(0);
    int test;
    std :: cin >> test;
    while(test--) {
        std :: string bracket_sequence;
        std :: cin >> bracket_sequence;
        std :: cout << (check_balance_bracket(bracket_sequence) ? "YES" : "NO") << std :: endl;
    }
    return 0;
}

static bool check_balance_bracket(const std :: string & bracket_sequence) {
    std :: stack <char> track_bracket_type;
    bool is_balance = true;
    for(const auto & bracket: bracket_sequence) {
        if(bracket == '(' || bracket == '[' || bracket == '{') {
            track_bracket_type.push(bracket);
            continue;
        }
        if(track_bracket_type.empty() || (bracket == ')' && track_bracket_type.top() != '(') || (bracket == ']' && track_bracket_type.top() != '[') || (bracket == '}' && track_bracket_type.top() != '{')) {
            is_balance = false;
            break;
        }
        track_bracket_type.pop();
    }
    if(!track_bracket_type.empty()) {
        is_balance = false;
    }
    return is_balance;
}
