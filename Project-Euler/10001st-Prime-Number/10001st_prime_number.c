/*  Problem Statement: https://www.hackerrank.com/contests/projecteuler/challenges/euler007/problem or https://projecteuler.net/problem=7
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>
#include<string.h>
#include<assert.h>

#define MAX_LIMIT 1000000 // Chosen this limit because there are 78,493 prime number <= 10^6
#define TOTAL_PRIMES 78493
uint32_t prime_number_table[TOTAL_PRIMES]; // Making the table global so that I can access it throughout the program.

void generate_prime(void);

int main(void) {
    uint32_t test;
    scanf("%"SCNu32, &test);
    assert(test > 0 && test < 1001);
    generate_prime();
    while(test--) {
        uint32_t n;
        scanf("%"SCNu32, &n);
        assert(n > 0 && n < TOTAL_PRIMES);
        printf("%"PRIu32"\n", prime_number_table[n - 1]); // Constant time operation.
    }
    return EXIT_SUCCESS;
}

void generate_prime(void) {
    bool sieve_table[MAX_LIMIT];
    memset(sieve_table,true,(sizeof(bool) * MAX_LIMIT));
    sieve_table[0] = false;
    sieve_table[1] = false;
    for(uint32_t i = 2, k = 0; i < MAX_LIMIT; ++i) {
        if(sieve_table[i]) {
            prime_number_table[k++] = i;
            for(uint32_t j = (i * i); j <= MAX_LIMIT; j += i) {
                sieve_table[j] = false;
            }
        }
    }
}