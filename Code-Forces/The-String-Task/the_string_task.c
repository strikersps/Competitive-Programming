/*  Problem Statement: https://codeforces.com/problemset/problem/118/A
    Author: striker
*/

#include<stdio.h>
#include<inttypes.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>

#define STRING_LENGTH 201

void process_string(char[]);
void to_lowercase(char[]);

int main(void) {
    char petya_string[STRING_LENGTH];
    memset(petya_string,'\0',sizeof(char)*STRING_LENGTH);
    scanf("%s",petya_string);
    process_string(petya_string);
    puts(petya_string);
    return 0;
}

void process_string(char petya_string[]) {
    to_lowercase(petya_string);
    for(uint16_t i = 0; petya_string[i] != '\0'; ++i) {
        if(petya_string[i] == 'a' || petya_string[i] == 'o' || petya_string[i] == 'y' || petya_string[i] == 'e' || petya_string[i] == 'u' || petya_string[i] == 'i') {
            for(uint16_t j = i; petya_string[j] != '\0'; ++j) {
                petya_string[j] = petya_string[j+1];
            }
            --i;
        }
    }
    uint16_t len = strlen(petya_string);
    for(int16_t i = len - 1; i >= 0; --i) {
        petya_string[(i << 1) + 1] = petya_string[i];
        petya_string[i << 1] = '.';
    }
}

void to_lowercase(char petya_string[]) {
    for(uint16_t i = 0; petya_string[i] != '\0'; ++i) {
        if(isupper(petya_string[i])) {
            petya_string[i] = tolower(petya_string[i]);
        }
    }
}