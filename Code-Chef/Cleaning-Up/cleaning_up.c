/*  Problem Statement: https://www.codechef.com/problems/CLEANUP/
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<inttypes.h>
#include<assert.h>

#define MEMORY_ALLOCATION_FAILED_ERROR(variable,bytes) fprintf(stderr,"Line number: %u: Not able to allocate <%lu> bytes of memory to <%s> variable.\n", __LINE__, bytes, #variable)
#define CONSTRAINTS_OUT_OF_BOUND_ERROR(variable,constraints) fprintf(stderr,"Line number: %u: Constraints of <%s> variable not satified. Constraints is <%s>.\n", __LINE__, #variable, constraints)

static void compute_left_job_assignment_list(const int *const, size_t);

int main(void) {
    int test;
    scanf("%d", &test);
    if(test < 1) {
        CONSTRAINTS_OUT_OF_BOUND_ERROR(test, "test > 0");
        exit(0);
    }
    while(test--) {
        int n,m;
        scanf("%d%d", &n, &m);
        if(m > n) {
            CONSTRAINTS_OUT_OF_BOUND_ERROR(m, "m <= n");
            exit(0);
        } else {
            bool *const jobs_list = calloc(n, sizeof(*jobs_list));
            if(jobs_list) {
                memset(jobs_list, false, n * sizeof(*jobs_list));
                for(int i = 0; i < m; ++i) {
                    uint32_t index;
                    scanf("%u", &index);
                    jobs_list[index - 1] = true;
                }
                if(n == m) {
                    printf(" \n \n");
                } else {
                    int *const jobs_uncompleted_list = calloc(n - m, sizeof(*jobs_uncompleted_list));
                    if(jobs_uncompleted_list) {
                        for(int i = 0, j = 0; i < n; ++i) {
                            if(!jobs_list[i]) {
                                jobs_uncompleted_list[j++] = i + 1;
                            }
                        }
                        free(jobs_list);
                        compute_left_job_assignment_list(jobs_uncompleted_list, n - m);
                        free(jobs_uncompleted_list);
                    } else {
                        MEMORY_ALLOCATION_FAILED_ERROR(jobs_uncompleted_list, (n - m) * sizeof(*jobs_uncompleted_list));
                        exit(0);
                    }
                }
            } else {
                MEMORY_ALLOCATION_FAILED_ERROR(jobs_list, n * sizeof(*jobs_list));
                exit(0);
            }
        }
    }
    return EXIT_SUCCESS;
}

static void compute_left_job_assignment_list(const int *const data, size_t n) {
    printf("%d", data[0]);
    for(uint32_t i = 2; i < n; i += 2) {
        printf(" %d", data[i]);
    }
    printf("\n");
    if(n > 1) {
        printf("%d", data[1]);
        for(uint32_t i = 3; i < n; i += 2) {
            printf(" %d", data[i]);
        }
        printf("\n");
    } else {
        printf(" \n");
    }
}
