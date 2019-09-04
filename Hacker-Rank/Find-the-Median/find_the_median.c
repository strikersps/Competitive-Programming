/*  Problem Statement: https://www.hackerrank.com/challenges/find-the-median/problem
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>
#include<assert.h>

bool is_sorted(int32_t*,uint32_t);
void merge_sort(int32_t*,uint32_t,uint32_t);
void merge_data(int32_t*,uint32_t,uint32_t,uint32_t);

int main(void) {
    uint32_t n;
    scanf("%"SCNu32,&n);
    assert(n > 0 && n < 1000001);
    int32_t *numbers = calloc(sizeof(int32_t),n);
    if(numbers) {
        for(uint32_t i=0;i<n;++i) {
            scanf("%"SCNu32,&numbers[i]);
            assert(numbers[i] > (-100001) && numbers[i] < 10001);
        }
        if(!(is_sorted(numbers,n))) {
            merge_sort(numbers,0,(n-1));
        }
        printf("%"PRId32"\n",numbers[n >> 1]);
        free(numbers);
    } else {
        fprintf(stderr,"Memory not allocated to pointer *numbers!\n");
    }
}

bool is_sorted(int32_t *numbers,uint32_t n) {
    bool flag = true;
    for(uint32_t i=0;i<(n-1);++i) {
        if(numbers[i] > numbers[i+1]) {
            flag = false;
            break;
        }
    }
    return flag;
}

void merge_sort(int32_t *numbers,uint32_t start,uint32_t end) {
    if(start < end) {
        uint32_t mid = ((end - start) >> 1) + start;
        merge_sort(numbers,start,mid);
        merge_sort(numbers,(mid+1),end);
        merge_data(numbers,start,mid,end);
    }
}

void merge_data(int32_t *numbers,uint32_t start,uint32_t mid,uint32_t end) {
    uint32_t left_size,right_size;
    left_size = (mid -start) + 1;
    right_size = end - mid;
    int32_t *left_data,*right_data;
    left_data  = calloc(sizeof(int32_t),left_size);
    if(left_data) {
        for(uint32_t i=0;i<left_size;(left_data[i] = numbers[start+i]),++i); 
    } else {
        fprintf(stderr,"Memory not allocated to left-data pointer!\n");
    }
    right_data = calloc(sizeof(int32_t),right_size);
    if(right_data) {
        for(uint32_t i=0;i<right_size;(right_data[i] = numbers[(mid + i) + 1]),++i);
    } else {
        fprintf(stderr,"Memory not allocated to right-data pointer!\n");
    }
    for(uint32_t i=0, j=0, k=start;k<=end;++k) {
        if(i == left_size) {
            numbers[k] = right_data[j];
            ++j;
        } else if(j == right_size) {
            numbers[k] = left_data[i];
            ++i;
        } else if(left_data[i] > right_data[j]) {
            numbers[k] = right_data[j];
            ++j;
        } else {
            numbers[k] = left_data[i];
            ++i;
        }
    }
    free(left_data);
    free(right_data);
}