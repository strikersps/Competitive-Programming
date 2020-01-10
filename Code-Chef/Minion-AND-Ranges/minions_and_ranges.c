/*  Problem Statement: https://www.codechef.com/PLIT2020/problems/MINIAND
 *  Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MEMORY_ALLOCATION_FAILED_ERROR(variable, bytes) fprintf(stderr, "Line number: %u: Not able to allocate <%lu> bytes of memory to <%s> variable.\n",  __LINE__, (bytes), #variable)
#define CONSTRAINTS_OUT_OF_BOUND_ERROR(variable, constraints) fprintf(stderr, "Line number: %u: Constraints not satisfied for <%s> variable, i.e. %s.\n", __LINE__, #variable, #constraints)
#define INITIALISE_CONTAINTER(container, bytes) memset(container, 0, (bytes))

int main(void) {
    #ifndef ONLINE_JUDGE
        freopen("test-cases/test-case-1.in", "r", stdin);
        freopen("test-cases/test-case-1.out", "w", stdout);
    #endif
    int test;
    scanf("%d", &test);
    while(test--) {
        int n;
        scanf("%d", &n);
        int *const data = calloc(n, sizeof(*data));
        if(data) {
            int even_number_freq[n]; // For storing the count of even numbers befor a[i].
            INITIALISE_CONTAINTER(even_number_freq, n * sizeof(int));
            for(int i = 0; i < n; ++i) {
                scanf("%d", &data[i]);
                if(i > 0) {
                    even_number_freq[i] = even_number_freq[i - 1] + (!(data[i] % 2) ? 1 : 0);
                } else {
                    even_number_freq[i] = !(data[i] % 2) ? 1 : 0;
                }
            }
            int queries;
            scanf("%d", &queries);
            while(queries--) {
                int start, end;
                scanf("%d%d", &start, &end);
                --start, --end;
                if(start <= end) {
                    if(end == start) {
                        printf("%s\n", (!(data[start] % 2)) ? "EVEN" : "ODD");
                    } else {
                        if(((data[start] % 2) && (data[end] % 2)) && (0 == (even_number_freq[end] - even_number_freq[start]))) {
                            printf("ODD\n");
                        } else {
                            printf("EVEN\n");
                        }
                    }
                } else {
                    fprintf(stderr, "Constraints not satisfied, i.e. start <= end.\n");
                    exit(0);
                }
            }
            free(data);
        } else {
            MEMORY_ALLOCATION_FAILED_ERROR(data, n * sizeof(*data));
            exit(0);
        }
    }
    return EXIT_SUCCESS;
}
