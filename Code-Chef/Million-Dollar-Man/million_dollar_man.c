/*  Problem Statement: https://www.codechef.com/NITC2020/problems/MADOMA
 *  Author: striker
*/

#include<stdio.h>
#include<stdlib.h>

typedef unsigned long long ull_t;
typedef long long ll_t;

#define MOD (1000000000 + 7)
#define MEMORY_ALLOCATION_FAILED_ERROR(variable, bytes) fprintf(stderr, "Line number: %u: Not able to allocate <%lu> bytes of memory to <%s> variable.\n", __LINE__, (bytes), #variable)
#define CONSTRAINTS_OUT_OF_BOUND_ERROR(variable, constraints) fprintf(stderr, "Line number: %u: Constraints not satisfied for the <%s> variable, i.e. %s.\n", __LINE__, #variable, #constraints)

enum matrix_dimensions {ncols = 2, nrows = 2};

static ull_t compute_money_earned(const ull_t, const ull_t, const ull_t);
static void matrix_exponentiation(ull_t [][ncols], ull_t);
static void matrix_multiplication(ull_t [][ncols], ull_t [][ncols]);

int main(void) {
    #ifndef ONLINE_JUDGE
        freopen("test-cases/test-case-1.in", "r", stdin);
        freopen("test-cases/test-case-1.out", "w", stdout);
    #endif
    ull_t n;
    scanf("%llu", &n);
    if(n < 1 || n > 1000000000000000000) {
        CONSTRAINTS_OUT_OF_BOUND_ERROR(n, 1 <= n <= 10^18);
        exit(0);
    }
    ull_t a, b;
    scanf("%llu%llu", &a, &b);
    if(a < 1 || a > 1000000000000000000) {
        CONSTRAINTS_OUT_OF_BOUND_ERROR(a, 1 <= a <= 10^18);
        exit(0);
    }
    if(b < 1 || b > 1000000000000000000) {
        CONSTRAINTS_OUT_OF_BOUND_ERROR(b, 1 <= b <= 10^18);
        exit(0);
    }
    printf("%llu\n", compute_money_earned(a, b, n - 1));
    return EXIT_SUCCESS;
}

static ull_t compute_money_earned(const ull_t a, const ull_t b, const ull_t n) {
    ull_t result_matrix[][ncols] = {{1, 0}, {0, 1}}; // Identity Matrix.
    if(n == 0) {
        return a;
    } else if(n == 1) {
        return b;
    }
    matrix_exponentiation(result_matrix, n);
    return ((a * result_matrix[0][0] % MOD) + (b * result_matrix[0][1]) % MOD) % MOD;
}

static void matrix_exponentiation(ull_t matrix[][ncols], ull_t exponent) {
    if(exponent > 1) {
        ull_t transformation_matrix[][ncols] = {{0, 1}, {4, 3}}; // Transformation Matrix.
        while(exponent) {
            if(exponent & 1) {
                matrix_multiplication(matrix, transformation_matrix);
            }
            matrix_multiplication(transformation_matrix, transformation_matrix);
            exponent >>= 1;
        }
    }
}

static void matrix_multiplication(ull_t matrix_A[][ncols], ull_t matrix_B[][ncols]) {
    ull_t a = (((matrix_A[0][0] * matrix_B[0][0]) % MOD) + (matrix_A[0][1] * matrix_B[1][0])) % MOD;
    ull_t b = (((matrix_A[0][0] * matrix_B[0][1]) % MOD) + (matrix_A[0][1] * matrix_B[1][1])) % MOD;
    ull_t c = (((matrix_A[1][0] * matrix_B[0][0]) % MOD) + (matrix_A[1][1] * matrix_B[1][0])) % MOD;
    ull_t d = (((matrix_A[1][0] * matrix_B[0][1]) % MOD) + (matrix_A[1][1] * matrix_B[1][1])) % MOD;
    matrix_A[0][0] = a;
    matrix_A[0][1] = b;
    matrix_A[1][0] = c;
    matrix_A[1][1] = d;
}
