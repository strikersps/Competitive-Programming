/*  Problem Statement: https://www.codechef.com/ZCOPRAC/problems/ZCO13001
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<assert.h>

typedef unsigned long long ull_t;
typedef long long ll_t;

void take_input(size_t *const,size_t);
const bool check_sorted(size_t *const,size_t);
void merge_sort(size_t *const,size_t,size_t);
void merge_data(size_t *const,size_t,size_t,size_t);
const ull_t compute_total_advertising_revenue(size_t *const,size_t);

int main(void) {
    size_t n;
    scanf("%lu",&n);
    assert(n > 0 && n < 200001);
    size_t *const team_strength = calloc(n,sizeof(size_t));
    if(team_strength) {
        take_input(team_strength,n);
        if(!check_sorted(team_strength,n)) {
            merge_sort(team_strength,0,(n - 1));
        }
        printf("%llu\n", compute_total_advertising_revenue(team_strength,n));
        free(team_strength);
    } else {
        fprintf(stderr,"Memory not allocated to *team_strenght pointer!\n");
    }
    return 0;
}

void take_input(size_t *const data,size_t n) {
    for(size_t i = 0; i < n; ++i) {
        scanf("%lu", &data[i]);
        assert(data[i] > 0 && data[i] < 1001);
    }
}

const bool check_sorted(size_t *const data,size_t n) {
    bool is_sorted = true;
    for(size_t i = 0; i < (n - 1); ++i) {
        if(data[i] < data[i + 1]) {
            is_sorted = false;
        }
    }
    return is_sorted;
}

void merge_sort(size_t *const data,size_t start,size_t end) {
    if(start < end) {
        size_t mid = ((end - start) >> 1) + start;
        merge_sort(data,start,mid);
        merge_sort(data,(mid + 1),end);
        merge_data(data,start,mid,end);
    }
}

void merge_data(size_t *const data,size_t start,size_t mid,size_t end) {
    size_t left_size,right_size;
    left_size = (mid - start) + 1;
    size_t *const left_list = calloc(left_size,sizeof(size_t));
    if(left_list) {
        for(size_t i = 0; i < left_size; ++i) {
            left_list[i] = data[start + i];
        }
    } else {
        fprintf(stderr,"Memory not allocated to *left-list pointer!\n");
    }
    right_size = end - mid;
    size_t *const right_list = calloc(right_size,sizeof(size_t));
    if(right_list) {
        for(size_t j = 0; j < right_size; ++j) {
            right_list[j] = data[(mid + 1) + j];
        }
    } else {
        fprintf(stderr,"Memory not allocated to *right_list pointer!\n");
    }
    for(size_t k = start, i = 0, j = 0; k <= end; ++k) {
        if(i == left_size) {
            data[k] = right_list[j];
            ++j;
        } else if(j == right_size) {
            data[k] = left_list[i];
            ++i;
        } else if(right_list[j] < left_list[i]) {
            data[k] = left_list[i];
            ++i;
        } else {
            data[k] = right_list[j];
            ++j;
        }
    }
    free(left_list);
    free(right_list);
}

const ull_t compute_total_advertising_revenue(size_t *const data,size_t n) {
    ull_t cummulative_sum = 0;
    for (size_t i = 0; i < n; cummulative_sum += data[i],i++);    
    ull_t total_advertising_rev_earned = 0;
    for(size_t i = 0; i < (n - 1); ++i) {
        cummulative_sum -= data[i];
        total_advertising_rev_earned += abs((data[i] * ((n - 1) - i)) - cummulative_sum);
    }
    return total_advertising_rev_earned;
}