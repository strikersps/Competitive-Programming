/*  Problem Statement: https://www.codechef.com/problems/EXUNA
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<assert.h>

const uint32_t find_minimum(uint32_t *const,uint32_t n);

int main(void) {
    uint32_t test;
    scanf("%"SCNu32,&test);
    assert(test > 0 && test < 500001);
    while(test--) {
        uint32_t n;
        scanf("%"SCNu32,&n);
        assert(n > 1 && n < 500001);
        uint32_t *const data = calloc(n,sizeof(uint32_t));
        if(data) {
            printf("%"PRIu32"\n",find_minimum(data,n));
            free(data);
        } else {
            fprintf(stderr,"Memory not allocated to *data pointer!\n");
        }
    }
    return 0;
}

const uint32_t find_minimum(uint32_t *const data,uint32_t n) {
    uint32_t min_val = INT32_MAX;
    for(uint32_t i = 0; i < n; ++i) {
        scanf("%"SCNu32,&data[i]);
        assert(data[i] > 0 && data[i] < 1000000001);
        if(data[i] < min_val) {
            min_val = data[i];
        }
    }
    return min_val;
}