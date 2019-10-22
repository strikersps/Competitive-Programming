/*  Problem Statement: https://codeforces.com/contest/1249/problem/A
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef unsigned long long ull_t;
typedef long long ll_t;
typedef unsigned short int usi_t;
typedef short int si_t;

const bool check_pair_exist(usi_t *const,usi_t);
const bool check_sorted(usi_t *const,usi_t);
void merge_sort(usi_t *const,usi_t,usi_t);
void merge_list(usi_t *const,usi_t,usi_t,usi_t);

int main(void) {
    usi_t queries;
    scanf("%hu", &queries);
    assert(queries > 0 && queries < 101);
    while(queries--) {
        usi_t n;
        scanf("%hu", &n);
        assert(n > 0 && n < 101);
        usi_t *const students = calloc(n,sizeof(usi_t));
        if(students) {
            for(usi_t i = 0; i < n; ++i) {
                scanf("%hu", &students[i]);
                assert(students[i] > 0 && students[i] < 101);
            }
            if(!check_sorted(students,n)) {
                merge_sort(students,0,(n - 1));
            }
            printf("%hu\n", (check_pair_exist(students,n) ? 2 : 1));
            free(students);
        } else {
            fprintf(stderr,"Memort not allocated to *students pointer!\n");
        }
    }
    return 0;
}

const bool check_sorted(usi_t *const data,usi_t n) {
    bool is_sorted = true;
    for(usi_t i = 0; i < (n - 1); ++i) {
        if(data[i] > data[i + 1]) {
            is_sorted = false;
            break;
        }
    }
    return is_sorted;
}

void merge_sort(usi_t *const data,usi_t start,usi_t end) {
    if(start < end) {
        const usi_t mid = ((end - start) >> 1) + start;
        merge_sort(data,start,mid);
        merge_sort(data,(mid + 1),end);
        merge_list(data,start,mid,end);
    }
}

void merge_list(usi_t *const data,usi_t start,usi_t mid,usi_t end) {
    const usi_t left_size = (mid -start) + 1;
    usi_t *const left_list = calloc(left_size,sizeof(usi_t));
    if(left_list) {
        for(usi_t i = 0; i < left_size; ++i) {
            left_list[i] = data[start + i];
        }
    } else {
        fprintf(stderr,"Memory not allocated to *left-list pointer!\n");
    }
    const usi_t right_size = end - mid;
    usi_t *const right_list = calloc(right_size,sizeof(usi_t));
    if(right_list) {
        for(usi_t j = 0; j < right_size; ++j) {
            right_list[j] = data[(mid + j) + 1];
        }
    } else {
        fprintf(stderr,"Memory not allocated to *right_list pointer!\n");
    }
    for(usi_t k = start, i = 0, j = 0; k <= end; ++k) {
        if(i == left_size) {
            data[k] = right_list[j];
            ++j;
        } else if(j == right_size) {
            data[k] = left_list[i];
            ++i;
        } else if(left_list[i] < right_list[j]) {
            data[k] = left_list[i];
            ++i;
        } else {
            data[k] =  right_list[j];
            ++j;
        }
    }
    free(left_list);
    free(right_list);
}

const bool check_pair_exist(usi_t *const data,usi_t n) {
    bool is_pair_exist = false;
    for(usi_t i = 0; i < (n - 1); ++i) {
        if((data[i + 1] - data[i]) == 1) {
            is_pair_exist = true;
            break;
        }
    }
    return is_pair_exist;
}