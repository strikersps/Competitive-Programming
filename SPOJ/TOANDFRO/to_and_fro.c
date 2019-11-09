/*  Problem Statement: https://www.spoj.com/problems/TOANDFRO/
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>

#define MAX_MSG_LENGTH 201

void decrypt_msg(char[],uint8_t);

int main(void) {
    while(true) {
        uint8_t tot_colns;
        scanf("%"SCNu8, &tot_colns);
        assert(tot_colns >= 0 && tot_colns < MAX_MSG_LENGTH);
        if(!tot_colns) {
            break;
        } else {
            char encrypted_msg[MAX_MSG_LENGTH];
            scanf("%s", encrypted_msg);
            decrypt_msg(encrypted_msg,tot_colns);
            printf("\n");
        }
    }
    return EXIT_SUCCESS;
}

void decrypt_msg(char encrypted_msg[],uint8_t key) {
    uint8_t encrypted_msg_len = strlen(encrypted_msg);
    for(uint8_t i = 0; i < key; ++i) {
        uint8_t counter = 0;
        for(uint8_t j = i; j < encrypted_msg_len; ++counter,j += key) {
            if(counter & 1) {
                printf("%c", encrypted_msg[(key * (counter + 1)) - (i + 1)]);
            } else {
                printf("%c", encrypted_msg[j]);
            }
        }
    }
}