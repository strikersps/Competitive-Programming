/*  Problem Statement: https://www.codechef.com/problems/LAPIN
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>

#define MAX_SIZE 1001
#define TOTAL_ALPHABETS 26

const bool check_lapindrome(char[]);

int main(void) {
    uint8_t test;
    scanf("%"SCNu8, &test);
    assert(test > 0 && test < 101);
    while(test--) {
        char word[MAX_SIZE];
        scanf("%s", word);
        printf("%s", (check_lapindrome(word) ? "YES\n" : "NO\n"));
    }
    return EXIT_SUCCESS;
}

const bool check_lapindrome(char word[]) {
    bool is_lapindrome = true;
    uint16_t alphabet_freq[TOTAL_ALPHABETS];
    memset(alphabet_freq,0,(sizeof(uint16_t) * TOTAL_ALPHABETS));
    uint16_t word_len = strlen(word), mid;
    mid = word_len >> 1;
    for(uint16_t i = 0; word[i] != '\0'; ++i) {
        if(i < mid) {
            ++alphabet_freq[word[i] - 'a'];
        } else if(word_len & 1) {
            if(i > mid) {
                if (alphabet_freq[word[i] - 'a']) {
                    --alphabet_freq[word[i] - 'a'];
                }
            }
        } else {
            if(alphabet_freq[word[i] - 'a']) {
                --alphabet_freq[word[i] - 'a'];
            }
        }
    }
    for(uint16_t i = 0; i < TOTAL_ALPHABETS; ++i) {
        if(alphabet_freq[i]) {
            is_lapindrome = false;
            break;
        }
    }
    return is_lapindrome;
}