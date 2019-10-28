/*  Problem Statement: https://leetcode.com/problems/defanging-an-ip-address/
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#define MAX_SIZE 21

char* defangIPaddr(char*);

int main(void) {
    char ip_address[MAX_SIZE];
    scanf("%s", ip_address);
    char *const defang_ip_address = defangIPaddr(ip_address);
    puts(defang_ip_address);
    return EXIT_SUCCESS;
}

char* defangIPaddr(char * address){
    char *defang_ip_address = calloc((strlen(address) + 7),sizeof(char));
    if(defang_ip_address) {
        int i,j;
        for(i = 0, j = 0; address[i] != '\0'; ++i) {
            if(address[i] == '.') {
                defang_ip_address[j++] = '[';
                defang_ip_address[j++] = '.';
                defang_ip_address[j++] = ']';
            } else {
                defang_ip_address[j++] = address[i];
            }
        }
        defang_ip_address[j] = '\0';
    } else {
        fprintf(stderr,"Not able to allocate %lu bytes of memory!\n", (strlen(address) + 7) * sizeof(char));
    }
    return defang_ip_address;
}