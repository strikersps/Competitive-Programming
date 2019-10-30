/*  Problem Statement: https://www.codechef.com/problems/CHFAR
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<assert.h>

int main(void) {
    uint16_t test;
    scanf("%"SCNu16, &test);
    assert(test > 0 && test < 1001);
    while(test--) {
        uint32_t n,k;
        scanf("%"SCNu32"%"SCNu32, &n,&k);
        assert((n > 0 && n < 10001) && (k > 0 && k < 10001) && (k <= n));
        uint8_t *const data = calloc(n,sizeof(uint8_t));
        if(data) {
            uint32_t count_ones = 0;
            for(uint32_t i = 0; i < n; ++i) {
                scanf("%"SCNu8, &data[i]);
                assert(data[i] > 0 && data[i] < 11);
                if(data[i] == 1) {
                    ++count_ones;
                }
            }
            if((n - count_ones) <= k) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }

        } else {
            fprintf(stderr,"Not able to allocate %lu bytes of memory\n", sizeof(uint8_t) * n);
        }
    }
    return EXIT_SUCCESS;
}