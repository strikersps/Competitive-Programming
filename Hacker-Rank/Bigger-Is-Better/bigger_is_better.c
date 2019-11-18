/*  Problem Statement: https://www.hackerrank.com/challenges/bigger-is-greater/problem?h_r=internal-search
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>

#define MAX_WORD_LENGTH 101

static const bool generate_next_permutation(char[]);
static void swap_data(char *const,char *const);

int main(void) {
    uint32_t test;
    scanf("%"SCNu32, &test);
    assert(test > 0 && test < 100001);
    while(test--) {
        char word[MAX_WORD_LENGTH];
        scanf("%s", word);
        if(!generate_next_permutation(word)) {
            printf("no answer\n");
        } else {
            puts(word);
        }
    }
    return EXIT_SUCCESS;
}

static const bool generate_next_permutation(char word[]) {
    int32_t i,j;
    uint32_t word_len = strlen(word) - 1;
    if(!word_len) {
        return false;
    } else {
        for(i = word_len; (i > 0 && word[i - 1] >= word[i]); --i);
        if(!i) {
            return false; // If i == 0 implies there doesn't exist pair of numbers such that a[i - 1] > a[i] i.e given sequence is in increasing order.
        } else {
            for(j = word_len; word[j] <= word[i - 1]; --j);
            swap_data(&word[j],&word[i - 1]);
            for(j = word_len; i < j; ++i,--j) {
                swap_data(&word[i],&word[j]);
            }
        }
    }
    return true;
}

static void swap_data(char *const a,char *const b) {
    if(a != b) {
        *a = (*a) ^ (*b);
        *b = (*a) ^ (*b);
        *a = (*a) ^ (*b);
    }
}