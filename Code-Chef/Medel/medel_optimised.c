/*  Problem Statement: https://www.codechef.com/problems/MDL
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<assert.h>

int main(void) {
    uint8_t test;
    scanf("%"SCNu8, &test);
    assert(test > 0 && test < 75);
    while(test--) {
        uint8_t n;
        scanf("%"SCNu8, &n);
        assert(n > 2 && n < 20);
        uint8_t *const data = calloc(n,sizeof(uint8_t));
        if(data) {
            uint8_t min_val, min_val_index, max_val, max_val_index;
            min_val = INT8_MAX;
            max_val = 0;
            for(uint8_t i = 0; i < n; ++i) {
                scanf("%"SCNu8, &data[i]);
                assert(data[i] > 0 && data[i] < 110);
                if(data[i] > max_val) {
                    max_val = data[i];
                    max_val_index = i;
                } 
                if(data[i] < min_val) {
                    min_val = data[i];
                    min_val_index = i;
                }
            }
            if(max_val_index > min_val_index) {
                printf("%"PRIu8" %"PRIu8"\n", min_val, max_val);
            } else {
                printf("%"PRIu8" %"PRIu8"\n", max_val,min_val);
            }
            free(data);
        } else {
            fprintf(stderr,"Not able to allocate to %lu bytes of memory!\n", n * sizeof(uint8_t));
        }
    }
    return EXIT_SUCCESS;
}