/*
 * Problem Statement: https://www.hackerrank.com/challenges/cpp-maps/problem
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

int main(void) {
    FAST_IO(0);
    int tot_queries;
    std :: cin >> tot_queries;
    std :: map<std :: string, int> student_marksheet;
    while(tot_queries--) {
        int option;
        std :: cin >> option;
        std :: string student_name;
        std :: cin >> student_name;
        switch(option) {
            case 1: {
                int student_marks;
                std :: cin >> student_marks;
                if(student_marksheet.find(student_name) == student_marksheet.end()) {
                    student_marksheet.insert(std :: make_pair(student_name, student_marks));
                } else {
                    student_marksheet[student_name] += student_marks;
                }
            }
                break;
            case 2: {
                student_marksheet.erase(student_name);
            }
                break;
            case 3: {
                std :: map<std :: string, int> :: iterator itr = student_marksheet.find(student_name);
                if(itr != student_marksheet.end()) {
                    std :: cout << itr->second << std :: endl;
                } else {
                    std :: cout << 0 << std :: endl;
                }
            }
        }
    }
    return 0;
}
