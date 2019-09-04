/*  Problem Statement: https://www.hackerrank.com/challenges/circular-array-rotation/problem
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<assert.h>

int main(void) {
    uint32_t m,n,k;
    uint32_t *number = NULL;
    uint16_t queries;
    scanf("%"SCNu32"%"SCNu32"%"SCNu16,&n,&k,&queries);
    assert((n > 0 && n < 100001) && (k > 0 && k < 100001) && (queries > 0 && queries < 501));
    number = calloc(sizeof(uint32_t),n);
    if(number) {
        for(uint32_t i=0;i<n;++i) {
            scanf("%"SCNu32,&number[(i+k)%n]);
        }
        for(uint16_t i=0;i<queries;++i) {
            scanf("%"SCNu32,&m);
            assert(m >= 0 && m < n);
            printf("%"PRIu32"\n",number[m]);
        }
        free(number);
    } else {
        fprintf(stderr,"Memory not allocated to pointer *number!\n");
    }
    return 0;
}