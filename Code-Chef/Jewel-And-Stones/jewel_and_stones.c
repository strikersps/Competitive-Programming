/*  Problem Statement: https://www.codechef.com/problems/STONES
 *  Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>

typedef unsigned long long ull_t;
typedef long long ll_t;

#define NUMBER_OF_ALPHABETS 26
#define MAX_STRING_LENGTH 101

#define CONSTRAINTS_NOT_SATISFIED(variable, constraints) fprintf(stderr,"Line number: %u: Constraints of <%s> variable is not fulfilled, i.e. %s.\n", __LINE__, #variable, constraints)

typedef struct alphabet_frequency {
    int lower_case_count, upper_case_count;
} alphabet_frequency_t;

static int compute_total_jewels_found(const char*, const char*);

int main(void) {
    int test;
    scanf("%d", &test);
    if(test < 1 || test > 100) {
        CONSTRAINTS_NOT_SATISFIED(test, "1 <= test <= 100");
        exit(0);
    }
    while(test--) {
        char jewel_string[MAX_STRING_LENGTH];
        char mined_string[MAX_STRING_LENGTH];
        scanf("%s%s", jewel_string, mined_string);
        printf("%d\n", compute_total_jewels_found(jewel_string, mined_string));
    }
    return EXIT_SUCCESS;
}


static int compute_total_jewels_found(const char *jewel_string, const char *mined_string) {
    alphabet_frequency_t frequency_table[NUMBER_OF_ALPHABETS];
    memset(frequency_table, 0, NUMBER_OF_ALPHABETS * sizeof(alphabet_frequency_t));
    char read_char;
    while(0 != (read_char = *jewel_string++)) {
        if(islower(read_char)) {
            ++frequency_table[read_char - 'a'].lower_case_count;
        } else {
            ++frequency_table[read_char - 'A'].upper_case_count;
        }
    }
    int jewels_count = 0;
    while(0 != (read_char = *mined_string++)) {
        if((islower(read_char) && frequency_table[read_char - 'a'].lower_case_count) || (isupper(read_char) && frequency_table[read_char - 'A'].upper_case_count)) {
            ++jewels_count;
        }
    }
    return jewels_count;
}
