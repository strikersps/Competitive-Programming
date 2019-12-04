/*  Problem Statement: https://www.hackerrank.com/challenges/countingsort1/problem
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<string.h>
#include<assert.h>

#define MAX_VALUE 100

int main(void) {
    uint32_t n;
    scanf("%"SCNu32, &n);
    assert(n > 99 && n < 1000001);
    uint8_t data[n];
    uint32_t frequency_data[MAX_VALUE];
    memset(frequency_data,0,(sizeof(uint32_t) * MAX_VALUE));
    for(uint32_t i = 0; i < n; ++i) {
        scanf("%"SCNu8, &data[i]);
        assert(data[i] >= 0 && data[i] < 100);
        ++frequency_data[data[i]];
    }
    for(uint32_t i = 0; i < MAX_VALUE; ++i) {
        printf("%"PRIu32" ", frequency_data[i]);
    }
    printf("\n");
    return EXIT_SUCCESS;
}