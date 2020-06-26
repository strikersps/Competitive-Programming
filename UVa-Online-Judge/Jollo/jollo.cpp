/*
 * Problem Statement: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3399s
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

/*START OF CODE-TEMPLATE*/

typedef unsigned long long ull_t;
typedef long long ll_t;

#define FAST_IO(value) std :: ios :: sync_with_stdio(value); std :: cin.tie(NULL); std :: cout.tie(NULL)

#define MOD 1000000007 // Constant (prime number) used in most competitive programming problems to reduce the answer to a 32-bit integer.
#define PI 3.141592653589793 // Number of digits(15) of Pi which JPL uses for Interplanetary Caculations.
#define GOLDEN_RATIO 1.618033988749895 // Number of digits(15).
#define INF_32_BIT_US_INT 0xFFFFFFFF // Maximum value which can be stored in an unsigned int (32-Bit).
#define INF_64_BIT_US_INT 0xFFFFFFFFFFFFFFFF // Maximum value which can be stored in an unsigned long long (64-Bit).
#define NEW_LINE '\n' // Created because sometimes std :: endl makes the code slower due to clearance of buffer after printing new-line.

#define COMPUTE_GCD(a, b) std :: __gcd((a), (b))
#define COMPUTE_LCM(a, b) (a * ((b) / COMPUTE_GCD(a, b)))

// C and C++ "%" operator is not a modular arithmetic operator rather it's a remainder operator which gives remainder when a / b.
// Implementation is based on the fact that a % b = a - (b * (a / b)), where a = dividend, b = divisor, a / b = quotient.
// Refer: https://stackoverflow.com/questions/11720656/modulo-operation-with-negative-numbers
// Time Complexity: O(1).
ll_t compute_mod(ll_t a, ll_t b) {
    assert(b > 0); // Denominator must be positive.
    ll_t rem = a % b;
    return rem < 0 ? b + rem : rem;
}

// The function computes the total number of divisors for the given n. i.e. d(n).
// Time-Complexity: O(sqrt(n)).
ll_t compute_total_divisors(ll_t n) {
    ll_t total_divisors = 0;
    for(ll_t i = 1; i <= (n / i); ++i) {
        if(!(n % i)) {
            if((n / i) == i) {
                ++total_divisors;
                continue;
            }
            total_divisors += 2;
        }
    }
    return total_divisors;
}

// The code computes whether the given number (n) is a perfect square or not based on the fact that, a number is a perfect square if it has odd number of divisors.
// Refer: https://math.stackexchange.com/questions/906159/a-number-is-a-perfect-square-if-and-only-if-it-has-odd-number-of-positive-diviso
// Time-Complexity: O(sqrt(n)).
bool check_perfect_sequare(ll_t n) {
    return compute_total_divisors(n) % 2 ? true : false;
}

// Computes the number of set-bits in the binary representation of n (64-Bit).
#define COMPUTE_SET_BITS(number) __builtin_popcountll(number)

// Computes the parity of the number n (64-Bit) i.e. parity is 0 if the number of set-bits is even otherwise odd.
#define COMPUTE_PARITY(number) __builtin_parity(number)

// Computes the number of leading zeroes in the binary representation of n (64-Bit). The value will be 64 - (number of bits required to represent n).
#define COMPUTE_LEADING_ZEROES(number) __builtin_clzll(number)

// Computes the number of trailing zeroes in the binary representation of n (64-Bit). The value will always be zeroe if n is odd.
#define COMPUTE_TRAILING_ZEROES(number) __builtin_ctzll(number)

/*END-OF CODE-TEMPLATE*/

static int select_princess_card(std :: vector <int> &, std :: vector <bool> &, const int);
static int compute_lowest_card_to_deal(std :: vector <int> &, std :: vector <int> &);

int main(void) {
    FAST_IO(0);
    while(true) {
        std :: vector <int> princess_cards(3, 0), prince_cards(2, 0);
        for(int & card_value: princess_cards) {
            std :: cin >> card_value;
        }
        for(int & card_value: prince_cards) {
            std :: cin >> card_value;
        }
        if(princess_cards[0] == 0 && princess_cards[1] == 0 && princess_cards[2] == 0 && prince_cards[0] == 0 && prince_cards[1] == 0) {
            break;
        }
        std :: cout << compute_lowest_card_to_deal(princess_cards, prince_cards) << NEW_LINE;
    }
    return 0;
}

static int select_princess_card(std :: vector <int> & princess_cards, std :: vector <bool> & used_princess_cards, const int prince_card_number) {
    int i = 0, princess_card_number = 0;
    for(; i < (int) princess_cards.size(); ++i) {
        if(!used_princess_cards[i] && princess_cards[i] > prince_card_number) {
            used_princess_cards[i] = true;
            princess_card_number = princess_cards[i];
            break;
        }
    }
    if(i == (int) princess_cards.size()) {
        for(int j = 0; j < (int) princess_cards.size(); ++j) {
            if(!used_princess_cards[j]) {
                used_princess_cards[j] = true;
                princess_card_number = princess_cards[j];
                break;
            }
        }
    }
    return princess_card_number;
}

static int compute_lowest_card_to_deal(std :: vector <int> & princess_cards, std :: vector <int> & prince_cards) {
    std :: vector <bool> used_cards_princess(3, false), used_cards_prince(2, false);
    std :: unordered_set <int> cards_used;
    sort(princess_cards.begin(), princess_cards.end());
    sort(prince_cards.begin(), prince_cards.end());
    int prince_card_number, princess_card_number, princess_round_win_count = 0, prince_round_win_count = 0;
    for(int round_number = 1; round_number < 3; ++round_number) {
        prince_card_number = round_number == 1 ? prince_cards[1] : prince_cards[0];
        round_number == 1 ? used_cards_prince[1] : used_cards_prince[0];
        cards_used.insert(prince_card_number);
        princess_card_number = select_princess_card(princess_cards, used_cards_princess, prince_card_number);
        princess_card_number > prince_card_number ? ++princess_round_win_count : ++prince_round_win_count;
        cards_used.insert(princess_card_number);
    }
    if(princess_round_win_count == 2) {
        return -1;
    }
    if(prince_round_win_count == 2) {
        cards_used.insert(!used_cards_princess[0] ? princess_cards[0] : !used_cards_princess[1] ? princess_cards[1] : princess_cards[2]);
        for(prince_card_number = 1; cards_used.count(prince_card_number); ++prince_card_number);
        return prince_card_number;
    }
    princess_card_number = !used_cards_princess[0] ? princess_cards[0] : !used_cards_princess[1] ? princess_cards[1] : princess_cards[2];
    for(prince_card_number = princess_card_number + 1; cards_used.count(prince_card_number); ++prince_card_number);
    return prince_card_number > 52 ? -1 : prince_card_number;
}
