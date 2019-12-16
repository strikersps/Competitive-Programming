/*  Problem Statement: https://www.codechef.com/DEC19B/problems/SUBSPLAY
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>

#define NUMBER_OF_ALPHABETS 26
#define NOT_PRESENT -1

static const int32_t compute_k(char[*]);
static const int32_t max(const int32_t,const int32_t);

int main(void) {
    int8_t test;
    scanf("%"SCNd8, &test);
    assert(test > 0 && test < 101);
    while(test--) {
        uint32_t n;
        scanf("%"SCNu32, &n);
        assert(n > 0 && n < 100001);
        char *const word = calloc((n + 1),sizeof(char));
        if(word) {
            scanf("%s", word);
            int32_t max_k = compute_k(word);
            if(max_k == NOT_PRESENT) {
                max_k = 0;
            }
            printf("%"PRId32"\n", max_k);
        } else {
            fprintf(stderr,"Line number: %u: Not able to allocate %lu bytes of memory to *word\n", __LINE__,((n + 1) * sizeof(char)));
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

static const int32_t compute_k(char word[]) {
    int32_t alphabet_occurences[NUMBER_OF_ALPHABETS], word_len = strlen(word);
    int32_t max_k = NOT_PRESENT;
    memset(alphabet_occurences,-1,(sizeof(int32_t) * NUMBER_OF_ALPHABETS));
    for(int32_t i = 0; word[i] != '\0'; ++i) {
        if(alphabet_occurences[word[i] - 'a'] == NOT_PRESENT) {
            alphabet_occurences[word[i] - 'a'] = i;
            continue;
        }
        max_k = max(max_k,(word_len - i) + alphabet_occurences[word[i] - 'a']);
        alphabet_occurences[word[i] - 'a'] = i;
    }
    return max_k;
}

static const int32_t max(const int32_t a,const int32_t b) {
    return (a > b) ? a : b;
}