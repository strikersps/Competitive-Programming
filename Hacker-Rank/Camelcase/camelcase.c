/*  Problem Statement: https://www.hackerrank.com/challenges/camelcase/problem
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>

#define STRING_LENGTH 100001

uint16_t find_no_of_words(char[]);

int main(void) {
    char word[STRING_LENGTH];
    scanf("%s",word);
    uint16_t word_len = strlen(word);
    assert(word_len > 0 && word_len < STRING_LENGTH);
    if(word_len > 0) {
        printf("%"PRIu32"\n",find_no_of_words(word));
    } else {
        fprintf(stderr,"Length of the string is zero!\n");
    }
}

uint16_t find_no_of_words(char word[]) {
    uint32_t count_words = 1;
    for(uint32_t i=0;word[i]!='\0';++i) {
        if(isupper(word[i])) {
            ++count_words;
        }
    }
    return count_words;
}