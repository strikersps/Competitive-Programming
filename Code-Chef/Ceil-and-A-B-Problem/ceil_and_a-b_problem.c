/*  Problem Statement: https://www.codechef.com/problems/CIELAB
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<assert.h>

int main(void) {
    uint32_t a,b;
    scanf("%"SCNu32"%"SCNu32, &a,&b);
    assert((a > 0 && a < 10001) && (b > 0 && b < 10001));
    if((a - b) % 10 == 9) {
        printf("%"PRIu32"\n", (a - b) - 1);
    } else {
        printf("%"PRIu32"\n", (a - b) + 1);
    }
    return 0;
}