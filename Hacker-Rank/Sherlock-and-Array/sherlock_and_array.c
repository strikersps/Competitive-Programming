/*  Problem Statement: https://www.hackerrank.com/challenges/sherlock-and-array/problem
    Author: Suraj Sharma
*/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

bool find_the_index(uint32_t*,uint32_t);

int main(void) {
    uint32_t test;
    scanf("%"SCNu32,&test);
    assert(test > 0 && test < 11);
    while(test--) {
        uint32_t n,*number=NULL;
        scanf("%"SCNu32,&n);
        assert(n > 0 && n < 100001);
        number = calloc(sizeof(uint32_t),n);
        if(number) {
            printf("%s",(find_the_index(number,n)?"YES\n":"NO\n"));
            free(number);
        } else {
            fprintf(stderr,"Memory not allocated to number pointer!\n");
        }
    }
    return 0;
}

bool find_the_index(uint32_t *number,uint32_t n) {
    uint32_t sum = 0;
    for(uint32_t i=0;i<n;++i) {
        scanf("%"SCNu32,&number[i]);
        assert(number[i] >= 0 && number[i] < 20001);
        sum += number[i];
    }
    uint32_t left_sum,right_sum;
    bool is_exist = false;
    left_sum = 0;
    right_sum = sum;
    for(uint32_t i=0;i<n;++i) {
        right_sum -= number[i];
        if(left_sum == right_sum) {
            is_exist = true;
            break;
        }
        left_sum += number[i];
    }
    return is_exist;
}