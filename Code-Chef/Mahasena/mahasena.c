/*  Problem Statement: https://www.codechef.com/problems/AMR15A
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<assert.h>

int main(void) {
    uint32_t n;
    scanf("%"SCNu32, &n);
    uint32_t *const total_soldiers = calloc(n,sizeof(uint32_t));
    if(total_soldiers) {
        uint32_t even_count,odd_count;
        even_count = odd_count = 0;
        for(uint32_t i = 0; i < n; ++i) {
            scanf("%"SCNu32, &total_soldiers[i]);
            assert(total_soldiers[i] > 0 && total_soldiers[i] < 101);
            if(total_soldiers[i] & 1) {
                ++odd_count;
            } else {
                ++even_count;
            }
        }
        if(even_count > odd_count) {
            printf("READY FOR BATTLE\n");
        } else {
            printf("NOT READY\n");
        }
        free(total_soldiers);
    } else {
        fprintf(stderr,"Memory not allocated to *total_soldiers!\n");
    }
    return EXIT_SUCCESS;
}