/*  Problem Statement: Refer to the readme.md in this directory.
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<assert.h>

typedef unsigned long long ull_t;
typedef long long ll_t;

static const bool check_sorted(const int *const,unsigned int);
static void merge_sort_int_sequence(int *const,unsigned int,unsigned int);
static void merge_int_sequence(int *const,unsigned int,unsigned int,unsigned int);
static void rearrange_int_sequence(int *const,unsigned int);
static void display_sequence(const int *const,unsigned int);

int main(void) {
    unsigned int n;
    // printf("Enter the length of the sequence\n");
    scanf("%u", &n);
    assert(n > 0);
    int sequence[n];
    // printf("Enter the sequence\n");
    for(unsigned int i = 0; i < n; ++i) {
        scanf("%d", &sequence[i]);
    }
    if(!check_sorted(sequence,n)) {
        merge_sort_int_sequence(sequence,0,(n - 1));
    }
    rearrange_int_sequence(sequence,n);
    // printf("Sequence after re-arrangement\n");
    display_sequence(sequence,n);
    return EXIT_SUCCESS;
}

static const bool check_sorted(const int *const data,unsigned int n) {
    bool is_sorted = true;
    for(unsigned int i = 0; i < (n - 1); ++i) {
        if(data[i] > data[i + 1]) {
            is_sorted = false;
            break;
        }
    }
    return is_sorted;
}

static void merge_sort_int_sequence(int *const data,unsigned int start,unsigned int end) {
    if(start < end) {
        unsigned int mid = ((end - start) >> 1) + start;
        merge_sort_int_sequence(data,start,mid);
        merge_sort_int_sequence(data,(mid + 1),end);
        merge_int_sequence(data,start,mid,end);
    }
}

static void merge_int_sequence(int *const data,unsigned int start,unsigned int mid,unsigned int end) {
    unsigned left_size = (mid - start) + 1;
    int left_data[left_size];
    memmove(left_data,&data[start],(sizeof(int) * left_size));
    unsigned right_size = end - mid;
    int right_data[right_size];
    memmove(right_data,&data[mid + 1],(sizeof(int) * right_size));
    for(unsigned int k = start, i = 0, j = 0; k <= end; ++k) {
        if(i == left_size) {
            data[k] = right_data[j++];
        } else if(j == right_size) {
            data[k] = left_data[i++];
        } else if(left_data[i] < right_data[j]) {
            data[k] = left_data[i++];
        } else {
            data[k] = right_data[j++];
        }
    }
}

static void rearrange_int_sequence(int *const data,unsigned int n) {
    unsigned int even_count,odd_count;
    even_count = odd_count = 0;
    for(unsigned int i = 0; i < n; ++i) {
        if(data[i] & 1) {
            ++odd_count;
        } else {
            ++even_count;
        }
    }
    int even_number_sequence[even_count],odd_number_sequence[odd_count];
    for(unsigned int i = 0, j = 0, k = 0; (i < n && j <= odd_count && k <= even_count); ++i) {
        if(data[i] & 1) {
            odd_number_sequence[j++] = data[i];
        } else {
            even_number_sequence[k++] = data[i];
        }
    }
    bool even_odd = false;
    for(unsigned int i = 0, j = 0, k = 0; k < n; ++k) {
        if(i == even_count) {
            data[k] = odd_number_sequence[j++];
        } else if(j == odd_count) {
            data[k] = even_number_sequence[i++];
        } else if(!k) {
            if(even_number_sequence[i] < odd_number_sequence[j]) {
                data[k] = even_number_sequence[i++];
                even_odd = true; 
            } else {
                data[k] = odd_number_sequence[j++];
            }
        } else if(!even_odd) {
            if(k & 1) {
                data[k] = even_number_sequence[i++];
            } else {
                data[k] = odd_number_sequence[j++];
            }
        } else {
            if(k & 1) {
                data[k] = odd_number_sequence[j++];
            } else {
                data[k] = even_number_sequence[i++];
            }
        }
    }
}

static void display_sequence(const int *const data,unsigned int n) {
    for(unsigned int i = 0; i < n; ++i) {
        printf("%d ", data[i]);
    }
    printf("\n");
}