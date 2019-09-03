/*  Problem Statement: https://www.spoj.com/problems/HANGOVER/
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>
#include<assert.h>

uint16_t find_min_cards(double);

int main(void) {
    double card_len;
    while(true) {
        fscanf(stdin,"%lf",&card_len);
        if(card_len == 0.00) break;
        assert(card_len > 0.00 && card_len < 5.21);
        fprintf(stdout,"%"PRIu16" card(s)\n",find_min_cards(card_len));
    }
    return 0;
}

uint16_t find_min_cards(double card_len) {
    double nthterm = 0.00;
    uint16_t no_of_cards = 0;
    for(uint16_t i=1;nthterm<card_len;++i) {
            nthterm += (1/(double)(i+1));
            ++no_of_cards;
    }
    return no_of_cards;
}
