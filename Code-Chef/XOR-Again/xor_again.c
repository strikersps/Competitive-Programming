/*  Problem Statement: https://www.codechef.com/problems/XORAGN
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>
#include<assert.h>

uint32_t find_xor_of_sequence(uint32_t*,uint32_t);

int main(void) {
    uint32_t test;
    scanf("%"SCNu32,&test);
    assert(test > 0 && test < 101);
    while(test--) {
        uint32_t n,*sequence;
        sequence = NULL;
        scanf("%"SCNu32,&n);
        assert(n > 0 && n < 100001);
        sequence = calloc(sizeof(uint32_t),n);
        if(sequence) {
            for(uint32_t i=0;i<n;scanf("%"SCNu32,&sequence[i]),assert(sequence[i] > 0 && sequence[i] <= (1 << 30)),++i);
            printf("%"PRIu32"\n",find_xor_of_sequence(sequence,n));
            free(sequence);
        } else {
            fprintf(stderr,"Memory not allocated to sequence pointer!\n");
        }
    }
    return 0;
}

uint32_t find_xor_of_sequence(uint32_t *sequence,uint32_t n) {
    uint32_t ans = 0;
    for(uint32_t i=0;i<n;++i) {
        ans = ans ^ (2 * sequence[i]);
    }
    return ans;
}
