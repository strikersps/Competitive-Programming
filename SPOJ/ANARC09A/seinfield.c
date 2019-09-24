/*  Problem Statement: https://www.spoj.com/problems/ANARC09A/
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>

#define SEQUENCE_SIZE 2001

const uint64_t minimum_no_operation(char[]);

int main(void) {
    char bracket_seq[SEQUENCE_SIZE];
    uint16_t test;
    test = 0;
    while(true) {
        ++test;
        scanf("%s",bracket_seq);
        if(!(bracket_seq[0] == '-')) {
            const uint16_t len = strlen(bracket_seq);
            if(!(len & 1)) {
                printf("%"PRIu16". %"PRIu64"\n",test,minimum_no_operation(bracket_seq));
            } else fprintf(stderr,"Length of the string should be even!\n");
        } else break;
    }
    return 0;
}

const uint64_t minimum_no_operation(char bracket_seq[]) {
    uint16_t open_cnt,min_no_ops;
    open_cnt = min_no_ops = 0;
    for(uint16_t i=0; bracket_seq[i] != '\0'; ++i) {
        if(bracket_seq[i] == '{') {
            ++open_cnt;
	    } else {
            if(!open_cnt) {
                ++min_no_ops;
                ++open_cnt;
            } else {
                --open_cnt;
            }
        }
    }
    return ((open_cnt>>1) + min_no_ops);
}
