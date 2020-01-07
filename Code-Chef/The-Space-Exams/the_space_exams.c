/*  Problem Statement: https://www.codechef.com/PLIN2020/problems/SPCEXM
 *  Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define CONSTRAINTS_OUT_OF_BOUND_ERROR(variable, constraints) fprintf(stderr, "Line number: %u: Constraints not satisfied for the <%s> variable, i.e. %s.\n",  __LINE__, #variable, #constraints)
#define MEMORY_ALLOCATION_FAILED_ERROR(variable, bytes) fprintf(stderr, "Line number: %u: Not able to allocate <%lu> bytes of memory to <%s> variable.\n", __LINE__, (bytes), #variable)
#define INITIALISE_CONTAINER(container, bytes) memset(container, 0, (bytes))

int main(void) {
    #ifndef ONLINE_JUDGE
        freopen("test-cases/test-case-1.in", "r", stdin);
        freopen("test-cases/test-case-1.out", "w", stdout);
    #endif
    int test;
    scanf("%d", &test);
    while(test--) {
        int n, m;
        scanf("%d%d", &n, &m);
        bool above_avg_student[n];
        INITIALISE_CONTAINER(above_avg_student, n * sizeof(bool));
        int count_eligible_student = 0;
        for(int i = 0; i < m; ++i) {
            double avg_marks;
            unsigned int marks_sum = 0;
            int student_mark[n];
            for(int j = 0; j < n; ++j) {
                scanf("%d", &student_mark[j]);
                if(student_mark[j] < 0 || student_mark[j] > 100) {
                    CONSTRAINTS_OUT_OF_BOUND_ERROR(student_mark[j], 0 <= student_mark[j] <= 100);
                    exit(0);
                }
                marks_sum += student_mark[j];
            }
            avg_marks = (double) marks_sum / n;
            for(int k = 0; k < n; ++k) {
                if(student_mark[k] > (int) avg_marks) {
                    if(!above_avg_student[k]) {
                        above_avg_student[k] = true;
                    }
                }
            }
            INITIALISE_CONTAINER(student_mark, n * sizeof(int));
        }
        for(int k = 0; k < n; ++k) {
            if(above_avg_student[k]) {
                ++count_eligible_student;
            }
        }
        printf("%d\n", count_eligible_student);
    }
    return EXIT_SUCCESS;
}
