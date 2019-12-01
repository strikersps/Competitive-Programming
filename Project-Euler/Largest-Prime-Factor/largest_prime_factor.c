/*  Problem Statement: https://www.hackerrank.com/contests/projecteuler/challenges/euler003/problem
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<assert.h>

static uint64_t largest_prime_factor(uint64_t);

int main(void) {
    int8_t test;
    scanf("%"SCNd8, &test);
    assert(test > 0 && test < 11);
    while(test--) {
        uint64_t n;
        scanf("%"SCNu64, &n);
        assert(n > 9 && n < 1000000000001);
        printf("%"PRIu64"\n", largest_prime_factor(n));
    }
    return EXIT_SUCCESS;
}

static uint64_t largest_prime_factor(uint64_t n) {
    uint64_t max_prime_factor = 0;
    if(!(n & 1)) {
        max_prime_factor = 2;
    }
    while(!(n & 1)) {
        n >>= 1;
    }
    for(uint64_t i = 3; (i * i) <= n; i +=2) {
        if(!(n % i)) {
            max_prime_factor = i;
            while(!(n % i)) {
                n /= i;
            }
        }
    }
    if(n > 2) {
        max_prime_factor = n;
    }
    return max_prime_factor;
}