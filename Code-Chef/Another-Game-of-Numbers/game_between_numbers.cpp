/*
 * Problem Statement: https://www.codechef.com/CHPTRS01/problems/GAMENUM
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
#include <cmath>

typedef unsigned long long ull_t;
typedef long long ll_t;

#define FAST_IO(value) std :: ios :: sync_with_stdio(value); std :: cin.tie(value)
#define MOD 10000000007 // Constant (prime number) used in most competitive programming problems to reduce the answer to a 32-bit integer.
#define PI 3.141592653589793 // Number of digits(15) of Pi which JPL uses for Interplanetary Caculations.
#define GOLDEN_RATIO 1.618033988749895 // Number of digits(15).

static ll_t compute_right_circular_shift_by_one(ll_t, ll_t);
static void compute_number_of_operations(ll_t, ll_t);

int main(void) {
    FAST_IO(0);
    int test;
    std :: cin >> test;
    while(test--) {
        ll_t a, b;
        std :: cin >> a >> b;
        if(!b) {
            std :: cout << 0 << a << std :: endl;
            continue;
        }
        compute_number_of_operations(a, b);
    }
    return 0;
}

static ll_t compute_right_circular_shift_by_one(ll_t number, ll_t left_shift) {
    ll_t preserved_bits = number & 1;
    return number >> 1 | preserved_bits << left_shift;
}

static void compute_number_of_operations(ll_t a, ll_t b) {
    ll_t left_shift = log2l(std :: max(a, b));
    ll_t updated_b = b;
    ll_t max_xor = a ^ b;
    ll_t operation_count, min_operation_count;
    operation_count = min_operation_count = 0;
    while(true) {
        ++operation_count;
        updated_b = compute_right_circular_shift_by_one(updated_b, left_shift);
        if(updated_b == b) {
            break;
        }
        if(max_xor < (a ^ updated_b)) {
            max_xor = a ^ updated_b;
            min_operation_count = operation_count;
        }
    }
    std :: cout << min_operation_count << " " << max_xor << std :: endl;
}
