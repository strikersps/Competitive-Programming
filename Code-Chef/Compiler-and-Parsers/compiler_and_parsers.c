/*  Problem Statement: https://www.codechef.com/problems/COMPILER
 *  Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_EXPRESSION_LENGTH 1000001
#define MEMORY_ALLOCATION_FAILED_ERROR(variable, bytes) fprintf(stderr, "Line number: %u: Not able to allocate <%lu> bytes of memory to <%s> variable.\n", __LINE__, (bytes), #variable)
#define CONSTRAINTS_OUT_OF_BOUND_ERROR(variable, constraints) fprintf(stderr, "Line number: %u: Constraints not satisfied for <%s> variable, i.e. %s.\n", __LINE__, #variable, #constraints)

static int compute_length_of_longest_prefix(char[]);

int main(void) {
    #ifndef ONLINE_JUDGE
        freopen("test-cases/test-case-1.in", "r", stdin);
        freopen("test-cases/test-case-1.out", "w", stdout);
    #endif
    int test;
    scanf("%d", &test);
    if(test < 1 || test > 500) {
        CONSTRAINTS_OUT_OF_BOUND_ERROR(test, 1 <= test <= 500);
        exit(0);
    }
    while(test--) {
        char expression[MAX_EXPRESSION_LENGTH];
        scanf("%s", expression);
        printf("%d\n", compute_length_of_longest_prefix(expression));
    }
    return EXIT_SUCCESS;
}

static int compute_length_of_longest_prefix(char expression[]) {
    int max_prefix_length;
    int open_angle_brackets = 0;
    max_prefix_length = 0;
    for(int i = 0; expression[i] != '\0'; ++i) {
        if(expression[i] == '<') {
            ++open_angle_brackets;
        } else {
            --open_angle_brackets;
        }
        if(!open_angle_brackets) {
            max_prefix_length = (i + 1);
        } else if (open_angle_brackets < 0) {
            break;
        }
    }
    return max_prefix_length;
}
