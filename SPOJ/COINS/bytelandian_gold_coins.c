/*  Problem Statment: https://www.spoj.com/problems/COINS/
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

typedef unsigned long long ull_t;
typedef long long ll_t;

ull_t *cache = NULL;

ull_t max_american_dollars(ull_t);
ull_t find_max(ull_t,ull_t);

int main(void) {
    int iteration = 10;
    while(iteration--) {
        ull_t n;
        scanf("%llu", &n);
        assert(n >= 0 && n < 1000000001);
        cache = calloc(n,sizeof(ull_t));
        printf("%llu\n", max_american_dollars(n));
    }
    return EXIT_SUCCESS;
}

ull_t max_american_dollars(ull_t n) {
    if(n == 0) {
        return 0;
    } else if(n == 1) {
        cache[n] = 1;
    } else if(n == 2) {
        cache[n] = 2;
    } else if(n == 3) {
        cache[n] = 3;
    } else if(n == 4) {
        cache[n] = 4;
    } else if(!cache[n]) {
        cache[n] = find_max(n,(max_american_dollars(n >> 1) + max_american_dollars(n / 3) + max_american_dollars(n / 4)));
        return cache[n];
    }
    return cache[n];
}

ull_t find_max(ull_t a,ull_t b) {
    return (a > b ? a : b);
}