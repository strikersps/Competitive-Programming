/*  Problem Statement: https://www.spoj.com/problems/FASHION/
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<string.h>
#include<stdbool.h>

#define MAX_SIZE 11
#define MEMORY_ALLOCATION_FAILED_ERROR(variable, bytes) fprintf(stderr, "Line number: %u: Not able to allocate <%lu> bytes of memory to <%s> variable.\n", __LINE__, (bytes), #variable)
#define CONSTRAINTS_OUT_OF_BOUND_ERROR(variable, constraints) fprintf(stderr, "Line number: %u: Constraints not satisfied for the variable <%s> i.e. $%s\n", __LINE__, #variable, #constraints)

int comparator_callback(const void*, const void*);

int main(void) {
    #ifndef ONLINE_JUDGE
        freopen("test-cases/test-case-2.in", "r", stdin);
        freopen("test-cases/test-case-2.out", "w", stdout);
    #endif
    int test;
    scanf("%d", &test);
    if(test < 1) {
        CONSTRAINTS_OUT_OF_BOUND_ERROR(test, test variable cannot be -ve);
        exit(0);
    }
    while(test--) {
        int n;
        scanf("%d", &n);
        if(n < 1) {
            CONSTRAINTS_OUT_OF_BOUND_ERROR(n, n cannot be -ve);
            exit(0);
        }
        unsigned int *const hotness_level_men = calloc(n, sizeof(*hotness_level_men));
        if(hotness_level_men) {
            for(int i = 0; i < n; ++i) {
                scanf("%u", &hotness_level_men[i]);
            }
            qsort(hotness_level_men, n, sizeof(*hotness_level_men), comparator_callback);
        } else {
            MEMORY_ALLOCATION_FAILED_ERROR(hotness_level_man, n * sizeof(*hotness_level_men));
            exit(0);
        }
        unsigned int *const hotness_level_women = calloc(n, sizeof(*hotness_level_women));
        if(hotness_level_women) {
            for(int i = 0; i < n; ++i) {
                scanf("%u", &hotness_level_women[i]);
            }
            qsort(hotness_level_women, n, sizeof(*hotness_level_women), comparator_callback);
        } else {
            MEMORY_ALLOCATION_FAILED_ERROR(hotness_women_level, n * sizeof(*hotness_level_women));
            exit(0);
        }
        unsigned int sum_of_hotness_bonds = 0;
        for(int i = 0; i < n; ++i) {
            if(hotness_level_men[i] && hotness_level_women[i]) {
                sum_of_hotness_bonds += (hotness_level_men[i] * hotness_level_women[i]);
            }
        }
        printf("%d\n", sum_of_hotness_bonds);
        free(hotness_level_men);
        free(hotness_level_women);
    }
    return EXIT_SUCCESS;
}

int comparator_callback(const void *a, const void *b) {
    return (*(unsigned int*) a) < (*(unsigned int*) b);
}
