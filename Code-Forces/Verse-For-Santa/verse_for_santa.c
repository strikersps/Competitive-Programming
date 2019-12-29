/*  Problem Statement: https://codeforces.com/problemset/problem/1279/B
 *  Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef unsigned long long ull_t;
typedef long long ll_t;

#define CONSTRAINTS_OUT_OF_BOUND_ERROR(variable, constraints) fprintf(stderr, "Line number: %u: Constraints not satisfied for the <%s> variable i.e. %s.\n", __LINE__, #variable, constraints)
#define MEMORY_ALLOCATION_FAILED_ERROR(variable, bytes) fprintf(stderr, "Line number: %u: Not able to <%lu> bytes of memory to <%s> variable.\n", __LINE__, (bytes), #variable)

int main(void) {
    int test;
    scanf("%d", &test);
    if(test < 1 || test > 100) {
        CONSTRAINTS_OUT_OF_BOUND_ERROR(test, "1 <= test <= 100");
        exit(0);
    }
    while(test--) {
        unsigned int n, time_given_by_santa;
        scanf("%u%u", &n, &time_given_by_santa);
        if(n < 1 || n > 100000) {
            CONSTRAINTS_OUT_OF_BOUND_ERROR(n, "1 <= n <= 10^5");
            exit(0);
        }
        if(time_given_by_santa < 1 || time_given_by_santa > 1000000000) {
            CONSTRAINTS_OUT_OF_BOUND_ERROR(time_given_by_santa, "1 <= time_given_by_santa <= 10^9");
            exit(0);
        }
        unsigned int *const time_taken = calloc(n, sizeof(*time_taken));
        if(time_taken) {
            ull_t total_time_to_recite = 0;
            for(unsigned int i = 0; i < n; ++i) {
                scanf("%u", (time_taken + i));
                if(time_taken[i] < 1 || time_taken[i] > 1000000000) {
                    CONSTRAINTS_OUT_OF_BOUND_ERROR(time_taken[i], "1 <= time_taken[i] <= 10^9");
                    exit(0);
                }
                total_time_to_recite += time_taken[i];
            }
            if(total_time_to_recite <= time_given_by_santa) {
                printf("0\n");
            } else {
                int skip_index;
                for(unsigned int i = 0, max_time_taken = 0, time_elapsed = 0; i < n; ++i) {
                    time_elapsed += time_taken[i];
                    if(time_taken[i] > max_time_taken) {
                        max_time_taken = time_taken[i];
                        skip_index = i;
                    }
                    if(time_elapsed > time_given_by_santa) {
                        break;
                    }
                }
                printf("%d\n", skip_index + 1);
                free(time_taken);
            }
        } else {
            MEMORY_ALLOCATION_FAILED_ERROR(time_taken, n * sizeof(*time_taken));
            exit(0);
        }
    }
    return EXIT_SUCCESS;
}
