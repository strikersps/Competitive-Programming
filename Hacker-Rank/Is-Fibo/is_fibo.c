/*  Problem Statement: https://www.hackerrank.com/contests/codesprint5/challenges/is-fibo/problem
 *  Author: striker
*/

#include<stdio.h>
#include<stdlib.h>

typedef unsigned long long ull_t;
typedef long long ll_t;

#define MAX_FIBONACCI_NUMBERS 94
#define NOT_FOUND -1
#define MEMORY_ALLOCATION_FAILED_ERROR(variable, bytes) fprintf(stderr, "Line number: %u: Not able to allocate <%lu> bytes of memory to <%s> variable.\n", __LINE__, (bytes), #variable)
#define CONSTRAINTS_OUT_OF_BOUND_ERROR(variable, constraints) fprintf(stderr, "Line number: %u: Constraints not satisfied for the <%s> variable, i.e. %s\n", __LINE__, #variable, #constraints)

static void generate_fibonacci_sequence(ull_t *const);
static int binary_search(ull_t *const, const ull_t);

int main(void) {
    /* Hackerrank Online Judge doesn't have ONLINE_JUDGE macro defined.
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
    ull_t *const fibo_sequence = calloc(MAX_FIBONACCI_NUMBERS, sizeof(*fibo_sequence));
    if(fibo_sequence) {
        generate_fibonacci_sequence(fibo_sequence);
        while(test--) {
            ull_t n;
            scanf("%llu", &n);
            if(n < 1 || n > 10000000000) {
                CONSTRAINTS_OUT_OF_BOUND_ERROR(n, 1 <= n <= 10^10);
                exit(0);
            }
            printf("%s\n", (NOT_FOUND == binary_search(fibo_sequence, n)) ? "IsNotFibo" : "IsFibo");
        }
        free(fibo_sequence);
    } else {
        MEMORY_ALLOCATION_FAILED_ERROR(fibo_sequence, MAX_FIBONACCI_NUMBERS * sizeof(*fibo_sequence));
        exit(0);
    }
    return EXIT_SUCCESS;
}

static void generate_fibonacci_sequence(ull_t *const fibo_sequence) {
    fibo_sequence[0] = 0;
    fibo_sequence[1] = 1;
    for(unsigned int i = 2; i < MAX_FIBONACCI_NUMBERS; ++i) {
        fibo_sequence[i] = fibo_sequence[i - 1] + fibo_sequence[i - 2];
    }
}

static int binary_search(ull_t *const data, ull_t key) {
    for(int start = 0, end = MAX_FIBONACCI_NUMBERS - 1; start <= end;) {
        const int mid = ((end - start) >> 1) + start;
        if(key == data[mid]) {
            return mid;
        } else if(key > data[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return NOT_FOUND;
}
