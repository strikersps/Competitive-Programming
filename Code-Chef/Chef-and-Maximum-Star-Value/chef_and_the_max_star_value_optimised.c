/*  Problem Statement: https://www.codechef.com/problems/MSV
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<assert.h>

#define MAX_VAL 1000000
#define MAX_SIZE 100000

struct data_frequency {
    uint32_t frequency_of_data;
    uint32_t location_in_data;
};
typedef struct data_frequency data_frequency_t;

data_frequency_t* take_input(uint32_t *const,uint32_t,uint32_t*);
uint32_t* compute_divisors(uint32_t *const,uint32_t,data_frequency_t*);

int main(void) {
    uint8_t test;
    scanf("%"SCNu8,&test);
    assert(test > 0 && test < 11);
    while(test--) {
        uint32_t n;
        scanf("%"SCNu32,&n);
        assert(n > 0 && n <= MAX_SIZE);
        uint32_t *const data = calloc(n,sizeof(uint32_t));
        if(data) {
            uint32_t max_val = 0;
            data_frequency_t *const freq_data = take_input(data,n,&max_val);
            if(freq_data) {
                uint32_t *const divisors_count = compute_divisors(data,n,freq_data);
                uint32_t max_count = 0;
                for(uint32_t i = 0; i < max_val; ++i) {
                    if(divisors_count[i] > max_count) {
                        max_count = divisors_count[i];
                    }
                }
                printf("%"PRIu32"\n", max_count);
                free(divisors_count);
            } else {
                fprintf(stderr,"NULL is returned by take_input()!\n");
            }
            free(freq_data);
            free(data);
        } else {
            fprintf(stderr,"Memory not allocated to *data pointer!\n");
        }
    }
    return 0;
}

data_frequency_t* take_input(uint32_t *const data,uint32_t n,uint32_t *max_val) {
    data_frequency_t *data_freq = calloc(MAX_VAL,sizeof(data_frequency_t));
    for(uint32_t i = 0; i < MAX_VAL; (data_freq[i].frequency_of_data) = 0,++i);
    if(data_freq) {
        for(uint32_t i = 0; i < n; ++i) {
            scanf("%"SCNu32,&data[i]);
            assert(data[i] > 0 && data[i] <= MAX_VAL);
            ++data_freq[data[i] - 1].frequency_of_data;
            data_freq[data[i] - 1].location_in_data = i;
            if(data[i] > (*max_val)) {
                (*max_val) = data[i];
            }
        }
    } else {
        fprintf(stderr,"Memory not allocated to *freq_data pointer!\n");
        return NULL;
    }
    return data_freq;
}

uint32_t* compute_divisors(uint32_t *const data,uint32_t n,data_frequency_t *freq_data) {
    uint32_t *divisors_count = calloc(MAX_VAL,sizeof(uint32_t));
    if(divisors_count) {
        for(uint32_t i = 0; i < (n - 1); ++i) {
            for(uint32_t j = 1; (j * j) <= data[i]; ++j) {
                if((data[i] % j) == 0) {
                    if((freq_data[j - 1].frequency_of_data) && (freq_data[j - 1].location_in_data) > i) {
                        ++divisors_count[j - 1];
                    }
                    uint32_t quotient = data[i] / j;
                    if(j != quotient) {
                        if((freq_data[quotient - 1].frequency_of_data) && ((freq_data[quotient - 1].location_in_data) > i)) {
                            ++divisors_count[quotient - 1];
                        }
                    }
                }
            }
        }
    } else {
        fprintf(stderr,"Memory not allocated to *divisors_count pointer!\n");
    }
    return divisors_count;
}