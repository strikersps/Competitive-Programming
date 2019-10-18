/*  You can refer to the screen-shot on the link (https://github.com/strikersps/Competitive-Programming/blob/master/Other-Programs/Common-Prime/Common-Prime-Problem-Statement.jpg) for the problem statement.
    Problem was asked in JP Morgan Chase Online Programming Challenge.
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>
#include<assert.h>

#define NOT_EXIST -1

const uint64_t compute_gcd(uint64_t,uint64_t);
void compute_prime_factors(uint64_t n);

int main(void) {
    uint64_t a,b;
    scanf("%"SCNu64"%"SCNu64,&a,&b);
    assert(a > 0 && b > 0);
    if(compute_gcd(a,b) == 1) {
        printf("%"PRId8"\n", NOT_EXIST);
    } else {
        compute_prime_factors(compute_gcd(a,b));
    }
    return 0;
}

const uint64_t compute_gcd(uint64_t a,uint64_t b) {
    if(b == 0) {
        return a;
    } else {
        return compute_gcd(b,(a%b));
    }
}

void compute_prime_factors(uint64_t n) {
    uint64_t smallest_prime_factor = INT64_MAX;
    if(!(n & 1)) {
        smallest_prime_factor = 2;
    }
    while(!(n & 1)) {
        n >>= 1;
    }
    for(uint64_t i = 3; (i * i) <= n; i += 2) {
        if(!(n % i)) {
            if(i < smallest_prime_factor) {
                smallest_prime_factor = i;
            }
            n /= i;
        }
    }
    if((n > 2) && (n < smallest_prime_factor)) {
        smallest_prime_factor = n;
    }
    printf("%"PRIu64"\n", smallest_prime_factor);
}