/*
 * Problem Statement: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d83dc
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

#define MAX_LIMIT 1000000000LL

static ll_t compute_modulo(const ll_t &, const ll_t &);
static void move_robot(std :: pair <ll_t, ll_t> &, const char);
static std :: pair <ll_t, ll_t> compute_final_position_robot(const std :: string &);

int main(void) {
    FAST_IO(0);
    int test;
    std :: cin >> test;
    for(int t = 1; t <= test; ++t){
        std :: string command;
        std :: cin >> command;
        std :: pair <ll_t, ll_t> robot_final_pos = compute_final_position_robot(command);
        std :: cout << "Case #" << t << ": " << robot_final_pos.first << " " << robot_final_pos.second << std :: endl;
    }
    return 0;
}

static ll_t compute_modulo(const ll_t & dividend, const ll_t & divisor) {
    ll_t remainder = dividend % divisor;
    return remainder < 0 ? remainder + divisor : remainder;
}

static void move_robot(std :: pair <ll_t, ll_t> & robot_loc, const char direction) {
    switch(direction) {
        case 'N': {
            robot_loc.second -= 1LL;
        }
        break;
        case 'S': {
            robot_loc.second += 1LL;
        }
        break;
        case 'E': {
            robot_loc.first += 1LL;
        }
        break;
        case 'W': {
            robot_loc.first -= 1LL;
        }
    }
}

static std :: pair <ll_t, ll_t> compute_final_position_robot(const std :: string & command) {
    std :: stack <std :: pair <ll_t, std :: pair <ll_t, ll_t>>> repeat_command;
    std :: pair <ll_t, ll_t> pos_change = {0, 0}; // (dx, dy)
    for(size_t i = 0; i < command.size(); ++i) {
        if(command[i] == '(') {
            pos_change = {0, 0};
            continue;
        }
        if(command[i] >= '2' && command[i] <= '9') {
            repeat_command.push(std :: make_pair(command[i] - '0', pos_change));
            continue;
        }
        if(command[i] == ')') {
            std :: pair <ll_t, std :: pair <ll_t, ll_t>> & top_data = repeat_command.top();
            pos_change.first = compute_modulo(compute_modulo(pos_change.first, MAX_LIMIT) * compute_modulo(top_data.first, MAX_LIMIT), MAX_LIMIT);
            pos_change.second = compute_modulo(compute_modulo(pos_change.second, MAX_LIMIT) * compute_modulo(top_data.first, MAX_LIMIT), MAX_LIMIT);
            pos_change.first += (top_data.second.first);
            pos_change.second += (top_data.second.second);
            repeat_command.pop();
            continue;
        }
        move_robot(pos_change, command[i]);
    }
    pos_change.first = compute_modulo(1 + pos_change.first, MAX_LIMIT);
    pos_change.second = compute_modulo(1 + pos_change.second, MAX_LIMIT);
    if(!pos_change.first) {
        pos_change.first = MAX_LIMIT;
    }
    if(!pos_change.second) {
        pos_change.second = MAX_LIMIT;
    }
    return pos_change;
}
