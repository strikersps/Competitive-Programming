/*
 * Problem Statement: https://www.spoj.com/problems/COMDIV/
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

#define FAST_IO(value) std :: ios :: sync_with_stdio(value); std :: cin.tie(value); std :: cout.tie(value)
#define MOD 10000000007 // Constant (prime number) used in most competitive programming problems to reduce the answer to a 32-bit integer.
#define PI 3.141592653589793 // Number of digits(15) of Pi which JPL uses for Interplanetary Caculations.
#define GOLDEN_RATIO 1.618033988749895 // Number of digits(15).

#define READ_ERROR(return_val) std :: cerr << "Line number: " << __LINE__ << ": scanf() read error!" << std :: endl << "Expected-Return-Value: " << return_val << std :: endl; exit(0);

static int compute_gcd(const int, const int);
static int compute_total_divisors(const int);

/*
 * NOTE: In this program if you use cin and cout then you will TLE, beacause of that I used scanf() and printf().
*/

int main(void) {
    FAST_IO(0);
    int test;
    // std :: cin >> test;
    if(1 != scanf("%d", &test)) {
        READ_ERROR(1);
    }
    while(test--) {
        int a, b;
        if(2 == scanf("%d%d", &a, &b)) {
            // std :: cin >> a >> b;
            // std :: cout << compute_total_divisors(compute_gcd(a, b)) << std :: endl;
            printf("%d\n", compute_total_divisors(compute_gcd(a, b)));
            continue;
        }
        READ_ERROR(2);
    }
    return 0;
}

static int compute_gcd(const int a, const int b) {
    if(!b) {
        return a;
    }
    if(!a) {
        return b;
    }
    return compute_gcd(b, a % b);
}

static int compute_total_divisors(const int n) {
    int total_divisors = 0;
    for(register int i = 1; i <= (n / i); ++i) {
        if(!(n % i)) {
            if((n / i) != i) {
                total_divisors += 2;
            } else {
                ++total_divisors;
            }
        }
    }
    return total_divisors;
}
