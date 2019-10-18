/*  Problem Statement: https://www.codechef.com/KOKO2019/problems/DISTCHOC
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>
#include<assert.h>

void take_input(uint32_t *const,uint32_t);
const bool check_sorted(uint32_t *const,uint32_t);
void merge_sort(uint32_t *const,uint32_t,uint32_t);
void merge_data(uint32_t *const,uint32_t,uint32_t,uint32_t);

int main(void) {
    uint32_t n;
    scanf("%"SCNu32,&n);
    assert(n > 0 && n < 100001);
    uint32_t *const chocolate_boxes = calloc(n,sizeof(uint32_t));
    if(chocolate_boxes) {
        take_input(chocolate_boxes,n);
        if(!(check_sorted(chocolate_boxes,n))) {
            merge_sort(chocolate_boxes,0,(n - 1));
        }
        uint64_t wait_time, min_wait_time;
        wait_time = min_wait_time = 0;
        for(uint32_t i = 1; i < n; ++i) {
            wait_time += chocolate_boxes[i - 1];
            min_wait_time += wait_time;
        }
        printf("%"PRIu64"\n", min_wait_time);
        free(chocolate_boxes);
    } else {
        fprintf(stderr,"Memory not allocated to *chocolates_boxes pointer!\n");
    }
    return 0;
}

void take_input(uint32_t *const data,uint32_t n) {
    for(uint32_t i = 0; i < n; ++i) {
        scanf("%"SCNu32,&data[i]);
        assert(data[i] > 0 && data[i] < 1000001);
    }
}

const bool check_sorted(uint32_t *const data,uint32_t n) {
    bool is_sorted = true;
    for(uint32_t i = 0; i < (n - 1); ++i) {
        if(data[i] > data[i + 1]) {
            is_sorted = false;
            break;
        }
    }
    return is_sorted;
}

void merge_sort(uint32_t *const data,uint32_t start,uint32_t end) {
    if(start < end) {
        uint32_t mid = ((end - start) >> 1) + start;
        merge_sort(data,start,mid);
        merge_sort(data,(mid + 1),end);
        merge_data(data,start,mid,end);
    }
}

void merge_data(uint32_t *const data,uint32_t start,uint32_t mid,uint32_t end) {
    uint32_t left_size,right_size;
    left_size = (mid - start) + 1;
    right_size = end - mid;
    uint32_t *const left_data = calloc(left_size,sizeof(uint32_t));
    if(left_data) {
        for(uint32_t i = 0; i < left_size; ++i) {
            left_data[i] = data[start + i];
        }
    } else {
        fprintf(stderr,"Memory not allocated to *left_data pointer!\n");
    }
    uint32_t *const right_data = calloc(right_size,sizeof(uint32_t));
    if(right_data) {
        for(uint32_t j = 0; j < right_size; ++j) {
            right_data[j] = data[(mid + j) + 1];
        }
    } else {
        fprintf(stderr,"Memory not allocated to *right_data pointer!\n");
    }
    for(uint32_t i = 0,j = 0, k = start; k <= end; ++k) {
        if(i == left_size) {
            data[k] = right_data[j];
            ++j;
        } else if(j == right_size) {
            data[k] = left_data[i];
            ++i;
        } else if(right_data[j] > left_data[i]) {
            data[k] = left_data[i];
            ++i;
        } else {
            data[k] = right_data[j];
            ++j;
        }
    }
    free(left_data);
    free(right_data);
}