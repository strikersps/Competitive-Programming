/*  Problem Statement: https://www.codechef.com/JAN20B/problems/BRKBKS
 *  Author: striker
*/

#include<stdio.h>
#include<stdlib.h>

#define STACK_SIZE 3
#define MEMORY_ALLOCATION_FAILED_ERROR(variable, bytes) fprintf(stderr, "Line number: %u: Not able to allocate <%lu> bytes of memory to <%s> variable.\n", __LINE__, (bytes), #variable)

#define CONSTRAINTS_OUT_OF_BOUND_ERROR(variable, constraints) fprintf(stderr, "Line number: %u: Constraints not satisfied for <%s> variable i.e. %s.\n", __LINE__, #variable, #constraints)

static unsigned int compute_total_hits(const int, int *const);

int main(void) {
    #ifndef ONLINE_JUDGE
        freopen("test-cases/test-case-1.in", "r", stdin);
        freopen("test-cases/test-case-1.out", "w", stdout);
    #endif
    int test;
    scanf("%d", &test);
    if(test < 1 || test > 64) {
        CONSTRAINTS_OUT_OF_BOUND_ERROR(test, 1 <= test <= 64);
        exit(0);
    }
    while(test--) {
        int s;
        int stack_width[STACK_SIZE];
        scanf("%d%d%d%d", &s, &stack_width[0], &stack_width[1], &stack_width[2]);
        if(s < 1 || s > 8) {
            CONSTRAINTS_OUT_OF_BOUND_ERROR(s, 1 <= s <= 8);
            exit(0);
        }
        if(stack_width[0] < 1 || stack_width[0] > 2) {
            CONSTRAINTS_OUT_OF_BOUND_ERROR(stack_width[0], 1 <= stack_width[0] <= 2);
            exit(0);
        }
        if(stack_width[1] < 1 || stack_width[1] > 2) {
            CONSTRAINTS_OUT_OF_BOUND_ERROR(stack_width[1], 1 <= stack_width[1] <= 2);
            exit(0);
        }
        if(stack_width[2] < 1 || stack_width[2] > 2) {
            CONSTRAINTS_OUT_OF_BOUND_ERROR(stack_width[2], 1 <= stack_width[2] <= 2);
            exit(0);
        }
        printf("%u\n", compute_total_hits(s, stack_width));
    }
    return EXIT_SUCCESS;
}

static unsigned int compute_total_hits(const int s, int *const stack_width) {
    unsigned int min_hits = 0;
    if((s >= 6) || (s >= (stack_width[0] + stack_width[1] + stack_width[2]))) {
        min_hits = 1;
    } else {
        for(unsigned int i = 0; i < STACK_SIZE; ++i) {
            if(s >= (stack_width[i] + stack_width[i + 1])) {
                ++i;
            }
            ++min_hits;
        }
    }
    return min_hits;
}
