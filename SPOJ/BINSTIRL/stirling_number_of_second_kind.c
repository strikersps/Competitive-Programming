/*  Problem Statement: https://www.spoj.com/problems/BINSTIRL/
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<string.h>
#include<assert.h>

const uint32_t compute_stirling_number_of_second_kind(uint32_t,uint32_t);

int main(void) {
    uint32_t test;
    scanf("%"SCNu32, &test);
    assert(test > 0 && test < 201);
    while(test--) {
        uint32_t n,m;
        scanf("%"SCNu32"%"SCNu32, &n,&m);
        assert((n > 0 && n < 1000000001) && (m > 0 && m < 1000000001));
        printf("%"PRIu32"\n", compute_stirling_number_of_second_kind((n + 1),(m + 1)));
    }
    return EXIT_SUCCESS;
}

const uint32_t compute_stirling_number_of_second_kind(uint32_t n,uint32_t m) {
    uint8_t *const data_storage = calloc((m + 1),sizeof(uint8_t));
    data_storage[0] = 1;
    for(uint32_t i = 0; i < n; ++i) {
        for(int32_t j = (m - 1); j >= 0; --j) {
            if(j > i) {
                data_storage[j] = 0;
            } else if(i > 0 && j == 0) {
                data_storage[j] = 0;
            }
            else if(j == i) {
                data_storage[j] = 1;
            } else {
                data_storage[j] = (((j % 2) * (data_storage[j] % 2)) + (data_storage[j - 1] % 2)) % 2;
            }
        }
    }
    uint32_t ans = data_storage[m - 1];
    free(data_storage);
    return ans;
}