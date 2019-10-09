/*  Problem Statement: https://www.geeksforgeeks.org/queries-counts-multiples-array/
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<string.h>
#include<assert.h>

uint32_t* find_all_multiples(uint32_t[],uint32_t,uint32_t);

int main(void) {
    uint32_t n,max_val = 0;
    printf("Enter the size of the sequence\n");
    scanf("%"SCNu32,&n);
    uint32_t data[n];
    printf("Enter the data\n");
    for(uint32_t i = 0; i < n; ++i) {
        scanf("%"SCNu32,&data[i]);
        assert(data[i] > 0);
        if(data[i] > max_val) {
            max_val = data[i];
        }
    }
    uint32_t *const multiples = find_all_multiples(data,n,max_val);
    uint32_t query;
    printf("Enter the number of queries\n");
    scanf("%"SCNu32,&query);
    while(query--) {
        uint32_t num;
        scanf("%"SCNu32,&num);
        if(num > max_val) {
            printf("0\n");
        } else {
            printf("%"PRIu32"\n",multiples[num - 1]);
        }
    }
    free(multiples);
    return 0;
}

uint32_t* find_all_multiples(uint32_t data[],uint32_t n,uint32_t max_val) {
    uint32_t *const freq_data = calloc(max_val,sizeof(uint32_t));
    for(uint32_t i = 0; i < n; ++i) {
        ++freq_data[data[i] - 1];
    }
    uint32_t *const multiples = calloc(max_val,sizeof(uint32_t));
    multiples[0] = n - 1;
    for(uint32_t i = 2; i <= max_val; ++i) {
        for(uint32_t j = i; j <= max_val; (j += i)) {
            multiples[i - 1] += freq_data[j - 1];
        }
    }
    for(uint32_t i = 0; i < max_val; ++i) {
        printf("%"PRIu32" ",multiples[i]);
    }
    printf("\n");
    free(freq_data);
    return multiples;
}