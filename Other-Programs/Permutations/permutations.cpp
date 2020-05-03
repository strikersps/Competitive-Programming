/*
 * Problem Statement: https://cses.fi/problemset/task/1070
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
#include <cstring>
#include <cassert>

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

static void generate_beautiful_permutation(const int);

int main(void) {
    FAST_IO(0);
    int n;
    std :: cin >> n;
    if(n == 1) {
        std :: cout << 1 << std :: endl;
    } else if(n < 4) {
        std :: cout << "NO SOLUTION" << std :: endl;
    } else {
        generate_beautiful_permutation(n);
    }
    return 0;
}

static void generate_beautiful_permutation(const int n) {
    std :: unordered_set <int> encountered_numbers;
    std :: vector <int> beautiful_permutation(n);
    beautiful_permutation[0] = n - 1;
    encountered_numbers.insert(n - 1);
    for(int i = 1; i < n; ++i) {
        for(int j = 2; j < n; ++j) {
            int v1 = beautiful_permutation[i - 1] + j;
            int v2 = beautiful_permutation[i - 1] - j;
            if(v1 > n) {
                if(encountered_numbers.count(v2)) {
                    continue;
                }
                beautiful_permutation[i] = v2;
                encountered_numbers.insert(v2);
                break;
            } else if(v2 < 1) {
                if(encountered_numbers.count(v1)) {
                    continue;
                }
                beautiful_permutation[i] = v1;
                encountered_numbers.insert(v1);
                break;
            } else {
                if(encountered_numbers.count(v1) && encountered_numbers.count(v2)) {
                    continue;
                } else {
                    if(encountered_numbers.count(v1)) {
                        beautiful_permutation[i] = v2;
                    } else if(encountered_numbers.count(v2)) {
                        beautiful_permutation[i] = v1;
                    } else {
                        beautiful_permutation[i] = v1;
                    }
                    encountered_numbers.insert(beautiful_permutation[i]);
                    break;
                }
            }
        }
    }
    for(const int & number: beautiful_permutation) {
        std :: cout << number << " ";
    }
    std :: cout << std :: endl;
}
