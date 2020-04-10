/*
 * Problem Statement: https://www.hackerrank.com/challenges/leonardo-and-prime/problem
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

static void generate_prefix_prime_product(std :: vector <ull_t> &, const int);
static bool check_prime(const int);

int main(void) {
    FAST_IO(0);
    std :: vector <ull_t> prefix_prime_product;
    generate_prefix_prime_product(prefix_prime_product, 55);
    int test;
    std :: cin >> test;
    while(test--) {
        ll_t n;
        std :: cin >> n;
        auto itr = std :: lower_bound(prefix_prime_product.begin(), prefix_prime_product.end(), n);
        size_t index = itr - prefix_prime_product.begin();
        if(std :: binary_search(prefix_prime_product.begin(), prefix_prime_product.end(), n)) {
            std :: cout << 1 + index << std :: endl;
            continue;
        }
        std :: cout << index << std :: endl;
    }
    return 0;
}

static bool check_prime(const int n) {
    if(n == 2 || n == 3) {
        return true;
    }
    if(n == 1 || !(n % 2) || !(n % 3)) {
        return false;
    }
    bool is_prime = true;
    for(int i = 5; i <= (n / i); ++i) {
        if(!(n % i)) {
            is_prime = false;
            break;
        }
    }
    return is_prime;
}

static void generate_prefix_prime_product(std :: vector <ull_t> & prefix_prime_product, const int limit) {
    ull_t prime_product = 1;
    for(int i = 1; i <= limit; ++i) {
        if(check_prime(i)) {
            prime_product *= i;
            if(prime_product <= 1e18) {
                prefix_prime_product.push_back(prime_product);
                continue;
            }
            break;
        }
    }
}
