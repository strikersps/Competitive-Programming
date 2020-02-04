/*  Problem Statement: https://www.hackerrank.com/challenges/maximum-xor/problem
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<assert.h>

int main(void) {
    uint32_t n,queries;
    scanf("%"SCNu32, &n);
    assert(n > 0 && n < 100001);
    uint32_t data[n];
    for(uint32_t i = 0; i < n; ++i) {
        scanf("%"SCNu32, &data[i]);
        assert(data[i] >= 0 && data[i] < 1000000001);
    }
    scanf("%"SCNu32, &queries);
    assert(queries > 0 && queries < 100001);
    while(queries--) {
        uint32_t number;
        scanf("%"SCNu32, &number);
        assert(number >= 0 && number < 1000000001);
        uint32_t xor_val,max_xor_val = 0;
        for(uint32_t i = 0; i < n; ++i) {
            xor_val = data[i] ^ number;
            if(xor_val > max_xor_val) {
                max_xor_val = xor_val;
            }
        }
        printf("%"PRIu32"\n", max_xor_val);
    }
    return EXIT_SUCCESS;
}