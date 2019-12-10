/*  Problem Statement: https://www.codechef.com/DEC19B/problems/PLMU
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<assert.h>

int main(void) {
    uint8_t test;
    scanf("%"SCNu8, &test);
    assert(test > 0 && test < 21);
    while(test--) {
        uint16_t n;
        scanf("%"SCNu16, &n);
        assert(n > 0 && n < 40001);
        uint32_t *const data = calloc(sizeof(uint32_t),n);
        if(data) {
            uint64_t count_of_zeroes,count_of_twos;
            count_of_zeroes = count_of_twos = 0;
            for(uint16_t i = 0; i < n; ++i) {
                scanf("%"SCNu32, &data[i]);
                assert(data[i] >= 0 && data[i] < 1000000001);
                if(!data[i]) {
                    ++count_of_zeroes;
                } else if(data[i] == 2) {
                    ++count_of_twos;
                }
            }
            printf("%"PRIu64"\n", ((count_of_zeroes * (count_of_zeroes - 1)) >> 1) + ((count_of_twos * (count_of_twos - 1)) >> 1));
            free(data);
        } else {
            fprintf(stderr,"Line number:%u: Not able to allocate %lu bytes of memory to *data\n", __LINE__,(sizeof(uint32_t) * n));
        }
    }
    return EXIT_SUCCESS;
}