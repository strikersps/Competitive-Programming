/*  Problem Statement: https://www.spoj.com/problems/JAVAC/
    Author: Suraj Sharma
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<ctype.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>

#define STRING_LENGTH 101
#define JAVA_IDENTIFIER 1
#define C_PLUS_PLUS_IDENTIFIER 2
#define INVALID_IDENTIFIER -1

int8_t detect_type_of_word(char[]);
bool is_camel_case(char[]);
bool is_underscore_case(char[]);
void to_c_plus_plus(char[]);
void to_java_identifier(char[]);

int main(void) {
    char word[STRING_LENGTH];
    while(scanf("%s",word) != EOF) {
        uint16_t word_len = strlen(word);
        assert(word_len > 0 && word_len < 101);
        if(word_len > 0) {
            switch(detect_type_of_word(word)){
                case 0:
                    puts(word);
                    break;
                case 1:
                    to_c_plus_plus(word);
                    break;
                case 2:
                    to_java_identifier(word);
                    puts(word);
                    break;
                default:
                    printf("Error!\n");
                    break;
            }
        } else {
            fprintf(stderr,"Length of the word is zero!\n");
        }
    }
    return 0;
}

int8_t detect_type_of_word(char word[]) {
    if(is_camel_case(word) && is_underscore_case(word)) {
        return false;
    } else if(is_camel_case(word)) {
        return JAVA_IDENTIFIER;
    } else if(is_underscore_case(word)) {
        return C_PLUS_PLUS_IDENTIFIER;
    } else {
        return INVALID_IDENTIFIER;
    }
}

bool is_camel_case(char word[]) {
    bool is_camel = true;
    for(uint16_t i=0;(word[i]!='\0');++i) {
        if(isupper(word[0]) || (!isalpha(word[i])) || isspace(word[i])) {
            is_camel = false;
            break;
        }
    }
    return is_camel;
}

bool is_underscore_case(char word[]) {
    bool is_underscore = true;
    for(uint16_t i=0;word[i]!='\0';++i) {
        if(word[0] == '_' || (word[strlen(word) - 1] == '_') || (word[i] == '_' && word[i+1] == '_') || isupper(word[i]) || isspace(word[i])) {
            is_underscore = false;
            break;
        }
    }
    return is_underscore;
}

void to_java_identifier(char word[]) {
    uint16_t i,j,count_underscores = 0;
    for(i=0;word[i]!='\0';++i) {
        if(word[i] == '_') {
            ++count_underscores;
            word[i+1] = toupper(word[i+1]);
            for(j=i+1;word[j]!='\0';++j) {
                word[j-1] = word[j];
            }
            word[j-1] = '\0';
        }
    }
}

void to_c_plus_plus(char word[]) {
    int16_t i,j,identifier_len;
    uint8_t count_upper_case = 0;
    for(uint8_t i=0;word[i]!='\0';++i) { 
        if(isupper(word[i])) {
            ++count_upper_case;
        }
    }
    identifier_len = strlen(word) + count_upper_case + 1;
    char *identifier = calloc(sizeof(char),identifier_len);
    if(identifier) {
        for(i = (identifier_len - 2),j = (strlen(word) - 1);(i>=0 && j>=0); --i,--j ) {
            if(isupper(word[j])) {
                word[j] = tolower(word[j]);
                identifier[i] = word[j];
                identifier[--i] = '_';
            } else if(identifier[i] != '_') {
                identifier[i] = word[j];
            }
        }
        puts(identifier);
        free(identifier);
    } else {
        fprintf(stderr,"Memory not re-allocated to identifier pointer!\n");
        free(word);
    }
}