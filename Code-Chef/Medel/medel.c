/*  Problem Statement: https://www.codechef.com/problems/MDL
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<assert.h>

typedef struct sequence {
    uint8_t member;
    uint8_t index;
} sequence_t;

void insertion_sort(sequence_t *const,uint8_t);

int main(void) {
    uint8_t test;
    scanf("%"SCNu8, &test);
    assert(test > 0 && test < 75);
    while(test--) {
        uint8_t n;
        scanf("%"SCNu8, &n);
        assert(n > 2 && n < 20);
        sequence_t *const data = calloc(n,sizeof(sequence_t));
        if(data) {
            for(uint8_t i = 0; i < n; ++i) {
                scanf("%"SCNu8, &data[i].member);
                data[i].index = i;
                assert(((data[i].member) > 0) && ((data[i].member) < 110));
            }
            insertion_sort(data,n);
            if(data[0].index < data[n - 1].index) {
                printf("%"PRIu8" %"PRIu8"\n", data[0].member,data[n - 1].member);
            } else {
                printf("%"PRIu8" %"PRIu8"\n", data[n - 1].member,data[0].member);
            }
            free(data);
        } else {
            fprintf(stderr,"Not able to allocated %lu bytes\n", sizeof(n * sizeof(uint8_t)));
        }
    }
    return EXIT_SUCCESS;
}

void insertion_sort(sequence_t *const data,uint8_t n) {
    int i, j;
    for(i = 1; i < n; ++i) {
        uint8_t key = data[i].member, key_val_index = data[i].index;
        for(j = (i - 1); (j >= 0 && data[j].member > key); --j) {
            data[j + 1].member = data[j].member;
            data[j + 1].index = data[j].index;
        }
        data[j + 1].member = key;
        data[j + 1].index = key_val_index;
    }
}