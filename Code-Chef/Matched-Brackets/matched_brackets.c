/*  Problem Statement: https://www.codechef.com/ZCOPRAC/problems/ZCO12001
    Author: striker
*/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>

int main(void) {
    int32_t n;
    scanf("%"SCNd32, &n);
    assert(n > 1 && n < 100001);
    uint8_t *const bracket_sequence = calloc((size_t) n, sizeof(uint8_t));
    if(bracket_sequence) {
        int32_t open_cnt, max_depth, number_of_symbols, max_number_of_symbols;
        int32_t index_depth, index_max_symbols;
        index_depth = index_max_symbols = -1;
        open_cnt = max_depth = number_of_symbols = max_number_of_symbols = 0;
        for(int32_t i = 0; i < n; ++i) {
            scanf("%"SCNu8, &bracket_sequence[i]);
            assert(bracket_sequence[i] > 0 && bracket_sequence[i] < 3);
            ++number_of_symbols;
            if(bracket_sequence[i] == 1) {
                ++open_cnt;
                if(open_cnt > max_depth) {
                    max_depth = open_cnt;
                    index_depth = i;
                }
            } else {
                --open_cnt;
                if(!open_cnt) {
                    if(number_of_symbols > max_number_of_symbols) {
                        max_number_of_symbols = number_of_symbols;
                        index_max_symbols = (i - (max_number_of_symbols - 1));
                    }
                    number_of_symbols = 0;
                }
            }
        }
        printf("%"PRIu32" %"PRIu32" %"PRIu32" %"PRIu32"\n", max_depth, (index_depth + 1), max_number_of_symbols, (index_max_symbols + 1));
        free(bracket_sequence);
    } else {
        fprintf(stderr,"Not able to allocate %lu bytes of memory\n", (n * sizeof(uint8_t)));
    }
    return 0;
}
