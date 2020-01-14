/*  Problem Statement: https://www.spoj.com/problems/SBANK/
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>

#define BANK_ACCNT_LENGTH 32
#define CONTROL_DIGIT_LENGTH 3
#define BANK_CODE_LENGTH 9
#define OWNER_CODE_LENGTH 20

typedef struct bank_accounts {
    char control_digit[CONTROL_DIGIT_LENGTH];
    char bank_code[BANK_CODE_LENGTH];
    char owner_code[OWNER_CODE_LENGTH];
} bank_accounts_t;

static void display_data(bank_accounts_t *const, uint32_t);
static bool check_sorted(bank_accounts_t *const, uint32_t);
static void merge_sort(bank_accounts_t *const, uint32_t, uint32_t);
static void merge_data(bank_accounts_t *const, uint32_t, uint32_t, uint32_t);

int main(void) {
    #ifndef ONLINE_JUDGE
        freopen("test-cases/test-case-1.in", "r", stdin);
        freopen("test-cases/test-case-1.out", "w", stdout);
    #endif
    int8_t test;
    scanf("%"SCNd8, &test);
    assert(test > 0 && test < 6);
    getchar();
    while(test--) {
        uint32_t n;
        scanf("%"SCNu32, &n);
        assert(n > 0 && n < 100001);
        getchar();
        bank_accounts_t *const accounts = malloc(n * sizeof *accounts);
        if(accounts) {
            for(uint32_t i = 0; i < n; ++i) {
                scanf("%s%s", accounts[i].control_digit, accounts[i].bank_code);
                getchar();
                fgets(accounts[i].owner_code, OWNER_CODE_LENGTH, stdin);
                if(accounts[i].owner_code[OWNER_CODE_LENGTH - 1] == '\n') {
                    accounts[i].owner_code[OWNER_CODE_LENGTH - 1] = '\0';
                }
            }
            if(!check_sorted(accounts, n)) {
                merge_sort(accounts, 0, n - 1);
            }
            display_data(accounts, n);
            free(accounts);
        } else {
            fprintf(stderr,"Not able to allocate %lu bytes of memory\n", n * sizeof *accounts);
            exit(0);
        }
    }
    return EXIT_SUCCESS;
}

static void display_data(bank_accounts_t *const accounts, uint32_t n) {
    uint32_t accnt_count;
    for(uint32_t i = 0; i < n; i += accnt_count) {
        accnt_count = 1;
        char accnt_1[BANK_ACCNT_LENGTH],accnt_2[BANK_ACCNT_LENGTH];
        snprintf(accnt_1, BANK_ACCNT_LENGTH, "%s %s %s", accounts[i].control_digit, accounts[i].bank_code, accounts[i].owner_code);
        for(uint32_t j = i + 1; j < n; ++j) {
            snprintf(accnt_2, BANK_ACCNT_LENGTH, "%s %s %s", accounts[j].control_digit, accounts[j].bank_code, accounts[j].owner_code);
            if(strcmp(accnt_1, accnt_2) == 0) {
                ++accnt_count;
                continue;
            }
            break;
        }
        fputs(accounts[i].control_digit, stdout);
        printf(" ");
        fputs(accounts[i].bank_code, stdout);
        printf(" ");
        fputs(accounts[i].owner_code, stdout);
        printf(" %d\n", accnt_count);
    }
}

static bool check_sorted(bank_accounts_t *const accounts, uint32_t n) {
    bool is_sorted = true;
    char accnt_1[BANK_ACCNT_LENGTH], accnt_2[BANK_ACCNT_LENGTH];
    for(uint32_t i = 0; i < (n - 1); ++i) {
        snprintf(accnt_1, BANK_ACCNT_LENGTH, "%s %s %s", accounts[i].control_digit, accounts[i].bank_code, accounts[i].owner_code);
        snprintf(accnt_2, BANK_ACCNT_LENGTH, "%s %s %s", accounts[i + 1].control_digit, accounts[i + 1].bank_code, accounts[i + 1].owner_code);
        if(strcmp(accnt_1, accnt_2) > 0) {
            is_sorted = false;
            break;
        }
    }
    return is_sorted;
}

static void merge_sort(bank_accounts_t *const accounts, uint32_t start, uint32_t end) {
    if(start < end) {
        uint32_t mid = ((end - start) >> 1) + start;
        merge_sort(accounts, start, mid);
        merge_sort(accounts, mid + 1, end);
        merge_data(accounts, start, mid, end);
    }
}

static void merge_data(bank_accounts_t *const accounts, uint32_t start, uint32_t mid, uint32_t end) {
    uint32_t left_size = (mid - start) + 1;
    bank_accounts_t *const left_data = malloc(left_size * sizeof *left_data);
    if(left_data) {
        memcpy(left_data, &accounts[start], left_size * sizeof *accounts);
    } else {
        fprintf(stderr,"Not able to allocated %lu bytes of memory to left_data pointer\n", left_size * sizeof *left_data);
        exit(0);
    }
    uint32_t right_size = end - mid;
    bank_accounts_t *const right_data = malloc(right_size * sizeof *right_data);
    if(right_data) {
        memcpy(right_data, &accounts[mid + 1], right_size * sizeof *accounts);
    } else {
        fprintf(stderr,"Not able to allocate %lu bytes of memory to right_data pointer\n", right_size * sizeof *right_data);
        exit(0);
    }
    for(uint32_t k = start,i = 0, j = 0; k <= end; ++k) {
        if(i == left_size) {
            memcpy(&accounts[k], &right_data[j], sizeof *right_data);
            ++j;
        } else if(j == right_size) {
            memcpy(&accounts[k], &left_data[i], sizeof *left_data);
            ++i;
        } else {
            char accnt_1[BANK_ACCNT_LENGTH], accnt_2[BANK_ACCNT_LENGTH];
            snprintf(accnt_1, BANK_ACCNT_LENGTH, "%s %s %s", left_data[i].control_digit, left_data[i].bank_code, left_data[i].owner_code);
            snprintf(accnt_2, BANK_ACCNT_LENGTH, "%s %s %s", right_data[j].control_digit, right_data[j].bank_code, right_data[j].owner_code);
            if(strcmp(accnt_1, accnt_2) > 0) {
                memcpy(&accounts[k], &right_data[j], sizeof *right_data);
                ++j;
            } else {
                memcpy(&accounts[k], &left_data[i], sizeof *left_data);
                ++i;
            }
        }
    }
    free(left_data);
    free(right_data);
}
