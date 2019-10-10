/*  Problem Statement: 
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>
#include<assert.h>

#define NOT_FOUND -1

void take_input(uint32_t *const,uint32_t);
const uint32_t compute_gcd(uint32_t,uint32_t);
const uint32_t find_sequence_gcd(uint32_t *const,uint32_t);
const bool linear_search(uint32_t *const,uint32_t,uint32_t);

int main(void) {
    uint32_t test;
    printf("Enter the number of test cases\n");
    scanf("%"SCNu32,&test);
    assert(test > 0);
    while(test--) {
        uint32_t n;
        printf("Enter the size of the array\n");
        scanf("%"SCNu32,&n);
        assert(n > 0);
        uint32_t *const data = calloc(n,sizeof(uint32_t));
        if(data) {
            take_input(data,n);
            uint32_t seq_gcd = find_sequence_gcd(data,n);
            if(linear_search(data,n,seq_gcd)) {
                printf("%"PRIu32"\n",seq_gcd);
            } else {
                printf("%"PRId8"\n",NOT_FOUND);
            }
            free(data);
        } else {
            fprintf(stderr,"Memory not allocated to *data pointer!\n");
        }
    }
}

void take_input(uint32_t *const data,uint32_t n) {
    printf("Enter the members of the array\n");
    for(uint32_t i = 0; i < n; ++i) {
        scanf("%"SCNu32,&data[i]);
        assert(data[i] > 0);
    }
}

const uint32_t compute_gcd(uint32_t a,uint32_t b) {
    if(b == 0) {
        return a;
    } else {
        return compute_gcd(b,(a%b));
    }
}

const uint32_t find_sequence_gcd(uint32_t *const data,uint32_t n) {
    uint32_t curr_gcd = 0;
    for(uint32_t i = 0; i < n; ++i) {
        curr_gcd = compute_gcd(data[i],curr_gcd);
    }
    return curr_gcd;
}

const bool linear_search(uint32_t *const data,uint32_t n,uint32_t key) {
    bool is_found = false;
    for(uint32_t i = 0; i < n; ++i) {
        if(data[i] == key) {
            is_found = true;
            break;
        }
    }
    return is_found;
}