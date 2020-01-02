/*  Problem Statement: https://www.hackerrank.com/contests/projecteuler/challenges/euler002/problem or https://projecteuler.net/problem=2
 *  Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef unsigned long long ull_t;
typedef long long ll_t;

#define MEMORY_ALLOCATION_FAILED_ERROR(variable, bytes) fprintf(stderr, "Line number: %u: Not able to allocate <%lu> bytes of memory to <%s> variable.\n", __LINE__, (bytes), #variable)
#define CONSTRAINTS_OUT_OF_BOUND_ERROR(variable, constraints) fprintf(stderr, "Line number: %u: Constraints not satisfied for the <%s> variable i.e. %s\n", __LINE__, #variable, #constraints)
#define INITIALIZE_DATA(variable, bytes) memset(variable, 0, (bytes))

static ull_t compute_even_fibonacci_sum(const ull_t);

int main(void) {
    /*
    #ifndef ONLINE_JUDGE
        freopen("test-cases/test-case-1.in", "r", stdin);
        freopen("test-cases/test-case-1.out", "w", stdout);
    #endif
    */
    int test;
    scanf("%d", &test);
    if(test < 1 || test > 100000) {
        CONSTRAINTS_OUT_OF_BOUND_ERROR(test, 1 <= test <= 10^5);
        exit(0);
    }
    while(test--) {
        ull_t n;
        scanf("%llu", &n);
        if(n < 1 || n > 40000000000000000) {
            CONSTRAINTS_OUT_OF_BOUND_ERROR(n, 10 <= n <= 4 * 10^16);
            exit(0);
        }
        printf("%llu\n", compute_even_fibonacci_sum(n));
    }
    return EXIT_SUCCESS;
}

static ull_t compute_even_fibonacci_sum(const ull_t n) {
    ull_t sub_problem_1_sol = 2, sub_problem_2_sol = 8;
    ull_t even_sum = sub_problem_1_sol;
    while(sub_problem_2_sol <= n) {
        even_sum += sub_problem_2_sol;
        ull_t temp = sub_problem_2_sol;
        sub_problem_2_sol = 4 * sub_problem_2_sol + sub_problem_1_sol;
        sub_problem_1_sol = temp;
    }
    return even_sum;
}
