/*
 * Problem Statement: https://www.codechef.com/LRNDSA02/problems/INPSTFIX
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

static int compute_operator_priority(const char &);
static void compute_postfix_expression(const std :: string &);

int main(void) {
    FAST_IO(0);
    int test;
    std :: cin >> test;
    while(test--) {
        int n;
        std :: cin >> n;
        std :: string infix_expression;
        std :: cin >> infix_expression;
        compute_postfix_expression(infix_expression);
    }
    return 0;
}

static int compute_operator_priority(const char & optr) {
    int priority = 0;
    switch(optr) {
        case '^':
            priority = 3;
            break;
        case '/':
        case '*':
            priority = 2;
            break;
        case '-':
        case '+':
            priority = 1;
    }
    return priority;
}

static void compute_postfix_expression(const std :: string & infix_expression) {
    std :: stack <char> operators; // Store the operators in the expression in LIFO manner.
    std :: string postfix_expression;
    for(auto & ops: infix_expression) {
        if(ops == '(') {
            operators.push(ops);
            continue;
        }
        if(ops == '+' || ops == '-' || ops == '*' || ops == '/' || ops == '^') {
            while(!operators.empty() && (compute_operator_priority(operators.top()) >= compute_operator_priority(ops))) {
                postfix_expression += operators.top();
                operators.pop();
            }
            operators.push(ops);
            continue;
        }
        if(ops == ')') {
            while(operators.top() != '(') {
                postfix_expression += operators.top();
                operators.pop();
            }
            operators.pop();
            continue;
        }
        postfix_expression += ops;
    }
    while(!operators.empty()) {
        postfix_expression += operators.top();
        operators.pop();
    }
    std :: cout << postfix_expression << std :: endl;
}
