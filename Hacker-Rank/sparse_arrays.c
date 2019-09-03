/*  Problem Statement: https://www.hackerrank.com/challenges/sparse-arrays/problem
    Author: Suraj Sharma
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<assert.h>

#define COLUMNS 21

uint16_t find_occurences_of_string(char**,uint16_t,char[]);
void free_memory(char**,uint16_t);

int main(void) {
    uint16_t n,q;
    char **dict = NULL;
    scanf("%"SCNu16,&n);
    assert(n > 0 && n < 1001);
    dict = calloc(sizeof(char*),n);
    if(dict) {
        for(uint16_t i=0;i<n;++i) {
            dict[i] = calloc(sizeof(char),COLUMNS);
            scanf("%s",dict[i]);
        }
        scanf("%"SCNu16,&q);
        assert(q > 0 && q < 1001);
        char query_string[COLUMNS];
        uint16_t occurrence_of_data[q];
        for(uint16_t i=0;i<q;++i) {
            scanf("%s",query_string);
            occurrence_of_data[i] = find_occurences_of_string(dict,n,query_string);
        }
        for(uint16_t i=0;i<q;++i) {
            printf("%"PRIu16"\n",occurrence_of_data[i]);
        }
        free_memory(dict,n);

    } else {
        fprintf(stderr,"Memory not allocated to **dict pointer!\n");
    }
    return 0;
}

uint16_t find_occurences_of_string(char **dict,uint16_t n,char query_string[]) {
    uint16_t count = 0;
    for(uint16_t i=0;i<n;++i) {
        if(!(strcmp(dict[i],query_string))) {
            ++count;
        }
    }
    return count;
}

void free_memory(char **dict,uint16_t n) {
    for(uint16_t i=0;i<n;++i) {
        free(dict[i]);
    }
    free(dict);
}