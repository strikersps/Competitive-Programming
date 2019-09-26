/*  Problem Statement: https://www.codechef.com/problems/CLFIBD
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<inttypes.h>
#include<stdbool.h>
#include<assert.h>

#define STRING_LENGTH 100001
#define FREQUENCY_ARRAY_LENGTH 26

bool check_dynamic(char[]);
bool check_sorted(uint32_t[],uint32_t);
void insertion_sort(uint32_t[],uint32_t);

int main(void) {
    uint8_t test;
    scanf("%"SCNu8,&test);
    assert(test > 0 && test < 11);
    while(test--) {
        char user_string[STRING_LENGTH];
        memset(user_string,'\0',(sizeof(char) * STRING_LENGTH));
        scanf("%s",user_string);
        if(check_dynamic(user_string)) {
            printf("Dynamic\n");
        } else {
            printf("Not\n");
        }
    }
    return 0;
}

bool check_dynamic(char user_string[]) {
    uint32_t frequency_dist[FREQUENCY_ARRAY_LENGTH];
    memset(frequency_dist,0,(sizeof(uint32_t) * FREQUENCY_ARRAY_LENGTH));
    uint32_t unique_char = 0;
    for(uint32_t i = 0; user_string[i] != '\0'; ++i) {
        uint8_t index = user_string[i] - 'a';
        if(!frequency_dist[index]) {
            ++unique_char;
        }
        ++frequency_dist[index];
    }
    bool is_dynamic = true;
    if(unique_char < 3) {
        return is_dynamic;
    } else {
        uint32_t present_char_freq[unique_char];
        memset(present_char_freq,0,(sizeof(uint32_t) * unique_char));
        for(uint32_t i = 0, j = 0; ((i < FREQUENCY_ARRAY_LENGTH) && (j < unique_char)); ++i) {
            if(frequency_dist[i]) {
                present_char_freq[j++] = frequency_dist[i];
            }
        }
        if(!check_sorted(present_char_freq,unique_char)) {
            insertion_sort(present_char_freq,unique_char);
        }
        if(present_char_freq[3] != present_char_freq[2] + present_char_freq[1]) {
            present_char_freq[0] = present_char_freq[0] ^ present_char_freq[1];
            present_char_freq[1] = present_char_freq[0] ^ present_char_freq[1];
            present_char_freq[0] = present_char_freq[0] ^ present_char_freq[1];
        }
        for(uint32_t i = 2; i < unique_char; ++i) {
            if(present_char_freq[i] != (present_char_freq[i - 1] + present_char_freq[i - 2])) {
                is_dynamic = false;
                break;
            }
        }
    }
    return is_dynamic;
}

bool check_sorted(uint32_t data[],uint32_t size) {
    bool is_sorted = true;
    for(uint32_t i = 0; i < (size - 1); ++i) {
        if(data[i] > data[i + 1]) {
            is_sorted = false;
            break;
        }
    }
    return is_sorted;
}

void insertion_sort(uint32_t data[],uint32_t size) {
    for(uint32_t i = 1; i < size; ++i) {
        uint32_t key = data[i];
        int32_t j;
        for(j = i - 1;(j >= 0 && key < data[j]); data[j + 1] = data[j],--j);
        data[j + 1] = key;
    }
}