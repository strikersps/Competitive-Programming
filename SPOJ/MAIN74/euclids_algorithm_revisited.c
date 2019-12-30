/*  Problem Statement: https://www.spoj.com/problems/MAIN74/
 *  Author: striker
*/

#include<stdio.h>
#include<stdlib.h>

typedef unsigned long long ull_t;
typedef long long ll_t;

#define MOD (1000000000 + 7)
#define MEMORY_ALLOCATION_FAILED_ERROR(variable, bytes) fprintf(stderr, "Line number: %u: Not able to allocate <%lu> bytes of memory to <%s> variable.\n", __LINE__, (bytes), #variable)
#define CONSTRAINTS_OUT_OF_BOUND_ERROR(variable, constraints) fprintf(stderr, "Line number: %u: Constraints not satisfied for <%s> variable i.e. %s\n", __LINE__, #variable, #constraints)

enum matrix_dimensions {nrows = 2, ncols = 2};

static ull_t nth_fibonacci(ull_t);
static void matrix_multiplication(ull_t [][ncols], ull_t [][ncols]);
static void matrix_exponentiation(ull_t [][ncols], ull_t);

int main(void) {
    int test;
    scanf("%d", &test);
    if(test < 1 || test > 50) {
        CONSTRAINTS_OUT_OF_BOUND_ERROR(test, 1 <= test <= 50);
        exit(0);
    }
    while(test--) {
        ll_t n;
        scanf("%lld", &n);
        if(n < 0 || n > 1000000000000000000) {
            CONSTRAINTS_OUT_OF_BOUND_ERROR(n, 0 <= n <= 10^18);
            exit(0);
        }
        if(n == 0) {
            printf("0\n");
        } else if(n == 1) {
            printf("2\n");
        } else {
            printf("%llu\n", nth_fibonacci(n + 3));
        }
    }
    return EXIT_SUCCESS;
}

static ull_t nth_fibonacci(ull_t n) {
    if(!n) {
        return 0;
    }
    ull_t result_matrix[][ncols] = {{1, 0}, {0, 1}}; // Identity Matrix.
    matrix_exponentiation(result_matrix, n - 1);
    return result_matrix[0][0];
}

static void matrix_exponentiation(ull_t result_matrix[][ncols], ull_t n) {
    if(n > 0) {
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
    ull_t a = ((matrix_A[0][0] * matrix_B[0][0]) % MOD + (matrix_A[0][1] * matrix_B[1][0]) % MOD) % MOD;
    ull_t b = ((matrix_A[0][0] * matrix_B[0][1]) % MOD + (matrix_A[0][1] * matrix_B[1][1]) % MOD) % MOD;
    ull_t c = ((matrix_A[1][0] * matrix_B[0][0]) % MOD + (matrix_A[1][1] * matrix_B[1][0]) % MOD) % MOD;
    ull_t d = ((matrix_A[1][0] * matrix_B[0][1]) % MOD + (matrix_A[1][1] * matrix_B[1][1]) % MOD) % MOD;
    matrix_A[0][0] = a;
    matrix_A[0][1] = b;
    matrix_A[1][0] = c;
    matrix_A[1][1] = d;
}
