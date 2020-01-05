/*  Problem Statement: https://codeforces.com/contest/1287/problem/A
 *  Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MEMORY_ALLOCATION_FAILED_ERROR(variable, bytes) fprintf(stderr, "Line number: %u: Not able to allocate <%lu> bytes of memory to <%s> variable.\n", __LINE__, (bytes), #variable)
#define CONSTRAINTS_OUT_OF_BOUND_ERROR(variable, constraints) fprintf(stderr, "Line number: %u: Constraints not satisfied for the variable <%s> i.e. %s.\n", __LINE__, #variable, #constraints)

static bool is_pair_exist(char *const);

int main(void) {
    #ifndef ONLINE_JUDGE
        freopen("test-cases/test-case-1.in", "r",  stdin);
        freopen("test-cases/test-case-1.out", "w", stdout);
    #endif
    int test;
    scanf("%d", &test);
    if(test < 1 || test > 100) {
        CONSTRAINTS_OUT_OF_BOUND_ERROR(test, 1 <= test <= 100);
        exit(0);
    }
    while(test--) {
        int n;
        scanf("%d", &n);
        if(n < 1 || n > 100) {
            CONSTRAINTS_OUT_OF_BOUND_ERROR(n, 1 <= n <= 100);
            exit(0);
        }
        char student_line[n];
        scanf("%s", student_line);
        int time;
        for(time = 0; is_pair_exist(student_line); ++time);
        printf("%d\n", time);
    }
    return EXIT_SUCCESS;
}

static bool is_pair_exist(char *const student_line) {
    bool is_exist = false;
    for(unsigned int i = 1; student_line[i] != '\0'; ++i) {
        if(student_line[i] == 'P' && student_line[i - 1] == 'A') {
            is_exist = true;
            student_line[i++] = 'A';
        }
    }
    return is_exist;
}
