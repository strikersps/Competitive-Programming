/*  Problem Statement: https://www.spoj.com/problems/ACODE/
 *  Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef unsigned long long ull_t;
typedef long long ll_t;

#define MAX_STRING_LENGTH 50001
#define MEMORY_ALLOCATION_FAILED_ERROR(variable, bytes) fprintf(stderr, "Line number: %u: Not able to allocate <%lu> bytes of memory to <%s> variable.\n", __LINE__, (bytes), #variable)
#define CONSTRAINTS_OUT_OF_BOUND_ERROR(variable, constraints) fprintf(stderr. "Line number: %u: Constraints not satisfied for the <%s> variable i.e. %s\n", __LINE__, #variable, #constraints)

static ull_t compute_number_of_decodings(char[]);

int main(void) {
    #ifndef ONLINE_JUDGE
        freopen("test-cases/test-case-1.in", "r", stdin);
        freopen("test-cases/test-case-1.out", "w", stdout);
    #endif
    while(true) {
        char encoded_data[MAX_STRING_LENGTH];
        scanf("%s", encoded_data);
        if(!strcmp(encoded_data, "0")) {
            break;
        }
        printf("%llu\n", compute_number_of_decodings(encoded_data));
    }
    return EXIT_SUCCESS;
}

static ull_t compute_number_of_decodings(char encoded_data[]) {
    int data_len = strlen(encoded_data);
    ull_t *const cache_solutions = calloc(data_len, sizeof(*cache_solutions));
    if(cache_solutions) {
        for(int end = data_len - 1, i = 0; end >= 0; --end, ++i) {
            if(end == data_len - 1) {
                if('0' == encoded_data[end]) {
                    cache_solutions[i] = 0;
                } else {
                    cache_solutions[i] = 1;
                }
            } else {
                int valid_num = ((encoded_data[end] - '0') * 10) + encoded_data[end + 1] - '0';
                if('0' != encoded_data[end]) {
                    cache_solutions[i] = cache_solutions[i - 1];
                    if(valid_num > 9  && valid_num < 27) {
                        if(end == data_len - 2) {
                            cache_solutions[i]++;
                        } else {
                            cache_solutions[i] += cache_solutions[i - 2];
                        }
                    }
                }
            }
        }
    } else {
        MEMORY_ALLOCATION_FAILED_ERROR(cache_solutions, data_len * sizeof(*cache_solutions));
        exit(0);
    }
    ull_t total_decodings = cache_solutions[data_len - 1];
    free(cache_solutions);
    return total_decodings;
}

