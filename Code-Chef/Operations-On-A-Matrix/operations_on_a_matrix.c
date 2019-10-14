/*  Problem Statement: https://www.codechef.com/OCT19B/problems/SAKTAN
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<string.h>
#include<assert.h>

uint64_t const find_odd_numbers(uint32_t *const,uint32_t *const,uint32_t,uint32_t);

int main(void) {
    uint16_t test;
    scanf("%"SCNu16,&test);
    assert(test > 0 && test < 301);
    while(test--) {
        uint32_t n,m,q;
        scanf("%"SCNu32"%"SCNu32"%"SCNu32,&n,&m,&q);
        assert((m > 0 && m <100001) && (n > 0 && n < 100001) && (q > 0 && q < 100001));
        uint32_t *const row_access = calloc(n,sizeof(uint32_t));
        uint32_t *const col_access = calloc(m,sizeof(uint32_t));
        while(q--) {
            uint32_t x_i,y_i;
            scanf("%"SCNu32"%"SCNu32,&x_i,&y_i);
            assert((x_i > 0 && x_i <= n) && (y_i > 0 && y_i <= m));
            ++row_access[x_i - 1];
            ++col_access[y_i - 1];
        }
        printf("%"PRIu64"\n",find_odd_numbers(row_access,col_access,n,m));
        free(row_access);
        free(col_access);
    }
    return 0;
}

uint64_t const find_odd_numbers(uint32_t *const row_access,uint32_t *const col_access,uint32_t n,uint32_t m) {
    uint64_t row_access_odd,row_access_even,col_access_odd,col_access_even;
    row_access_odd = row_access_even = col_access_odd = col_access_even = 0;
    for(uint32_t i = 0; i < n; ++i) {
        if(row_access[i] & 1) {
            ++row_access_odd;
        } else {
            ++row_access_even;
        }
    }
    for(uint32_t i = 0; i < m; ++i) {
        if(col_access[i] & 1) {
            ++col_access_odd;
        } else {
            ++col_access_even;
        }
    }
    return ((row_access_odd * col_access_even) + (row_access_even * col_access_odd));
}