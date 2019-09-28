/*  Problem Statement: https://www.codechef.com/problems/FIBEASY
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<assert.h>

#define LENGTH 60

typedef unsigned long long ull_t;
typedef unsigned long ul_t;

unsigned short int* generate_fibonacci(void);

int main(void) {
    ul_t test;
    scanf("%lu",&test);
    assert(test > 0 && test < 100001);
    unsigned short *const fibonacii_seq = generate_fibonacci();
    while(test--) {
        ull_t n, preserved_index,exponent;
        scanf("%llu",&n);
        if(n & (n - 1)) {
            exponent = log2l(n);
            preserved_index = (exponent > 30 ? pow (2,exponent) : (1 << (ull_t)exponent));
        } else {
            preserved_index = n;
        }
        
        if(preserved_index > 60) {
            preserved_index %= 60;
        }
        printf("%hu\n",fibonacii_seq[preserved_index - 1]);
    }
    return 0;
}

unsigned short int* generate_fibonacci(void) {
    static unsigned short int fib[LENGTH];
    fib[0] = 0;
    fib[1] = 1;
    for(unsigned short int i = 2; i < LENGTH; ++i) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % 10;
    }
    return fib;
}