/*  Problem Statement: https://www.spoj.com/problems/FIBOSUM/
 *  Author: striker
*/

#include<stdio.h>
#include<stdlib.h>

typedef unsigned long long ull_t;
typedef long long ll_t;

enum matrix_dimensions {nrows = 2, ncols = 2};

#define MOD (1000000000 + 7)
#define MEMORY_ALLOCATION_FAILED_ERROR(variable, bytes) fprintf(stderr, "Line number: %u: Not able to allocate <%lu> bytes of memory to <%s> variable.\n", __LINE__, (bytes), #variable)
#define CONSTRAINTS_OUT_OF_BOUND_ERROR(variable, constraints) fprintf(stderr, "Line nubmer: %u: Constraints not satisfied for <%s> variable i.e. %s\n",  __LINE__, #variable, #constraints)

static ll_t nth_fibonacci(ll_t);
static void matrix_exponentiation(ll_t [][ncols], ll_t);
static void matrix_multiplication(ll_t [][ncols], ll_t [][ncols]);

int main(void) {
    #ifndef ONLINE_JUDGE
        freopen("test-cases/test-case-1.in", "r", stdin);
        freopen("test-cases/test-case-1.out", "w", stdout);
    #endif
    int test;
    scanf("%d", &test);
    if(test < 1 || test > 1000) {
        CONSTRAINTS_OUT_OF_BOUND_ERROR(test, 1 <= test <= 1000);
        exit(0);
    }
    while(test--) {
        int n, m;
        scanf("%d%d", &n, &m);
        if(n < 0 || n > 1000000000) {
            CONSTRAINTS_OUT_OF_BOUND_ERROR(n, 0 <= n <= 10^9);
            exit(0);
        }
        if(m < 0 || m > 1000000000) {
            CONSTRAINTS_OUT_OF_BOUND_ERROR(m, 0 <= m <= 10^9);
            exit(0);
        }
        if(n > m) {
            CONSTRAINTS_OUT_OF_BOUND_ERROR(n < m, n should be less than m);
            exit(0);
        }
        if(!(n == m)) {
            ll_t fibo_sum = ((nth_fibonacci(m + 2) - 1) - (nth_fibonacci((n - 1) + 2) - 1)) % MOD;
            if(fibo_sum < 0) {
                fibo_sum += MOD;
            }
            printf("%lld\n", fibo_sum);
        } else {
            printf("%lld\n", nth_fibonacci(n) % MOD);
        }
    }
    return EXIT_SUCCESS;
}

static ll_t nth_fibonacci(ll_t n) {
    if(!n) {
        return 0;
    } else if(1 == n) {
        return 1;
    }
    ll_t result_matrix[][ncols] = {{1, 0}, {0, 1}}; //Identity Matrix.
    matrix_exponentiation(result_matrix, n - 1);
    return result_matrix[0][0];
}

static void matrix_exponentiation(ll_t result_matrix[][ncols], ll_t n) {
    ll_t transformation_matrix[][ncols] = {{1, 1}, {1, 0}}; // Transformation Matrix.
    while(n) {
        if(n & 1) {
            matrix_multiplication(result_matrix, transformation_matrix);
        }
        matrix_multiplication(transformation_matrix, transformation_matrix);
        n >>= 1;
    }
}

static void matrix_multiplication(ll_t matrix_A[][ncols], ll_t matrix_B[][ncols]) {
    ll_t a = ((matrix_A[0][0] * matrix_B[0][0]) % MOD + (matrix_A[0][1] * matrix_B[1][0]) % MOD) % MOD;
    ll_t b = ((matrix_A[0][0] * matrix_B[0][1]) % MOD + (matrix_A[0][1] * matrix_B[1][1]) % MOD) % MOD;
    ll_t c = ((matrix_A[1][0] * matrix_B[0][0]) % MOD + (matrix_A[1][1] * matrix_B[1][0]) % MOD) % MOD;
    ll_t d = ((matrix_A[1][0] * matrix_B[0][1]) % MOD + (matrix_A[1][1] * matrix_B[1][1]) % MOD) % MOD;
    matrix_A[0][0] = a;
    matrix_A[0][1] = b;
    matrix_A[1][0] = c;
    matrix_A[1][1] = d;
}
