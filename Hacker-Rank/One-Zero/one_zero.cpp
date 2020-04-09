/*
 * Problem Statement: https://www.hackerrank.com/contests/mnnit-opc-2k20-2-0/challenges/one-zero-2
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
#include <cstring>
#include <cmath>

typedef unsigned long long ull_t;
typedef long long ll_t;

#define FAST_IO(value) std :: ios :: sync_with_stdio(value); std :: cin.tie(value)
#define MOD 1000000007 // Constant (prime number) used in most competitive programming problems to reduce the answer to a 32-bit integer.
#define PI 3.141592653589793 // Number of digits(15) of Pi which JPL uses for Interplanetary Caculations.
#define GOLDEN_RATIO 1.618033988749895 // Number of digits(15).

static ll_t compute_maximum_binary_value(char[], const int);

int main(void) {
    FAST_IO(0);
    int n;
    std :: cin >> n;
    char binary_string[n];
    std :: cin >> binary_string;
    std :: cout << compute_maximum_binary_value(binary_string, n) << std :: endl;
    return 0;
}

static ll_t compute_maximum_binary_value(char binary_string[], const int n) {
    char *const updated_binary_string = new char[n << 1];
    std :: memcpy(updated_binary_string, binary_string, n * sizeof(char));
    std :: memcpy(updated_binary_string + n, binary_string, n * sizeof(char));
    int i, pos;
    for(i = n - 1, pos = n; i >=0; --i) {
        if(std :: memcmp(updated_binary_string + i, updated_binary_string + pos, n * sizeof(char)) > 0) {
            pos = i;
        }
    }
    ll_t decimal_equivalent = 0;
    for(i = 0; i < n; ++i) {
        decimal_equivalent = ((decimal_equivalent << 1LL) + updated_binary_string[pos + i] - '0') % MOD;
    }
    delete updated_binary_string;
    return decimal_equivalent;
}
