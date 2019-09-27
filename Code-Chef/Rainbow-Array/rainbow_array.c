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

#define ARRAY_LENGTH 10

void take_input(uint8_t *const,uint8_t,uint8_t[]);
bool check_rainbow(uint8_t *const,uint8_t,uint8_t[]);

int main(void) {
    uint8_t test;
    scanf("%"SCNu8,&test);
    assert(test > 0 && test< 101);
    while(test--) {
        uint8_t n;
        uint8_t freq_dist[ARRAY_LENGTH];
        memset(freq_dist,0,(sizeof(uint8_t) * ARRAY_LENGTH));
        scanf("%"SCNu8,&n);
        assert(n > 6 && n < 101);
        uint8_t *const data = calloc(n,sizeof(uint8_t));
        if(data) {
            take_input(data,n,freq_dist);
            if(check_rainbow(data,n,freq_dist)) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
            free(data);
        } else {
            fprintf(stderr,"Memory not allocated to successfully to *data pointer!\n");
        }
    }
    return 0;
}

void take_input(uint8_t *const data,uint8_t n,uint8_t freq_dist[]) {
    for(uint8_t i = 0; i < n; ++i) {
        scanf("%"SCNu8,&data[i]);
        ++freq_dist[data[i] - 1];
    }
}

bool check_rainbow(uint8_t *const data,uint8_t n,uint8_t freq_dist[]) {
    bool is_rainbow = true;
    if(!(freq_dist[0] && freq_dist[1] && freq_dist[2] && freq_dist[3] && freq_dist[4] && freq_dist[5] && freq_dist[6])) {
        is_rainbow = false;
    }
    else if(freq_dist[ARRAY_LENGTH - 3] || freq_dist[ARRAY_LENGTH - 2] || freq_dist[ARRAY_LENGTH - 1]) {
        is_rainbow = false;
    } else {
        uint8_t start = 0, end = (n - 1);
        for(uint8_t i = 0; i < (ARRAY_LENGTH - 3); ++i) {
            while((start <= end) && ((data[start] == (i + 1)) && (data[end] == (i + 1)))) {
                ++start;
                --end;
            }
            if((data[start] != data[end]) || ((data[start] > (i + 2)) || (data[end] > (i + 2))) || (data[start] < i || data[end] < i)) {
                is_rainbow = false;
            }
        }
    }
    return is_rainbow;
}