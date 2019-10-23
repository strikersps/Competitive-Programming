/*  Problem Statement: https://www.codechef.com/problems/RECIPE
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<assert.h>

uint16_t compute_gcd(uint16_t,uint16_t);

int main(void) {
    uint8_t test;
    scanf("%"SCNu8, &test);
    assert(test > 0 && test < 101);
    while(test--) {
        uint8_t n;
        scanf("%"SCNu8, &n);
        uint16_t *const ingredients_qty = calloc(n,sizeof(uint16_t));
        if(ingredients_qty) {
            uint16_t gcd_val = 0;
            for(uint8_t i = 0; i < n; ++i) {
                scanf("%"SCNu16, &ingredients_qty[i]);
                assert(ingredients_qty[i] > 0 && ingredients_qty[i] < 1001);
                if(i == 0) {
                    gcd_val = ingredients_qty[i];
                } else {
                    gcd_val = compute_gcd(gcd_val,ingredients_qty[i]);
                }
            }
            for(uint16_t i = 0; i < n; ++i) {
                ingredients_qty[i] /= gcd_val;
                printf("%"PRIu16" ", ingredients_qty[i]);
            }
            printf("\n");
            free(ingredients_qty);
        } else {
            fprintf(stderr,"Not able to allocate memory of %lu bytes", sizeof(n*sizeof(uint16_t)));
        }
    }
    return EXIT_SUCCESS;
}

uint16_t compute_gcd(uint16_t a,uint16_t b) {
    if(b == 0) {
        return a;
    } else {
        return compute_gcd(b,(a%b));
    }
}