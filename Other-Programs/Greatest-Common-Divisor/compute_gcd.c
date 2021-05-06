/*
 *  Problem Statement: Program to compute the GCD of two numbers using only one statement.
 *  Author: striker
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef long long ll_t;
typedef unsigned long long ull_t;

#define SCANF_READ_ERROR(exp_return) fprintf(stderr, "Line Number: %u: scanf() read error. Expected return value: %d\n", __LINE__, (exp_return)); exit(1)

static ll_t compute_gcd(ll_t, ll_t);

int main(void) {
    int test;
    if(1 != scanf("%d", &test)) {
        SCANF_READ_ERROR(1);
    }
    assert(test > 0);
    while(test--) {
        ll_t a, b;
        if(2 != scanf("%lld%lld", &a, &b)) {
            SCANF_READ_ERROR(2);
        }
        printf("%lld\n", compute_gcd(a, b));
    }
    return EXIT_SUCCESS;
}

static ll_t compute_gcd(ll_t a, ll_t b) {
    return !b ? a : b == 1LL ? b : compute_gcd(b, a % b);
}
