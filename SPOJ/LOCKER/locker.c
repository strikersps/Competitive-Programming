/*  Problem Statement : https://www.spoj.com/problems/LOCKER/ (Magic of the Locker)
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define MOD 1000000007

typedef unsigned long long ull_t;

ull_t modular_expo(ull_t,ull_t); // Calculate the modular exponentiation (a^n % m);

int main(void) {
    size_t test;
    scanf("%ld",&test);
    while(test--) {
        ull_t n;
        scanf("%llu,",&n);
        assert(n > 0 && n < 1000000000001);
        if((n > 0) && (n < 5)) {
            printf("%llu\n",n);
        } else {
            if((n % 3) == 2) {
                printf("%llu\n",(( 2 * (modular_expo(3,n/3))) % MOD));
            } else if((n % 3) == 1) {
                printf("%llu\n",((4 * (modular_expo(3,((n/3)-1)))) % MOD));
            } else {
                printf("%llu\n",(modular_expo(3,(n/3))) % MOD);
            }
        }
    }
    return 0;
}

ull_t modular_expo(ull_t base,ull_t expo) {
    ull_t prod = 1;
    while(expo) {
        if(expo & 1) {
            prod = (prod*base) % MOD;
        }
        expo >>= 1;
        base = (base * base) % MOD;
    }
    return prod;
}