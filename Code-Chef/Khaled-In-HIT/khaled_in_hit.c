/*  Problem Statement: https://www.codechef.com/problems/HIT
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>
#include<assert.h>

#define NOT_POSSIBLE -1

const bool check_sorted(uint8_t *const,uint8_t);
void merge_sort(uint8_t *const,uint8_t,uint8_t);
void merge_list(uint8_t *const,uint8_t,uint8_t,uint8_t);

int main(void) {
    uint16_t test;
    scanf("%"SCNu16, &test);
    assert(test > 0 && test < 1001);
    while(test--) {
        uint8_t n;
        scanf("%"SCNu8, &n);
        assert(n > 0 && n < 101 && (n % 4 == 0));
        uint8_t *const scores = calloc(n,sizeof(uint8_t));
        if(scores) {
            for(uint8_t i = 0; i < n; ++i) {
                scanf("%"SCNu8, &scores[i]);
                assert(scores[i] >= 0 && scores[i] < 101);
            }
            if(!check_sorted(scores,n)) {
                merge_sort(scores,0,(n - 1));
            }
            uint8_t grp_strength = n / 4;
            if((scores[grp_strength] == scores[grp_strength - 1]) || (scores[grp_strength << 1] == scores[(grp_strength << 1) - 1]) || (scores[3 * grp_strength] == scores[(3 * grp_strength) - 1])) {
                printf("%"PRId8"\n", NOT_POSSIBLE);
            } else {
                printf("%"PRIu8" %"PRIu8" %"PRIu8"\n", scores[grp_strength],scores[grp_strength << 1],scores[3 *grp_strength]);
            }
            free(scores);
        } else {
            fprintf(stderr,"Not able to allocated %lu bytes of memory!\n", (n * sizeof(uint8_t)));
        }
    }
    return EXIT_SUCCESS;
}

const bool check_sorted(uint8_t *const scores,uint8_t n) {
    bool is_sorted = true;
    for(uint8_t i = 0; i < (n - 1); ++i) {
        if(scores[i] > scores[i + 1]) {
            is_sorted = false;
            break;
        }
    }
    return is_sorted;
}

void merge_sort(uint8_t *const scores,uint8_t start,uint8_t end) {
    if(start < end) {
        uint8_t mid = ((end - start) >> 1) + start;
        merge_sort(scores,start,mid);
        merge_sort(scores,(mid + 1),end);
        merge_list(scores,start,mid,end);
    }
}

void merge_list(uint8_t *const scores,uint8_t start,uint8_t mid,uint8_t end) {
    uint8_t left_size = (mid - start) + 1;
    uint8_t *left_list = calloc(left_size,sizeof(uint8_t));
    if(left_list) {
        for(uint8_t i = 0; i < left_size; ++i) {
            left_list[i] = scores[start + i];
        }
    } else {
        fprintf(stderr,"Not able to allocate %lu bytes of memory to *left_list\n", (sizeof(uint8_t) * left_size));
    }
    uint8_t right_size = end - mid;
    uint8_t *right_list = calloc(right_size,sizeof(uint8_t));
    if(right_list) {
        for(uint8_t i = 0; i < right_size; ++i) {
            right_list[i] = scores[(mid + 1) + i];
        }
    } else {
        fprintf(stderr,"Not able to allocate %lu bytes of memory to *right_list\n", sizeof(uint8_t) * right_size);
    }
    for(uint8_t k = start,i = 0,j = 0; k <= end; ++k) {
        if(i == left_size) {
            scores[k] = right_list[j];
            ++j;
        } else if(j == right_size) {
            scores[k] = left_list[i];
            ++i;
        } else if(left_list[i] < right_list[j]) {
            scores[k] = left_list[i];
            ++i;
        } else {
            scores[k] = right_list[j];
            ++j;
        }
    }
    free(left_list);
    free(right_list);
}