/*  Problem Statment: https://www.hackerrank.com/challenges/repeated-string/problem
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<string.h>
#include<assert.h>

#define MAX_STRING_LENGTH 101

static uint64_t repeated_string(char *const pattern,uint64_t);

int main(void) {
    char pattern[MAX_STRING_LENGTH];
    scanf("%s", pattern);
    uint64_t n;
    scanf("%"SCNu64, &n);
    assert(n > 0 && n < 1000000000001);
    printf("%"PRIu64"\n", repeated_string(pattern,n));
    return EXIT_SUCCESS;
}

static uint64_t repeated_string(char *const pattern,uint64_t n) {
    uint8_t pattern_len = strlen(pattern);
    uint64_t count = 0;
    for(uint8_t i = 0; pattern[i] != '\0'; ++i) {
        if(pattern[i] == 'a') {
            ++count;
        }
    }
    count *= (n / pattern_len);
    uint8_t limit = n % pattern_len;
    if(limit) {
        for(uint8_t i = 0; i < limit; ++i) {
            if(pattern[i] == 'a') {
                ++count;
            }
        }
    }
    return count;
}