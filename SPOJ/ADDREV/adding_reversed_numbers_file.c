/*  Problem Statement: https://www.spoj.com/problems/ADDREV/
    Author: Suraj Sharma
    I/O: The input to the program is through file named input.txt
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>

#define STRING_LENGTH 18 // Assuming that the two positive integers will be 64-bit long.

char* pre_process_number(char*);
void reverse_string(char*);
void swap_data(char*,char*);
char* add_numbers(char*,char*);

int main(int argc,const char*argv[]) {
    FILE *f_in = fopen("test_cases/input.txt","r");
    FILE *f_out = fopen("test_cases/output.txt","w");
    if(f_in && f_out) {
        // printf("input.txt opened successfully\n");
        uint16_t test;
        fscanf(f_in,"%"SCNu16,&test);
        // printf("Enter the number of test cases\n");
        // scanf("%"SCNu16,&test);
        assert(test>0 && test<10001);
        while(test--) {
            char *first_num,*second_num,*sum;
            first_num = calloc(sizeof(char),STRING_LENGTH);
            second_num = calloc(sizeof(char),STRING_LENGTH);
            if(first_num && second_num) {
                // printf("Enter the two positive integers\n");
                fscanf(f_in,"%s%s",first_num,second_num);
                // scanf("%s%s",first_num,second_num);
                if(strlen(first_num) > 1) {
                    first_num = pre_process_number(first_num);
                    reverse_string(first_num);
                }
                if(strlen(second_num) > 1) {
                    second_num = pre_process_number(second_num);
                    reverse_string(second_num);
                }
                sum = add_numbers(first_num,second_num);
                free(first_num);
                free(second_num);
                if(sum) {
                    if(strlen(sum) > 1) {
                        sum = pre_process_number(sum);
                        reverse_string(sum);
                    }
                    fprintf(f_out,"[%s]\n",sum);
                    free(sum);
                } else {
                    fprintf(stderr,"Memory not allocated to *sum!\n");
                }
            } else {
                if(!(first_num)) {
                    fprintf(stderr,"Memory not allocated to *first_num!\n");
                } else {
                    fprintf(stderr,"Memory not allocated to *second_num!\n");
                }
            }
        }
        fclose(f_in);
        fclose(f_out);
    } else {
        if(!f_in) {
            fprintf(stderr,"input.txt not open successfully!\n");
        } else {
            fprintf(stderr,"output.txt not open successfully\n");
        }
    }
    return 0;
}

char* pre_process_number(char *number) {
    uint8_t num_len = strlen(number);
    // Remove all the leading zeroes.
    while(number[0] == '0') {
        for(uint8_t i = 1;i<=num_len;(number[i-1] = number[i]),++i);
    }
    // Remove all the trailing zeroes.
    num_len = strlen(number);
    for(uint8_t i=(num_len-1);(number[i] == '0');(number[i] = '\0'),--i);
    num_len = strlen(number);
    char *num = realloc(number,(sizeof(char)*(num_len+1)));
    num[num_len] = '\0';
    return num;
}

void reverse_string(char *number) {
    for(uint8_t start = 0,end = (strlen(number)-1);(start < end);swap_data(&number[start],&number[end]),++start,--end);
}

void swap_data(char*a,char*b) {
    if(a != b) {
        *a = (((*a) - 48) ^ ((*b) - 48)) + 48;
        *b = (((*a) - 48) ^ ((*b) - 48)) + 48;
        *a = (((*a) - 48) ^ ((*b) - 48)) + 48;
    }
}

char* add_numbers(char *first_num,char *second_num) {
    uint8_t first_num_len,second_num_len,sum_len;
    first_num_len = strlen(first_num);
    second_num_len = strlen(second_num);
    sum_len = first_num_len > second_num_len ? (first_num_len + 2): (second_num_len + 2);
    char *sum = calloc(sizeof(char),sum_len);
    if(sum) {
        memset(sum,'0',(sizeof(char)*sum_len));
        int8_t i,j,k,val,carry;
        i = first_num_len - 1;
        j = second_num_len - 1;
        sum[sum_len-1] = '\0';
        carry = 0;
        for(k=(sum_len-2);k>0;k--) {
            if(i >= 0 && j >= 0) {
                val = (sum[k] - 48) + ((first_num[i] - 48) + (second_num[j] - 48)) + carry;
                carry = 0;
                --j;--i;
            } else if(i < 0 && j >= 0) {
                val = (sum[k] - 48) + (second_num[j] - 48) + carry;
                carry = 0;
                --j;
            } else if(j < 0 && i >= 0) {
                val = (sum[k] - 48) + (first_num[i] - 48) + carry;
                carry = 0;
                --i;
            } else {
                break;
            }
            if(val > 9) {
                sum[k] = (val % 10) + 48;
                sum[k-1] = ((sum[k-1] - 48) + (val / 10)) + 48;
            } else {
                sum[k] = val + 48;
            }
        }
    } else {
        fprintf(stderr,"Memory not allocated to *sum!\n");
    }
    return sum;
}