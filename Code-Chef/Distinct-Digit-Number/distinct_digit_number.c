/*  Problem Statement: https://www.codechef.com/HCS12019/problems/SETH0006
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<assert.h>

#define NOT_FOUND -1

const bool is_distinct_digits(size_t);

int main(void) {
    size_t start,end;
    scanf("%lu%lu",&start,&end);
    assert((start > 0 && start < 100001) && (end > 0 && end < 100001));
    while(start <= end) {
        if(is_distinct_digits(start)) {
            printf("%lu\n", start);
            break;
        }
        ++start;
    }
    if(start > end) {
        printf("%d\n",NOT_FOUND);
    }
    return 0;
}

const bool is_distinct_digits(size_t n) {
    bool is_all_digit_distinct = true, freq_digits[10];;
    size_t temp = n;
    memset(freq_digits,false,(10 * sizeof(bool)));
    while(temp) {
        if(freq_digits[temp % 10]) {
            is_all_digit_distinct = false;
            break;
        }
        freq_digits[temp % 10] = true;
        temp /= 10;
    }
    return is_all_digit_distinct;
}