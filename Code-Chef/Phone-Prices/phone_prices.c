/*  Problem Statement: https://www.codechef.com/OCT19B/problems/S10E
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<assert.h>

void take_input(uint16_t *const,uint8_t);
const uint8_t find_number_of_days(uint16_t *const,uint8_t);

int main(void) {
    uint8_t test;
    scanf("%"SCNu8,&test);
    assert(test > 0 && test < 101);
    while(test--) {
        uint8_t n;
        scanf("%"SCNu8,&n);
        assert(n > 6 && n < 101);
        uint16_t *const prices = calloc(n,sizeof(uint16_t));
        if(prices) {
            take_input(prices,n);
            printf("%"SCNu8"\n",find_number_of_days(prices,n));
            free(prices);
        } else {
            fprintf(stderr,"Memory not allocated to prices pointer!\n");
        }
    }
    return 0;
}

void take_input(uint16_t *const prices,uint8_t n) {
    for(uint8_t i = 0; i < n; ++i) {
        scanf("%"SCNu16,&prices[i]);
        assert(prices[i] > 349 && prices[i] < 751);
    }
}

const uint8_t find_number_of_days(uint16_t *const prices,uint8_t n) {
    uint8_t good_price = 0;
    int8_t i,j;
    for(i = 0; i < n; ++i) {
        uint8_t limit = (i > 5 ? (i - 5) : 0);
        for(j = (i - 1); j >= limit; --j) {
            if(prices[j] <= prices[i]) {
                break;
            }
        }
        if(!(j >= limit)) {
            ++good_price;
        }
    }
    return good_price;
}