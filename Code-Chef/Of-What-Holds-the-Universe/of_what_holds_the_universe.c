/*  Problem Statement: https://www.codechef.com/SAPC2019/problems/SOPC010
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>

typedef unsigned long long ull_t;
typedef long long ll_t;

#define MEMORY_ALLOCATION_FAILED_ERROR(variable, bytes) fprintf(stderr, "Line number: %u: Not able to allocate <%llu> bytes of memory to <%s> variable.\n",  __LINE__, (bytes), #variable)
#define CONSTRAINTS_OUT_OF_BOUND_ERROR(variable, constraints) fprintf(stderr, "line nunmber: %u: Constraints not satisfied for <%s> varaible, i.e. %s.\n", __LINE__, #variable, #constraints)
#define INITIALISE_CONTAINER(container, bytes) memset(container, 0, (bytes))
#define LOG_3_BASE_2 1.58496250072

static ull_t compute_total_numbers_less_than_n(ull_t);
static char* compute_base_3_representation(ull_t);
static ull_t compute_base_10_representation(char[]);

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
        ull_t n;
        scanf("%llu", &n);
        if(n < 1 || n > 1000000000000000000) {
            CONSTRAINTS_OUT_OF_BOUND_ERROR(n, 1 <= n <= 10^18);
            exit(0);
        }
        printf("%llu\n", compute_total_numbers_less_than_n(n));
    }
    return EXIT_SUCCESS;
}

static ull_t compute_total_numbers_less_than_n(ull_t n) {
    char *const base_3_representation = compute_base_3_representation(n);
    if(base_3_representation) {
        bool first_occurrence = false;
        for(ull_t i = 0; base_3_representation[i] != '\0'; ++i) {
            if('2' == base_3_representation[i]) {
                first_occurrence = true;
            }
            if(first_occurrence) {
                base_3_representation[i] = '1';
            }
        }
    }
    return compute_base_10_representation(base_3_representation);
}

static char* compute_base_3_representation(ull_t n) {
    ull_t number_of_digits = (ull_t)(log2l(n) / LOG_3_BASE_2) + 2;
    char *const base_3_representation = calloc(number_of_digits, sizeof(*base_3_representation));
    if(base_3_representation) {
        ll_t index = number_of_digits - 2;
        while(n) {
            base_3_representation[index--] = (n % 3) + '0';
            n /= 3;
        }
    } else {
        MEMORY_ALLOCATION_FAILED_ERROR(base_3_representation, number_of_digits * sizeof(*base_3_representation));
        exit(0);
    }
    return base_3_representation;
}

static ull_t compute_base_10_representation(char base_2_representation[]) {
    ull_t base_10_representation = 0;
    if(base_2_representation) {
        for(ull_t i = 0; base_2_representation[i] != '\0'; ++i) {
            base_10_representation = (2 * base_10_representation) + (base_2_representation[i] - '0');
        }
    }
    return base_10_representation;
}
