/*  Problem Statement: https://www.hackerrank.com/challenges/new-year-chaos/problem
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>
#include<assert.h>

static uint32_t minimum_no_of_bribes(uint32_t[*],uint32_t);
static void swap_data(uint32_t *const,uint32_t *const);

int main(void) {
    int8_t test;
    scanf("%"SCNd8, &test);
    assert(test > 0 && test < 11);
    while(test--) {
        uint32_t n;
        scanf("%"SCNu32, &n);
        assert(n > 0 && n < 100001);
        uint32_t final_state[n];
        for(uint32_t i = 0; i < n; ++i) {
            scanf("%"SCNu32, &final_state[i]);
            assert(final_state[i] > 0 && final_state[i] <= n);
        }
        uint32_t min_bribe = minimum_no_of_bribes(final_state,n);
        if(!min_bribe) {
            printf("Too chaotic\n");
        } else {
            printf("%"PRIu32"\n", min_bribe);
        }
    }
    return EXIT_SUCCESS;
}

static uint32_t minimum_no_of_bribes(uint32_t final_state[],uint32_t n) {
    uint32_t min_bribe = 0;
    bool is_chaotic = false;
    for(int32_t i = (n - 1); i >= 0; --i) {
        if(!(final_state[i] == (i + 1))) {
            if((i > 0) && ((i + 1) == final_state[i - 1])) {
                ++min_bribe;
                swap_data(&final_state[i],&final_state[i - 1]);
            } else if((i > 1) && ((i + 1) == final_state[i - 2])) {
                min_bribe += 2;
                swap_data(&final_state[i - 2],&final_state[i - 1]);
                swap_data(&final_state[i - 1],&final_state[i]);
            } else {
                is_chaotic = true;
                break;
            }
        }
    }
    if(is_chaotic) {
        return 0;
    } else {
        return min_bribe;
    }
}

static void swap_data(uint32_t *const a,uint32_t *const b) {
    if(!(a == b)) {
        (*a) = (*a) ^ (*b);
        (*b) = (*a) ^ (*b);
        (*a) = (*a) ^ (*b);
    } else {
        fprintf(stderr,"Line Number: %u Both *a and *b are pointing to same memory location\n", __LINE__);
    }
}