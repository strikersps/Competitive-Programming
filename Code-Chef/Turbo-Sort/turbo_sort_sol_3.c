/*  Problem Statement: https://www.codechef.com/problems/TSORT
    Author: striker
    NOTE: Solved the problem using qsort() function defined in the stdlib.h header file. qsort() function sorts the data using the Quick-Sort Sorting Algorithm. Time-Complexity = O(n^2) in worst-case scenario.
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<assert.h>

int comparator_callback(const void*,const void*);

int main(void) {
    uint32_t n;
    scanf("%"SCNu32, &n);
    assert(n > 0 && n < 1000001);
    uint32_t data[n];
    for(uint32_t i = 0; i < n; ++i) {
        scanf("%"SCNu32, &data[i]);
        assert(data[i] >= 0 && data[i] < 1000001);
    }
    qsort(data,n,sizeof(uint32_t),comparator_callback);
    for(uint32_t i = 0; i < n; ++i) {
        printf("%"PRIu32"\n", data[i]);
    }
    return EXIT_SUCCESS;
}

int comparator_callback(const void *a,const void *b) {
    return ((*(uint32_t*)a) > (*(uint32_t*)b));
}