/*  Problem Statement: https://www.codechef.com/problems/RAINBOWA
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>
#include<assert.h>

#define LIMIT 7

bool take_input(uint8_t *const,uint8_t); // Returns true if the array consists of elements only between 1 and 7 other-wise returns false.
bool check_rainbow(uint8_t *const,uint8_t);

int main(void) {
    uint8_t test;
    scanf("%"SCNu8,&test);
    assert(test > 0 && test< 101);
    while(test--) {
        uint8_t n;
        scanf("%"SCNu8,&n);
        assert(n > 6 && n < 101);
        uint8_t *const data = calloc(n,sizeof(uint8_t));
        if(data) {
            if(!take_input(data,n)) {
                if(n > 12) {
                    if(check_rainbow(data,n)) {
                        printf("yes\n");
                    } else {
                        printf("no\n");
                    }
                } else {
                    printf("no\n");
                }
            } else {
                printf("no\n");
            }
        } else {
            fprintf(stderr,"Memory not allocated to successfully to *data pointer!\n");
        }
    }
    return 0;
}

bool take_input(uint8_t *const data,uint8_t n) {
    bool is_exist = false;
    for(uint8_t i = 0; i < n; ++i) {
        scanf("%"SCNu8,&data[i]);
        if(data[i] > LIMIT) {
            is_exist = true;
        } 
    }
    return is_exist;
}

bool check_rainbow(uint8_t *const data,uint8_t n) {
    bool is_rainbow = true;
    uint8_t freq_dist[LIMIT];
    memset(freq_dist,0,(sizeof(uint8_t)*LIMIT));
    for(uint8_t i = 0; i < n; ++i) {
        ++freq_dist[data[i] - 1];
    }
    if(!(freq_dist[0] && freq_dist[1] && freq_dist[2] && freq_dist[3] && freq_dist[4] && freq_dist[5] && freq_dist[6])) {
        is_rainbow = false;
    } else {
        uint8_t start = 0, end = (n - 1);
        for(uint8_t i = 1; i <= LIMIT; ++i) {
            while((start <= end) && ((data[start] == i) && (data[end] == i))) {
                ++start;
                --end;
            }
            if((start <= end) && ((data[start] != data[end]) || ((data[start] > (i + 1)) || (data[end] > (i + 1))) || (data[start] < i || data[end] < i))) {
                is_rainbow = false;
            }
        }
    }
    return is_rainbow;
}