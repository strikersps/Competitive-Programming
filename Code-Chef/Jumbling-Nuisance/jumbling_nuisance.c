/*  Problem Statement: https://www.codechef.com/ICHN2019/problems/ICHN03
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef unsigned long long ull_t;

int main(void) {
    size_t n;
    scanf("%lu",&n);
    assert(n > 1 && n < 101);
    ull_t *const sequence = calloc(n,sizeof(ull_t));
    sequence[0] = 0;
    sequence[1] = 1;
    for(size_t i = 2; i < n; ++i) {
        if(i & 1) {
            sequence[i] = ((i + 1) * (sequence[i - 1])) + 1;
        } else {
            sequence[i] = ((i + 1) * (sequence[i - 1])) - 1;
        }
    }
    printf("%llu\n",sequence[n - 1]);
    free(sequence);
    return 0;
}