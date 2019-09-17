/*  Problem Statement: https://codeforces.com/problemset/problem/158/A
    Author: striker
*/

#include<stdio.h>
#include<inttypes.h>
#include<stdlib.h>
#include<assert.h>

uint8_t calculate_total_participants(uint8_t*,uint8_t,uint8_t);

int main(void) {
    uint8_t n,k;
    scanf("%"SCNu8"%"SCNu8,&n,&k);
    assert((n > 0 && n < 51) && (k <= n && k < 51));
    uint8_t *score = calloc(sizeof(uint8_t),n);
    if(score) {
        for(uint8_t i = 0; i < n; ++i) {
            scanf("%"SCNu8,&score[i]);
            assert(score[i] >= 0 && score[i] < 101);
        }
        uint8_t total_participants = calculate_total_participants(score,n,k);
        printf("%"PRIu8"\n",total_participants);
        free(score);
    } else {
        fprintf(stderr,"Memory not allocated to score pointer!\n");
    }
    return 0;
}

uint8_t calculate_total_participants(uint8_t* score,uint8_t n,uint8_t k) {
    uint8_t tot_participants = 0;
    if(score[k - 1]) {
        tot_participants = k;
        for(uint8_t i = k - 1; (i < n - 1) && score[i] == score[i + 1]; ++tot_participants,++i);
    } else {
        for(uint8_t i = 0; (i < k) && score[i]; ++tot_participants,++i);
    }
    return tot_participants;
}