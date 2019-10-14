/*  Problem Statement: https://w...content-available-to-author-only...f.com/OCT19B/problems/MARM
    Author: striker
*/
 
#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<string.h>
#include<assert.h>
 
void take_input(uint32_t *const,uint32_t);
void update_sequence(uint32_t *const,uint32_t,uint64_t);
void display_sequence(uint32_t *const,uint32_t);
 
int main(void) {
    uint8_t test;
    printf("Enter the number of test-cases\n");
    scanf("%"SCNu8,&test);
    assert(test > 0 && test < 71);
    while(test--) {
        uint32_t n;
        uint64_t k;
        printf("Enter the value of n and k\n");
        scanf("%"SCNu32"%"SCNu64,&n,&k);
        assert((n > 0 &&  n < 10001) && (k > 0 && k < 1000000000001));
        uint32_t *const data = calloc(n,sizeof(uint32_t));
        if(data) {
            printf("Enter the data\n");
            take_input(data,n);
            if(n == 1) {
                data[0] = 0;
            } else {
                update_sequence(data,n,k);
            }
            // display_sequence(data,n);
            free(data);
        } else {
            fprintf(stderr,"Memory not allocated to *data pointer!\n");
        }
    }
    return 0;
}
 
void take_input(uint32_t *const data,uint32_t n) {
    for(uint32_t i = 0; i < n; ++i) {
        scanf("%"SCNu32,&data[i]);
        assert(data[i] > 0 && data[i] < 10000001);
    }
}
 
void update_sequence(uint32_t *const data,uint32_t n,uint64_t k) {
    printf("Given Sequence: ");
    display_sequence(data,n);
    printf("Updated Sequence:\n");
    for(uint64_t i = 0; i < k; ++i) {
        data[i % n] ^= (data[n - ((i % n) + 1)]);
        printf("k = %"PRIu64"\t",(i + 1));
        display_sequence(data,n);
    }
    /*
    uint32_t quotient = (k / n), remainder = (k % n);
    if(quotient) {
        uint32_t start, end;
        for(start = 0, end = (n - 1); start < end; ++start,--end) {
            for(uint32_t i = 0; i < quotient; ++i) {
                data[start] ^= data[end];
                data[end] ^= data[start];
            }
        }
        if(start == end) {
            data[start] = 0;
        }
        if(remainder) {
            for(uint32_t i = 0; i < remainder; ++i) {
                data[i] ^= data[n - i - 1];
            }
        } 
    } else {
        for(uint64_t i = 0; i < k; ++i) {
            // printf("%"PRIu64"\t%"PRIu64"\t",i,(i % n));
            uint32_t a = data[i % n];
            // printf("%"PRIu64"\t", (n - (i % n) - 1));
            uint32_t b = data[n - (i % n) - 1];
            data[i % n] = a ^ b;
            // printf("data stored at data[%"PRIu64"]: %"PRIu32"\n",(i % n), (a ^ b));
        }
    }
    */
}
 
void display_sequence(uint32_t *const data,uint32_t n) {
    for(uint32_t i = 0; i < n; ++i) {
        printf("%"PRIu32" ",data[i]);
    }
    printf("\n");
}