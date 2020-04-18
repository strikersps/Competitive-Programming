/*
 * Problem Statement: https://www.hackerrank.com/challenges/ctci-queue-using-two-stacks/problem
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

static void stack_implementation(void);

int main(void) {
    FAST_IO(0);
    stack_implementation();
    return 0;
}

static void stack_implementation(void) {
    int tot_query;
    std :: cin >> tot_query;
    std :: stack <int> enque_stack, extract_stack;
    while(tot_query--) {
        int option;
        std :: cin >> option;
        switch(option) {
            case 1: {
                int value; // value which is going to be inserted into the queue.
                std :: cin >> value;
                enque_stack.push(value);
                break;
            }
            case 2:
            case 3: {
                if(extract_stack.empty()) {
                    while(!enque_stack.empty()) {
                        extract_stack.push(enque_stack.top());
                        enque_stack.pop();
                    }
                }
                if(option == 2) {
                    extract_stack.pop();
                } else {
                    std :: cout << extract_stack.top() << std :: endl;
                }
                break;
            }
        }
    }
}

