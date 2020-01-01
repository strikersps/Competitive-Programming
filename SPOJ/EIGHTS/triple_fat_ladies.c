/*  Problem Statement: https://www.spoj.com/problems/EIGHTS/
 *  Author: striker
*/

#include<stdio.h>
#include<stdlib.h>

typedef unsigned long long ull_t;
typedef long long ll_t;

#define MEMORY_ALLOCATION_FAILED_ERROR(variable, bytes) fprintf(stderr, "Line number: %u: Not able to allocate <%lu> bytes of memory to <%s> variable\n", __LINE__, (bytes), #variable)
#define CONSTRAINTS_OUT_OF_BOUND_ERROR(variable, constraints) fprintf(stderr, "Line number: %u: Constraints not satisfied for the <%s> variable i.e. %s\n",  __LINE__, #variable, #constraints)

int main(void) {
    #ifndef ONLINE_JUDGE
        freopen("test-cases/test-case-1.in", "r", stdin);
        freopen("test-cases/test-case-1.out", "w", stdout);
    #endif
    int test;
    scanf("%d", &test);
    if(test < 1) {
        CONSTRAINTS_OUT_OF_BOUND_ERROR(test, "test variable cannot be -ve.");
        exit(0);
    }
    while(test--) {
        ull_t k;
        scanf("%llu", &k);
        if(k < 1 || k > 2000000000000) {
            CONSTRAINTS_OUT_OF_BOUND_ERROR(k, 1 <= k <= 2000000000000);
            exit(0);
        }
        printf("%llu\n", 192 + 250 * (k - 1));
    }
    return EXIT_SUCCESS;
}
