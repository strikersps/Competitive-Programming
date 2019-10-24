/*  Problem Statement: https://www.codechef.com/NPLQ2019/problems/NPLQ19D
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>

#define MAX_SIZE 100001
#define NO_OF_ALPHABETS 26

int main(void) {
    uint8_t test;
    scanf("%"SCNu8, &test);
    assert(test > 0 && test < 11);
    while(test--) {
        char place_visited[MAX_SIZE];
        scanf("%s", place_visited);
        bool hash_table_alphabets[NO_OF_ALPHABETS];
        memset(hash_table_alphabets,false,(NO_OF_ALPHABETS * sizeof(bool)));
        for(uint32_t i = 0; place_visited[i] != '\0'; ++i) {
            if(!hash_table_alphabets[place_visited[i] - 97]) {
                printf("%c", place_visited[i]);
                hash_table_alphabets[place_visited[i] - 97] = true;
            }
        }
        printf("\n");
    }
    return 0;
}