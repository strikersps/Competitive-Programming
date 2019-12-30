/*  Problem Statement: https://www.codechef.com/problems/AVISKR02
 *  Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>

typedef unsigned long long ull_t;
typedef long long ll_t;

#define MOD 1000000007
#define CONSTRAINTS_OUT_OF_BOUND_ERROR(variable, constraints) fprintf(stderr, "Line number: %u: Constraints not satisfied for the variable <%s> i.e. %s\n", __LINE__, #variable, #constraints)

enum {nrows = 2, ncols = 2};

static ull_t nth_fibonacci(ull_t);
static void matrix_exponentiation(ull_t [][ncols], ull_t);
static void matrix_multiplication(ull_t [][ncols], ull_t [*][*]);

int main(void) {
    int test;
    scanf("%d", &test);
    if(test < 1 || test > 40000) {
        CONSTRAINTS_OUT_OF_BOUND_ERROR(test, 1 <= test <= 40000);
        exit(0);
    }
    while(test--) {
        ull_t n;
        scanf("%llu", &n);
        printf("%llu\n", !n ? 0 : (nth_fibonacci((n << 1) - 1) * (nth_fibonacci(n << 1) % MOD)) % MOD);
    }
    return EXIT_SUCCESS;
}


static ull_t nth_fibonacci(ull_t n) {
    if(!n) {
        return 0;
    }
    ull_t result_matrix[][ncols] = {{1, 0}, {0, 1}};
    matrix_exponentiation(result_matrix, n);
    return result_matrix[0][0];
}

static void matrix_exponentiation(ull_t result_matrix[][2], ull_t n) {
    if(n > 1) {
        ull_t transformation_matrix[][ncols] = {{1, 1}, {1, 0}};
        while(n) {
            if(n & 1) {
                matrix_multiplication(result_matrix, transformation_matrix);
            }
            matrix_multiplication(transformation_matrix, transformation_matrix);
            n >>= 1;
        }
    }
}

static void matrix_multiplication(ull_t matrix_A[][ncols], ull_t matrix_B[][ncols]) {
    ull_t a = ((matrix_A[0][0] * matrix_B[0][0]) % MOD + (matrix_A[0][1] * matrix_B[1][0])) % MOD;
    ull_t b = ((matrix_A[0][0] * matrix_B[0][1]) % MOD + (matrix_A[0][1] * matrix_B[1][1])) % MOD;
    ull_t c = ((matrix_A[1][0] * matrix_B[0][0]) % MOD + (matrix_A[1][1] * matrix_B[1][0])) % MOD;
    ull_t d = ((matrix_A[1][0] * matrix_B[0][1]) % MOD + (matrix_A[1][1] * matrix_B[1][1])) % MOD;
    matrix_A[0][0] = a;
    matrix_A[0][1] = b;
    matrix_A[1][0] = c;
    matrix_A[1][1] = d;
}
