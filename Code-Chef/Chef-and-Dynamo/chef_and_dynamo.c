/*  Problem Statement: https://www.codechef.com/JAN20B/problems/DYNAMO
 *  Author: striker
 *  It's an interactive problem i.e. The program will interact with the online-judge.
 *  Read more on: https://codeforces.com/blog/entry/45307 for more information on how to design solutions for interactive problems in different
    programming languages.
*/

#include<stdio.h>
#include<stdlib.h>

typedef unsigned long long ull_t;
typedef long long ll_t;

#define MEMORY_ALLOCATION_FAILED_ERROR(variable, bytes) fprintf(stderr, "Line number: %u: Not able to allocate <%lu> bytes of memory to <%s> variable.\n", __LINE__, (bytes), #variable)
#define CONSTRAINTS_OUT_OF_BOUND_ERROR(variable, constraints) fprintf(stderr, "Line number: %u: Constraints not satisfied for <%s> variable, i.e. %s.\n", __LINE__, #variable, #constraints)

static ull_t binary_exponentiation(ull_t, ull_t);

int main(void) {
    #ifndef ONLINE_JUDGE
        freopen("test-cases/test-case-1.in", "r", stdin);
        freopen("test-cases/test-case-1.out", "w", stdout);
    #endif
    int test;
    scanf("%d", &test);
    if(test < 1 || test > 1000) {
        CONSTRAINTS_OUT_OF_BOUND_ERROR(test, 1 <= test <= 10^3);
        exit(0);
    }
    while(test--) {
        unsigned short int n;
        scanf("%hu", &n);
        if(n < 1 || n > 18) {
            CONSTRAINTS_OUT_OF_BOUND_ERROR(n, 1 <= n <= 18);
            exit(0);
        }
        ull_t sum, a, b, c, d, e;
        scanf("%llu", &a);
        sum = a + (2 * binary_exponentiation(10, n));
        printf("%llu\n", sum);
        fflush(stdout);
        scanf("%llu", &b);
        c = binary_exponentiation(10, n) - b;
        printf("%llu\n", c);
        fflush(stdout);
        scanf("%llu", &d);
        e = sum - (a + b + c + d);
        printf("%llu\n", e);
        fflush(stdout);
        int success;
        scanf("%d", &success);
        if(-1 == success) {
            break;
        }
    }
    return EXIT_SUCCESS;
}

static ull_t binary_exponentiation(ull_t base, ull_t exponent) {
    ull_t result = 1;
    if(!exponent) {
        return result;
    } else if(1 == exponent) {
        result = base;
    } else {
        while(exponent) {
            if(exponent & 1) {
                result *= base;
            }
            base *= base;
            exponent >>= 1;
        }
    }
    return result;
}
