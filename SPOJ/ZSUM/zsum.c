/*  Problem Statement: https://www.spoj.com/problems/ZSUM/
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

#define MOD 10000007

size_t modular_expo(size_t,size_t);

int main(void) {
    size_t n,k;
    while(true) {
        scanf("%lu%lu", &n,&k);
        if(!n && !k) break;
        assert((n > 1 && ((int) 2e8)) && (k > 0 && k < ((int) 1e6)));
        size_t ans = (modular_expo(n,k) + modular_expo(n,n) + 2 * (modular_expo((n - 1),k)) + 2 * (modular_expo((n - 1),(n - 1)))) % MOD;
        printf("%lu\n", ans);
    }
    return 0;
}

size_t modular_expo(size_t base,size_t exponent) {
    size_t result = 1;
    if(base > MOD) {
        base %= MOD;
    }
    while(exponent) {
        if(exponent & 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exponent >>= 1;
    }
    return result;
}