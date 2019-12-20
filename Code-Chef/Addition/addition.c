/*  Problem Statement: https://www.codechef.com/DEC19B/problems/BINADD
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>

#define MAX_STRING_LENGTH 100001

static int compute_loop_iteration(const char *const,const char *const);
static bool check_all_zeroes(const char *const);

int main(void) {
    int test;
    scanf("%d", &test);
    assert(test > 0 && test < 100001);
    while(test--) {
        char a[MAX_STRING_LENGTH],b[MAX_STRING_LENGTH];
        scanf("%s%s", a,b);
        const size_t len_a = strlen(a), len_b = strlen(b);
        char *binary_string_A, *binary_string_B;
        binary_string_A = binary_string_B = NULL;
        if(len_a < len_b) {
            binary_string_A = calloc((len_b + 1),sizeof(char));
            memset(binary_string_A,'0',(sizeof(char) * (len_b - len_a)));
            memmove(&binary_string_A[len_b - len_a],a,(sizeof(char) * len_a));
            binary_string_B = calloc((len_b + 1),sizeof(char));
            snprintf(binary_string_B,len_b + 1,"%s",b);
        } else if(len_a > len_b) {
            binary_string_B = calloc((len_a + 1),sizeof(char));
            memset(binary_string_B,'0',(sizeof(char) * (len_a - len_b)));
            memmove(&binary_string_B[len_a - len_b],b,(sizeof(char) * len_b));
            binary_string_A = calloc((len_a + 1),sizeof(char));
            snprintf(binary_string_A,len_a + 1,"%s",a);
        } else {
            binary_string_A = calloc((len_a + 1),sizeof(char));
            snprintf(binary_string_A,(len_a + 1),"%s",a);
            binary_string_B = calloc((len_b + 1),sizeof(char));
            snprintf(binary_string_B,(len_b + 1),"%s",b);
        }
        int loop_count = 0;
        if(check_all_zeroes(binary_string_B)) {
            loop_count = 0;
        } else if(check_all_zeroes(binary_string_A)) {
            loop_count = 1;
        } else if(!strcmp(binary_string_A,binary_string_B)) {
            loop_count = 2;
        } else {
            loop_count = compute_loop_iteration(binary_string_A,binary_string_B);
        }
        printf("%u\n", loop_count);
        free(binary_string_A);
        free(binary_string_B);
    }
    return EXIT_SUCCESS;
}

static bool check_all_zeroes(const char *const binary_string) {
    bool is_zeroes = true;
    for(unsigned int i = 0; binary_string[i] != '\0'; ++i) {
        if(binary_string[i] != '0') {
            is_zeroes = false;
            break;
        }
    }
    return is_zeroes;
}

static int compute_loop_iteration(const char *const binary_string_A,const char *const binary_string_B) {
    const size_t limit = strlen(binary_string_A);
    int carry, current_carry_seq_len, max_carry_seq_len;
    carry = current_carry_seq_len = max_carry_seq_len = 0;
    for(int i = (int)(limit - 1); i >= 0; --i) {
        carry += (binary_string_A[i] - '0') + (binary_string_B[i] - '0');
        switch(carry) {
            case 3:
                current_carry_seq_len = 1;
                carry -= 2;
                break;
            case 2:
                --carry;
                ++current_carry_seq_len;
                break;
            default:
                carry = current_carry_seq_len = 0;
                break;
        }
        if (current_carry_seq_len > max_carry_seq_len) {
            max_carry_seq_len = current_carry_seq_len;
        }
    }
    return max_carry_seq_len + 1;
}
