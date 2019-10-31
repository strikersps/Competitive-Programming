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
    for(int i = 0; i < 10; ++i) {
        ull_t n;
        scanf("%llu", &n);
        assert(n >= 0 && n < 1000000001);
        cache = calloc(n,sizeof(ull_t));
        printf("%llu\n", max_american_dollars(n));
        free(cache);
        cache = NULL; // To get rid of dangling pointer.
    }
    return EXIT_SUCCESS;
}

ull_t max_american_dollars(ull_t n) {
    if(n == 0) {
        return 0;
    } else if(n == 1 || n == 2 || n == 3 || n == 4) {
        cache[n - 1] = n;
    } else if(!cache[n - 1]) {
        cache[n - 1] = find_max(n,(max_american_dollars(n >> 1) + max_american_dollars(n / 3) + cache[((n >> 1) >> 1) - 1]));
    }
    return cache[n - 1];
}

ull_t find_max(ull_t a,ull_t b) {
    return (a > b ? a : b);
}