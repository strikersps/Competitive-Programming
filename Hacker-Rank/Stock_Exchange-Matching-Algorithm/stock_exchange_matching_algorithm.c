/*  Problem Statement: https://www.hackerrank.com/contests/goldman-sachs-womens-codesprint/challenges/stock-exchange-matching-algorithm
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<assert.h>

struct STOCK_EXCHANGE_MATCHING_PARAMETERS {
    uint32_t s_i,p_i;
};
typedef struct STOCK_EXCHANGE_MATCHING_PARAMETERS exchange_parameters_t;

void take_input(exchange_parameters_t*,uint32_t);
void merge_sort(exchange_parameters_t*,uint32_t,uint32_t);
void merge_data(exchange_parameters_t*,uint32_t,uint32_t,uint32_t);
uint32_t binary_search(exchange_parameters_t*,uint32_t,uint32_t);

int main(void) {
    uint32_t n,k;
    scanf("%"SCNu32,&n);
    assert(n > 0 && n < 100001);
    exchange_parameters_t *parameters = calloc(sizeof(exchange_parameters_t),n);
    if(parameters) {
        take_input(parameters,n);
        merge_sort(parameters,0,(n-1)); // Sorts the parameters according to the s_i values.
        scanf("%"SCNu32,&k);
        assert(k > 0 && k < 100001);
        while(k--) {
            uint32_t q;
            scanf("%"SCNu32,&q);
            assert(q > 0 && q < 1000000001);
            printf("%"PRIu32"\n",parameters[binary_search(parameters,n,q)].p_i);
        }
        free(parameters);
    } else {
        fprintf(stderr,"Memory not allocated to the pointer *parameters!\n");
    }
    return 0;
}

void take_input(exchange_parameters_t *parameters,uint32_t n) {
    for(uint32_t i=0;i<n;++i) {
        scanf("%"SCNu32,&(parameters[i].s_i));
        assert(parameters[i].s_i > 0 && parameters[i].s_i < 1000000001);
    }
    for(uint32_t i=0;i<n;++i) {
        scanf("%"SCNu32,&(parameters[i].p_i));
        assert(parameters[i].p_i > 0 && parameters[i].p_i < 1000000001);
    }
}

void merge_sort(exchange_parameters_t *parameters,uint32_t start,uint32_t end) {
    if(start <  end) {
        uint32_t mid = ((end - start) >> 1) + start;
        merge_sort(parameters,start,mid);
        merge_sort(parameters,(mid+1),end);
        merge_data(parameters,start,mid,end);
    }
}

void merge_data(exchange_parameters_t *parameters,uint32_t start,uint32_t mid,uint32_t end) {
    uint32_t left_size,right_size;
    left_size = (mid - start) + 1;
    right_size = (end - mid);
    exchange_parameters_t *left_data,*right_data;
    left_data = calloc(sizeof(exchange_parameters_t),left_size);
    if(left_data) {
        for(uint32_t i=0;i<left_size;++i) {
            left_data[i].s_i = parameters[start+i].s_i;
            left_data[i].p_i = parameters[start+i].p_i;
        }
    } else {
        fprintf(stderr,"Memory not allocated to left_data pointer!\n");
    }
    right_data = calloc(sizeof(exchange_parameters_t),right_size);
    if(right_data) {
        for(uint32_t i=0;i<right_size;++i) {
            right_data[i].s_i = parameters[mid + i + 1].s_i;
            right_data[i].p_i = parameters[mid + i + 1].p_i;
        }
    } else {
        fprintf(stderr,"Memory not allocated to right_data pointer!\n");
    }
    for(uint32_t i=0,j=0,k=start;k<=end;++k) {
        if(i == left_size) {
            parameters[k].s_i = right_data[j].s_i;
            parameters[k].p_i = right_data[j].p_i;
            ++j;
        } else if(j == right_size) {
            parameters[k].s_i = left_data[i].s_i;
            parameters[k].p_i = left_data[i].p_i;
            ++i;
        } else if(left_data[i].s_i > right_data[j].s_i) {
            parameters[k].s_i = right_data[j].s_i;
            parameters[k].p_i = right_data[j].p_i;
            ++j;
        } else {
            parameters[k].s_i = left_data[i].s_i;
            parameters[k].p_i = left_data[i].p_i;
            ++i;
        }
    }
    free(left_data);
    free(right_data);
}

uint32_t binary_search(exchange_parameters_t *parameters,uint32_t n,uint32_t key) {
    uint64_t start = 0,end = n-1,location = n - 1,mid;
    while(start <= end) {
        mid = ((end - start) >> 1) + start;
        if((parameters[mid].s_i) == key) {
            location = mid;
            break;
        } else if(parameters[mid].s_i > key) {
            if(mid > 0 && (parameters[mid-1].s_i <= key)) {
                location = mid - 1;
                break;
            } else {
                end = mid - 1;
            }
        } else {
            start = mid + 1;
        }
    }
    return location;
}