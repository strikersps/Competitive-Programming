/*  Problem Statement: https://www.codechef.com/problems/ALTARAY
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<assert.h>

typedef struct sequence {
    int32_t data;
    uint32_t len_of_longest_alt_seq;
} sequence_t;

void find_longest_alternating_seq(sequence_t *const, uint32_t);

int main(void) {
    #ifndef ONLINE_JUDGE
        freopen("test-cases/test-case-1.in", "r", stdin);
        freopen("test-cases/test-case-1.out", "w", stdout);
    #endif
    uint8_t test;
    scanf("%"SCNu8, &test);
    assert(test > 0 && test < 11);
    while(test--) {
        uint32_t n;
        scanf("%"SCNu32, &n);
        assert(n > 0 && n < 100001);
        sequence_t *const sequence = calloc(n, sizeof(sequence_t));
        if(sequence) {
            for(uint32_t i= 0; i < n; ++i) {
                scanf("%"SCNd32, &sequence[i].data);
                sequence[i].len_of_longest_alt_seq = 1;
            }
            find_longest_alternating_seq(sequence, n);
            for(uint32_t i = 0; i < n; ++i) {
                printf("%"PRIu32" ", sequence[i].len_of_longest_alt_seq);
            }
            printf("\n");
            free(sequence);
        } else {
            fprintf(stderr,"Not able to allocate %lu bytes of memory!\n", (n * sizeof(int32_t)));
        }
    }
    return EXIT_SUCCESS;
}

void find_longest_alternating_seq(sequence_t *const sequence, uint32_t n) {
    for(int32_t i = (n - 2); i >= 0; --i) {
        if((sequence[i].data > 0 && sequence[i + 1].data < 0) || (sequence[i].data < 0 && sequence[i + 1].data > 0)) {
            sequence[i].len_of_longest_alt_seq = sequence[i + 1].len_of_longest_alt_seq + 1;
        }
    }
}
