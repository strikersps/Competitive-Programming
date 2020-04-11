/*
 * Problem Statement: https://www.codechef.com/problems/SMRITI/
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

static bool check_palindrome_possible(const std :: string &, const int);

int main(void) {
    FAST_IO(0);
    int test;
    std :: cin >> test;
    while(test--) {
        std :: string read_string;
        std :: cin >> read_string;
        int k;
        std :: cin >> k;
        std :: cout << (check_palindrome_possible(read_string, k) ? "YES" : "NO") << std :: endl;
    }
    return 0;
}

#define MAX_NUMBER_OF_ALPHABETS 26

static bool check_palindrome_possible(const std :: string & read_string, const int k) {
    size_t string_len = read_string.size();
    if(string_len % k) {
        return false;
    }
    std :: vector <int> freq_map(MAX_NUMBER_OF_ALPHABETS, 0);
    for(const auto & character : read_string) {
        ++freq_map[character - 'a'];
    }
    int odd_count = 0;
    for(const auto & frequency: freq_map) {
        if(frequency % 2) {
            ++odd_count;
        }
    }
    if(!((string_len / k) % 2)) {
        if(!odd_count) {
            return true;
        }
        return false;
    }
    if(odd_count <= k) {
        return true;
    }
    return false;
}
