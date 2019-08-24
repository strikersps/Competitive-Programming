/*  Problem Statement: https://www.spoj.com/problems/ETF/
    Author: Suraj Sharma
*/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdint.h>

size_t compute_euler_totient(uint32_t);

int main(void) {
    uint32_t n,test;
    scanf("%d",&test);
    assert(test>0 && test<20001);
    while(test--) {
        scanf("%d",&n);
        assert(n>0 && n<1000001);
        printf("%ld\n",compute_euler_totient(n));
    }
    return 0;
}

size_t compute_euler_totient(uint32_t n) {
    uint32_t result = n;
    for(uint32_t i=2;(i*i)<=n;++i) {
        if(!(n%i)) {
            while(!(n%i)) n /= i;
            result -= (result/i);
        }
    }
    if(n>1) result -= (result/n);
    return result;
}