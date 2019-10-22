/*  Problem Statement: https://www.codechef.com/problems/REMISS
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<assert.h>

int main(void) {
    uint16_t test;
    scanf("%"SCNu16,&test);
    assert(test > 0 && test < 101);
    while(test--) {
        uint32_t a,b;
        scanf("%"SCNu32"%"SCNu32,&a,&b);
        assert((a > 0 && a < 1000001) && (b > 0 && b < 1000001));
        printf("%"PRIu32" %"PRIu32"\n",(a > b ? a : b),(a + b));
    }
    return 0;
}