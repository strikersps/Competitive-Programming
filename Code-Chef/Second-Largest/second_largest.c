/*  Problem Statement: https://www.codechef.com/problems/FLOW017
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<assert.h>

uint32_t find_max(uint32_t,uint32_t);
uint32_t find_min(uint32_t,uint32_t);

int main(void) {
    uint16_t test;
    scanf("%"SCNu16,&test);
    while(test--) {
        uint32_t a,b,c;
        scanf("%"SCNu32"%"SCNu32"%"SCNu32,&a,&b,&c);
        assert((a > 0 && a < 1000001) && (b > 0 && b < 1000001)  && (c > 0 && c < 1000001));
        printf("%"PRIu32"\n",(find_max(a,b) == find_max(a,c) ? find_min(find_max(a,b),find_max(b,c)) : find_min(find_max(a,b),find_max(a,c))));
    }
    return 0;
}

uint32_t find_max(uint32_t a,uint32_t b) {
    return (a > b) ? a : b;
}

uint32_t find_min(uint32_t a,uint32_t b) {
    return (a < b) ? a : b;
}
