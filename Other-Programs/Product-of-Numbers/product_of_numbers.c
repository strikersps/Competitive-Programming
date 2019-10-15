/*  Problem Statement: Refer the readme.md file.
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef unsigned long long ull_t;
typedef long long ll_t;

void take_input(size_t *const,size_t);
size_t* transform_list(size_t *const,size_t);
void display_list(size_t *const,size_t);

int main(void) {
    int test;
    printf("Enter the number of test-cases\n");
    scanf("%d",&test);
    assert(test > 0);
    while(test--) {
        size_t n;
        printf("Enter the length of the sequence\n");
        scanf("%lu",&n);
        assert(n > 0);
        // Assumption: All the numbers in the sequence are positive, and zero is not allowed.
        size_t *const data = calloc(n,sizeof(size_t));
        if(data) {
            printf("Enter the data into the sequence\n");
            take_input(data,n);
            size_t *const transformed_list = transform_list(data,n);
            display_list(transformed_list,n);
            free(transformed_list);
            free(data);
        } else {
            fprintf(stderr,"Memory not allocated to *data pointer!\n");
        }
    }
    return 0;
}

void take_input(size_t *const data,size_t n) {
    for(size_t i = 0; i < n; ++i) {
        scanf("%lu",&data[i]);
        assert(data[i] != 0);
    }
}

size_t* transform_list(size_t *const data,size_t n) {
    ull_t cummulative_product = 1;
    size_t *left_list = calloc(n,sizeof(size_t));
    if(left_list) {
        for(size_t i = 0; i < n; ++i) {
            cummulative_product *= data[i];
            left_list[i] = cummulative_product;
        }
    } else {
        fprintf(stderr,"Memory not allocated to *left-list pointer!\n");
    }
    cummulative_product = 1;
    size_t *right_list = calloc(n,sizeof(size_t));
    if(right_list) {
        for(int i = (n - 1); i >= 0; --i) {
            cummulative_product *= data[i];
            right_list[i] = cummulative_product;
        }
    } else {
        fprintf(stderr,"Memory not allocated to the *right-list pointer!\n");
    }
    size_t *transformed_list = calloc(n,sizeof(size_t));
    for(size_t i = 0; i < n; ++i) {
        if(!i) {
            transformed_list[i] = right_list[i + 1];
        } else if(i == (n - 1)) {
            transformed_list[i] = left_list[i - 1];
        } else {
            transformed_list[i] = right_list[i + 1] * left_list[i - 1];
        }
    }
    free(left_list);
    free(right_list);
    return transformed_list;
}

void display_list(size_t *const data,size_t n) {
    for(size_t i = 0; i < n; ++i) {
        printf("%lu ",data[i]);
    }
    printf("\n");
}