/*  Problem Statement: https://www.codechef.com/OCT19B/problems/MARM
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<math.h>
#include<string.h>
#include<assert.h>

void take_input(uint32_t *const,uint32_t);
void update_sequence(uint32_t *const,uint32_t,uint32_t);
void display_sequence(uint32_t *const,uint32_t);

int main(void) {
    uint8_t test;
    // printf("Enter the number of test-cases\n");
    scanf("%"SCNu8,&test);
    assert(test > 0 && test < 71);
    while(test--) {
        uint32_t n;
        uint64_t k;
        // printf("Enter the value of n and k\n");
        scanf("%"SCNu32"%"SCNu64,&n,&k);
        assert((n > 0 &&  n < 10001) && (k > 0 && k < 1000000000001));
        uint32_t *const data = calloc(n,sizeof(uint32_t));
        if(data) {
            take_input(data,n);
            if(n == 1) {
                data[0] = 0;
            } else {
                if(k < n) {
                    update_sequence(data,n,k);
                } else {
                    if(n & 1) {
                        data[n >> 1] = 0;
                    }
                    if(k % (3 * n)) {
                        k %= (3 * n);
                        update_sequence(data,n,k);
                    }
                }
            }
            display_sequence(data,n);
            free(data);
        } else {
            fprintf(stderr,"Memory not allocated to *data pointer!\n");
        }
    }
    return 0;
}

void take_input(uint32_t *const data,uint32_t n) {
    for(uint32_t i = 0; i < n; ++i) {
        scanf("%"SCNu32,&data[i]);
        assert(data[i] > 0 && data[i] < 10000001);
    }
}

void update_sequence(uint32_t *const data,uint32_t n,uint32_t k) {
    for(uint32_t i = 0; i < k; ++i) {
        data[i % n] ^= data[n - ((i % n) + 1)];
    }
}

void display_sequence(uint32_t *const data,uint32_t n) {
    for(uint32_t i = 0; i < n; ++i) {
        printf("%"PRIu32" ",data[i]);
    }
    printf("\n");
}