/*
 * Problem Statement: https://www.codechef.com/problems/TLG/
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

#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

/* START of CODE-TEMPLATE */

typedef unsigned long long ull_t;
typedef long long ll_t;

#define FAST_IO(value) std :: ios :: sync_with_stdio(value); std :: cin.tie(NULL)
#define MOD 1000000007 // Constant (prime number) used in most competitive programming problems to reduce the answer to a 32-bit integer.
#define PI 3.141592653589793 // Number of digits(15) of Pi which JPL uses for Interplanetary Caculations.
#define GOLDEN_RATIO 1.618033988749895 // Number of digits(15).

#define COMPUTE_GCD(a, b) std :: __gcd((a), (b))
#define COMPUTE_LCM(a, b) (a * ((b) / COMPUTE_GCD(a, b)))

// C and C++ % operator is not a modular arithmethic operator rather its a remainder operator which gives remainder when a / b;
// Refer: https://stackoverflow.com/questions/11720656/modulo-operation-with-negative-numbers
ll_t compute_mod(ll_t a, ll_t b) {
    assert(b != 0); // Modulus is not defined when denominator is zero.
    ll_t rem = a % b;
    return rem < 0 ? b + rem : rem;
}

/* END of CODE-TEMPLATE */

static std :: pair <int, int> find_winner(const int);

int main(void) {
    FAST_IO(0);
    int total_rounds;
    std :: cin >> total_rounds;
    std :: pair <int, int> winner = find_winner(total_rounds);
    std :: cout << winner.first << " " << winner.second << std :: endl;
    return 0;
}

static std :: pair <int, int> find_winner(const int total_rounds) {
    ll_t cumulative_score_p1 = 0, cumulative_score_p2 = 0;
    int max_lead = 0, player_id = 1;
    for(int i = 0; i < total_rounds; ++i) {
        int p1_score, p2_score, lead_score;
        std :: cin >> p1_score >> p2_score;
        cumulative_score_p1 += p1_score;
        cumulative_score_p2 += p2_score;
        if(cumulative_score_p1 > cumulative_score_p2) {
            lead_score = cumulative_score_p1 - cumulative_score_p2;
            if(lead_score > max_lead) {
                max_lead = lead_score;
                player_id = 1;
            }
        } else {
            lead_score = cumulative_score_p2 - cumulative_score_p1;
            if(lead_score > max_lead) {
                max_lead = lead_score;
                player_id = 2;
            }
        }
    }
    return {player_id, max_lead};
}
