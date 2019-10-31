/*  Problem Statement: https://www.spoj.com/problems/BINSTIRL/
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<assert.h>

int main(void) {
    uint32_t test;
    scanf("%"SCNu32, &test);
    assert(test > 0 && test < 201);
    while(test--) {
        uint32_t n,m;
        scanf("%"SCNu32"%"SCNu32, &n,&m);
        assert((n > 0 && n < 1000000001) && (m > 0 && m < 1000000001));
        printf("%"PRIu8"\n", ((n >= m) ? !((n - m) & ((m - 1) >> 1)) : 0));
    }
    return EXIT_SUCCESS;
}