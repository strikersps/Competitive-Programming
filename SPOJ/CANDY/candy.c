/*  Problem Statement: https://www.spoj.com/problems/CANDY/
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<assert.h>

uint32_t find_total_chocolates(uint16_t*,uint16_t);

int main(void) {
    int16_t n; // Number of candy packets.
    do {
        scanf("%"SCNu16,&n);
        if(n > 0) {
            uint16_t *chocolates_in_pack = calloc(sizeof(uint16_t),n);
            if(chocolates_in_pack) {
                uint32_t total_chocolates = find_total_chocolates(chocolates_in_pack,n);
                if(!(total_chocolates % n)) {
                    uint32_t min_number_of_moves = 0;
                    uint32_t mean = total_chocolates / n;
                    for(uint16_t i=0;i<n;++i) {
                        if(chocolates_in_pack[i] > mean) {
                            min_number_of_moves += (chocolates_in_pack[i] - mean);
                        }
                    }
                    printf("%"PRIu32"\n",min_number_of_moves);
                    free(chocolates_in_pack);
                } else {
                    printf("-1\n");
                }
            } else {
                fprintf(stderr,"Memory not allocated to *chocolates_in_pack pointer!\n");
            }

        }
    } while(n != (-1));
    return 0;
}

uint32_t find_total_chocolates(uint16_t *chocolates_in_pack,uint16_t n) {
    uint32_t total_chocolates = 0;
    for(uint16_t i=0;i<n;++i) {
        scanf("%"SCNu16,&chocolates_in_pack[i]);
        assert(chocolates_in_pack[i] > 0 && chocolates_in_pack[i] < 1001);
        total_chocolates += chocolates_in_pack[i];
    }
    return total_chocolates;
}
