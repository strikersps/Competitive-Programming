/*  Problem Statement: https://www.codechef.com/problems/PALL01
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>

#define MAX_SIZE 10001

const bool check_palindrome(char *const);

int main(void) {
    uint8_t test;
    scanf("%"SCNu8, &test);
    assert(test > 0 && test < 21);
    while(test--) {
        char number_base10[MAX_SIZE];
        scanf("%s", number_base10);
        if(check_palindrome(number_base10)) {
            printf("wins\n");
        } else{
            printf("losses\n");
        }
    }
    return 0;
}

const bool check_palindrome(char *const number_base10) {
    bool is_palindrome = true;
    for(uint32_t start = 0, end = strlen(number_base10) - 1; start < end; ++start,--end) {
        if(number_base10[start] != number_base10[end]) {
            is_palindrome = false;
            break;
        }
    }
    return is_palindrome;
}