/*
 * Problem Statement: https://www.codechef.com/LRNDSA02/problems/ZCO12001
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
#include <string>
#include <numeric>
#include <algorithm>
#include <cmath>

typedef unsigned long long ull_t;
typedef long long ll_t;

#define FAST_IO(value) std :: ios :: sync_with_stdio(value); std :: cin.tie(NULL)
#define MOD 1000000007 // Constant (prime number) used in most competitive programming problems to reduce the answer to a 32-bit integer.
#define PI 3.141592653589793 // Number of digits(15) of Pi which JPL uses for Interplanetary Caculations.
#define GOLDEN_RATIO 1.618033988749895 // Number of digits(15).

const int answer_size = 4;
static std :: vector <int> & compute_answer(const std :: vector <int> &, const int);

int main(void) {
    FAST_IO(0);
    int n;
    std :: cin >> n;
    std :: vector <int> bracket_sequence(n, 0);
    for(int & number: bracket_sequence) {
        std :: cin >> number;
    }
    std :: vector <int> & answer = compute_answer(bracket_sequence, n);
    for(const auto & ans : answer) {
        std :: cout << ans << " ";
    }
    std :: cout << std :: endl;
    return 0;
}

static std :: vector <int> & compute_answer(const std :: vector <int> & bracket_sequence, const int n) {
    static std :: vector <int> answer(answer_size, 0);
    int open_count, bracket_count;
    open_count = bracket_count = 0;
    for(int i = 0; i < n; ++i) {
        ++bracket_count;
        if(bracket_sequence[i] == 1) {
            ++open_count;
            continue;
        }
        if(bracket_sequence[i] == 2) {
            if(open_count > answer[0]) {
                answer[0] = open_count;
                answer[1] = i;
            }
            --open_count;
            if(!open_count) {
                if(bracket_count > answer[2]) {
                    answer[2] = bracket_count;
                    answer[3] = ((i + 1) - bracket_count) + 1;
                }
                bracket_count = 0;
            }
        }
    }
    return answer;
}

