/*  Problem Statement: https://www.codechef.com/problems/CHOPRT
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int main(void) {
    size_t test;
    scanf("%lu", &test);
    assert(test > 0 && test < 10001);
    while(test--) {
        size_t a,b;
        scanf("%lu%lu", &a,&b);
        assert((a > 0 && a <= 1000000001) && (b > 0 && b <= 1000000001));
        if(a == b) {
            printf("=\n");
        } else if(a > b) {
            printf(">\n");
        } else {
            printf("<\n");
        }
    }
    return 0;
}