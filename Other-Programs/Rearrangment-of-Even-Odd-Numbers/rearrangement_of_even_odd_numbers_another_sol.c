/*  Problem Statement: Refer to the readme.md in this directory.
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

int comparator_callback(const void*,const void*);
static const bool check_sorted(const int *const,unsigned int);
static void rearrange_int_sequence(int *const,unsigned int);
static void display_sequence(const int *const,unsigned int);

int main(void) {
    unsigned int n;
    scanf("%u", &n);
    assert(n > 0);
    int sequence[n];
    for(unsigned int i = 0; i < n; ++i) {
        scanf("%d", &sequence[i]);
    }
    if(!check_sorted(sequence,n)) {
        qsort(sequence,n,sizeof(int),comparator_callback);
    }
    rearrange_int_sequence(sequence,n);
    display_sequence(sequence,n);
    return EXIT_SUCCESS;
}

int comparator_callback(const void *a,const void *b) {
    return (*(int*)a) > (*(int*)b);
}

static const bool check_sorted(const int *const data,unsigned int n) {
    bool is_sorted = false;
    for(unsigned int i = 0; i < (n - 1); ++i) {
        if(data[i] >  data[i + 1]) {
            is_sorted = false;
            break;
        }
    }
    return is_sorted;
}

static void rearrange_int_sequence(int *const data,unsigned int n) {
    unsigned int even_count, odd_count;
    even_count = odd_count = 0;
    for(unsigned int i = 0; i < n; ++i) {
        if(data[i] & 1) {
            ++odd_count;
        } else {
            ++even_count;
        }
    }
    int odd_int_sequence[odd_count],even_int_sequence[even_count];
    for(unsigned int i = 0, j = 0, k = 0; i < n; ++i) {
        if(data[i] & 1) {
            odd_int_sequence[j++] = data[i];
        } else {
            even_int_sequence[k++] = data[i];
        }
    }
    bool even_odd = false;
    for(unsigned int i = 0, j = 0, k = 0; i < n; ++i) {
        if(j == odd_count) {
            data[i] = even_int_sequence[k++];
        } else if(k == even_count) {
            data[i] = odd_int_sequence[j++];
        } else if(!i) {
            if(even_int_sequence[k] < odd_int_sequence[j]) {
                even_odd = true;
                data[i] = even_int_sequence[k++];
            } else {
                data[i] = odd_int_sequence[j++];
            }
        } else {
            if(!even_odd) {
                if(i & 1) {
                    data[i] = even_int_sequence[k++];
                } else {
                    data[i] = odd_int_sequence[j++];
                }
            } else {
                if(i & 1) {
                    data[i] = odd_int_sequence[j++];
                } else {
                    data[i] = even_int_sequence[k++];
                }
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
