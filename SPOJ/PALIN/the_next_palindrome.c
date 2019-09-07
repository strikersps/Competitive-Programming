/*  Problem Statement: https://www.spoj.com/problems/PALIN/
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>

#define STRING_LENGTH 1000002

bool check_palindrome(char[]);
bool check_all_nines(char[]);
void find_next_palindrome(char[]);

int main(void) {
    uint64_t test;
    scanf("%"SCNu64,&test);
    assert(test > 0);
    while(test--) {
        char number_base_10[STRING_LENGTH];
        memset(number_base_10,'\0',(sizeof(char)*STRING_LENGTH));
        scanf("%s",number_base_10);
        uint32_t string_len = strlen(number_base_10);
        assert(string_len > 0);
        if(check_all_nines(number_base_10)) {
            for(uint32_t i=0;i<=string_len;++i) {
                if(i == 0 || i == (string_len)) {
                    number_base_10[i] = '1';
                } else {
                    number_base_10[i] = '0';
                }
            }
        } else {
            find_next_palindrome(number_base_10);
        }
        puts(number_base_10);
    }
    return 0;
}

bool check_all_nines(char number[]) {
    bool is_all_nines = true;
    for(uint32_t i=0;number[i]!='\0';++i) {
        if(!(number[i] == '9')) {
            is_all_nines = false;
            break;
        }
    }
    return is_all_nines;
}

bool check_palindrome(char number[]) {
    bool is_palindrome = true;
    for(uint32_t start = 0,end = (strlen(number) - 1);(start < end);++start,--end) {
        if(!(number[start] == number[end])) {
            is_palindrome = false;
            break;
        }
    }
    return is_palindrome;
}

void find_next_palindrome(char number[]) {
    uint32_t str_len = strlen(number);
    if(check_palindrome(number)) {
        uint32_t start,mid,end;
        start = 0;
        end = str_len - 1;
        mid = ((end - start) >> 1) + start;
        for(start = mid,(end = (str_len & 1) ? mid : (mid + 1)); (start >= 0 && end < str_len) && (number[start] == '9'); --start,++end) {
            number[end] = number[start] = '0';
        }
        if(start >= 0 && end < str_len) {
            number[start]++;
            number[end] = number[start];
        }
    } else {
        uint32_t start,mid,end;
        bool flag = false;
        start = 0;
        end = str_len - 1;
        mid = ((end - start) >> 1) + start;
        for(start = mid, end = ((str_len & 1) ? mid: (mid + 1)); (start >=0 && end < str_len) && (number[start] == number[end]); --start,++end);
        if(number[start] < number[end]) {
            flag = true;
            number[end] = number[start];
        }
        if(flag) {
            for(start = mid, end = ((str_len & 1) ? mid : (mid + 1)); (start >=0 && end < str_len) && (number[start] == '9'); --start,++end) {
                number[end] = number[start] = '0';
            }
            if(start >=0 && end < str_len) {
                number[start]++;
                number[end] = number[start];
            }
        }
        for(start = 0, end = str_len - 1; (start < end); ++start,--end) {
            number[end] = number[start];
        }
    }
}
