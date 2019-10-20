/*  Problem Statement: https://www.codechef.com/INFY2019/problems/INF1908
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<assert.h>

int main(void) {
    uint16_t test;
    scanf("%"SCNu16, &test);
    assert(test > 0 && test < 101);
    while(test--) {
        uint32_t n,k;
        scanf("%"SCNu32"%"SCNu32, &n,&k);
        assert((n > 0 && n < 100001) && (k > 0 && k < 100001));
        if(n % 10) {
            uint32_t reduced_number = (n / 10) * 10;
            printf("%"PRIu32"\n", (reduced_number + ((n + (k % 10)) % 10)));
        } else {
            printf("%"PRIu32"\n", (n + (k % 10)));
        }
    }
    return 0;
}
