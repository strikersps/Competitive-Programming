/*  Problem Statement: https://practice.geeksforgeeks.org/problems/next-smallest-palindrome/0
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>
#include<assert.h>

bool check_all_nines(uint32_t*,uint32_t);
bool check_palindrome(uint32_t*,uint32_t);
void find_next_palindrome(uint32_t*,uint32_t);

int main(void) {
    uint32_t test;
    scanf("%"SCNu32,&test);
    assert(test > 0 && test < 101);
    while(test--) {
        uint32_t n,*number = NULL;
        scanf("%"SCNu32,&n);
        assert(n > 0 && n <1001);
        number = calloc(sizeof(uint32_t),n);
        if(number) {
            for(uint16_t i=0; i < n; ++i) {
                scanf("%"SCNu32,&number[i]);
                assert(number[i] >= 0 && number[i] < 10);
            }
            if(check_all_nines(number,n)) {
                uint32_t *num = realloc(number,sizeof(uint32_t)*(n+1));
                if(num) {
                    for(uint16_t i = 0; i < (n+1); ++i) {
                        if(i == 0 || i == n) {
                            num[i] = 1;
                        } else {
                            num[i] = 0;
                        }
                        printf("%"PRIu32" ",num[i]);
                    }
                    free(num);
                    printf("\n");
                } else {
                    fprintf(stderr,"Memory not allocated to num pointer!\n");
                }
            } else {
                find_next_palindrome(number,n);
                for(uint32_t i = 0; i < n; printf("%"PRIu32" ",number[i]),++i);
                printf("\n");
                free(number);
            }
        } else {
            fprintf(stderr,"Memory not allocated to number pointer!\n");
        }
    }
    return 0;
}

bool check_all_nines(uint32_t *number,uint32_t n) {
    bool is_all_nine = true;
    for(uint16_t i  = 0; i < n; ++i) {
        if(!(number[i] == 9)) {
            is_all_nine = false;
            break;
        }
    }
    return is_all_nine;
}

bool check_palindrome(uint32_t *number,uint32_t n) {
    uint32_t start,end;
    bool is_palindrome = true;
    for(start = 0, end = n - 1; (start <  end); ++start,--end) {
        if(!(number[start] == number[end])) {
            is_palindrome = false;
            break;
        }
    }
    return is_palindrome;
}

void find_next_palindrome(uint32_t *number,uint32_t n) {
    uint32_t start,mid,end;
    start = 0;
    end = (n - 1);
    mid = ((end - start) >> 1) + start;
    if(check_palindrome(number,n)) {
        for(start = mid,end = ((n & 1) ? mid : (mid + 1)); (start >= 0 && end < n) && (number[start] == 9); --start,++end) {
            number[end] = number[start] = 0; 
        }
        if(start >= 0 && end < n) {
            number[start]++;
            number[end] = number[start];
        }
    } else {
        bool flag  = false;
        for(start = mid, end = ((n & 1) ? mid : (mid + 1)); (number[start] == number[end]); --start,++end);
        if(number[start] < number[end]) {
            flag = true;
            number[end] = number[start];
        }
        if(flag) {
            for(start = mid,end = ((n & 1) ? mid : (mid + 1)); (start >= 0 && end < n) && (number[start] == 9); --start,++end) {
                number[end] = number[start] = 0; 
            }
            if(start >= 0 && end < n) {
                number[start]++;
                number[end] = number[start];
            }
        }
        for(start = 0, end = n - 1; (start <  end); ++start,--end) {
            number[end] = number[start];
        }
    }
}