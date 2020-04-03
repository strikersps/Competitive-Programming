/*
 * Problem Statement: https://www.spoj.com/status/ns=25690798
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

#include <bits/stdc++.h>

typedef unsigned long long ull_t;
typedef long long ll_t;

#define FAST_IO(value) std :: ios :: sync_with_stdio(value); std :: cin.tie(value)
#define MOD 10000000007 // Constant (prime number) used in most competitive programming problems to reduce the answer to a 32-bit integer.
#define PI 3.141592653589793 // Number of digits(15) of Pi which JPL uses for Interplanetary Caculations.
#define GOLDEN_RATIO 1.618033988749895 // Number of digits(15).

static ll_t compute_sum_of_proper_divisors(const ll_t);

int main(void) {
    FAST_IO(0);
    int test;
    std :: cin >> test;
    while(test--) {
        ll_t n;
        std :: cin >> n;
        std :: cout << (n == 1 ? 0 : compute_sum_of_proper_divisors(n)) << std :: endl;
    }
    return 0;
}

static ll_t compute_sum_of_proper_divisors(const ll_t n) {
    ll_t sum_of_divisors = 1;
    for(register ll_t i = 2; i <= (n / i); ++i) {
        if(!(n % i)) {
            if((n / i) == i) {
                sum_of_divisors += i;
            } else {
                sum_of_divisors += (i + (n / i));
            }
        }
    }
    return sum_of_divisors;
}
