/*
 * Problem Statement: Program to do multiplication of matrices.
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
#include <iomanip>
#include <cmath>
#include <cstdio>

typedef unsigned long long ull_t;
typedef long long ll_t;

#define FAST_IO(value) std :: ios :: sync_with_stdio(value); std :: cin.tie(NULL)
#define MOD 1000000007 // Constant (prime number) used in most competitive programming problems to reduce the answer to a 32-bit integer.
#define PI 3.141592653589793 // Number of digits(15) of Pi which JPL uses for Interplanetary Caculations.
#define GOLDEN_RATIO 1.618033988749895 // Number of digits(15).

static void take_input_matrix(std :: vector <std :: vector<int>> &);
static void initialize_matrix(std :: vector <std :: vector <int>> &);
static void display_matrix(const std :: vector <std :: vector <int>> &);
static std :: vector <std :: vector<int>> & matrix_multiplication(const std :: vector <std :: vector <int>> &, const std :: vector <std :: vector <int>> &);

int main(void) {
    FAST_IO(0);
    int nrows, ncols; // Represents the dimensions of matrix A (nrows * ncols).
    std :: cin >> nrows >> ncols; // Take input for matrix A dimensions.
    std :: vector <std :: vector <int>> matrix_A(nrows, std :: vector <int> (ncols, 0));
    take_input_matrix(matrix_A);
    std :: cout << "Matrix-A:" << std :: endl;
    display_matrix(matrix_A);
    int mrows, mcols; // Represents the dimensiosn of the matrx B (mrows * mcols).
    std :: cin >> mrows >> mcols; // Take input for matrix B dimension.
    std :: vector <std :: vector <int>> matrix_B(mrows, std :: vector <int> (mcols, 0));
    take_input_matrix(matrix_B);
    std :: cout << "Matrix-B:" << std :: endl;
    display_matrix(matrix_B);
    if(ncols != mrows) {
        std :: cout << "Invalid Matrix Dimensions. i.e. For matrix multiplication, Number of Columns in matrix A = Number of Rows in matrix B" << std :: endl;
        exit(0);
    }
    std :: vector <std :: vector <int>> & result_matrix = matrix_multiplication(matrix_A, matrix_B);
    std :: cout << "Result-Matrix:" << std :: endl;
    display_matrix(result_matrix);
    return 0;
}

static void take_input_matrix(std :: vector <std :: vector <int>> & matrix) {
    for(size_t i = 0; i < matrix.size(); ++i) {
        for(size_t j = 0; j < matrix[i].size(); ++j) {
            std :: cin >> matrix[i][j];
        }
    }
}

static void display_matrix(const std :: vector <std :: vector <int>> & matrix) {
    for(size_t i = 0; i < matrix.size(); ++i) {
        std :: cout << std :: setw(5) << matrix[i][0];
        for(size_t j = 1; j < matrix[i].size(); ++j) {
            std :: cout << std :: setw(5) << matrix[i][j];
        }
        std :: cout << std :: endl;
    }
}

static void initialize_matrix(std :: vector <std :: vector <int>> & matrix) {
    for(size_t i = 0; i < matrix.size(); ++i) {
        for(size_t j = 0; j < matrix[0].size(); ++j) {
            matrix[i][j] = 0;
        }
    }
}

static std :: vector <std :: vector <int>> & matrix_multiplication(const std :: vector <std :: vector <int>> & matrix_A, const std :: vector <std :: vector <int>> & matrix_B) {
    size_t rrows, rcols; // Represents the dimensions of the result matrix (rrows * rcols).
    rrows = matrix_A.size();
    rcols = matrix_B[0].size();
    static std :: vector <std :: vector <int>> result_matrix(rrows, std :: vector <int> (rcols));
    initialize_matrix(result_matrix);
    for(size_t i = 0; i < rrows; ++i) {
        for(size_t j = 0; j < rcols; ++j) {
            for(size_t k = 0; k < matrix_A[0].size(); ++k) {
                result_matrix[i][j] += (matrix_A[i][k] * matrix_B[k][j]);
            }
        }
    }
    return result_matrix;
}
