/*  Problem Statement: https://www.codechef.com/problems/TSORT
    Author: striker
    NOTE: Solved the problem using Counting Sort Algorithm. Time-Complexit = O(max(a[i])) where a[i] represents the ith element of the given sequence.
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<string.h>
#include<assert.h>

#define MAX_VAL 1000001

int main(void) {
    uint32_t n;
    scanf("%"SCNu32, &n);
    assert(n > 0 && n < MAX_VAL);
    uint32_t data[n],frequency_data[MAX_VAL];
    memset(frequency_data,0,(sizeof(uint32_t) * MAX_VAL));
    for(uint32_t i = 0; i < n; ++i) {
        scanf("%"SCNu32, &data[i]);
        assert(data[i] >= 0 && data[i] < MAX_VAL);
        ++frequency_data[data[i]];
    }
    for(uint32_t i = 0; i < MAX_VAL; ++i) {
        if(data[i] > 1) {
            for(uint32_t j = 0; j < frequency_data[i]; ++j) {
                printf("%"PRIu32"\n", i);
            }
        } else if(frequency_data[i] == 1) {
            printf("%"PRIu32"\n", i);
        }
    }
    return EXIT_SUCCESS;
}