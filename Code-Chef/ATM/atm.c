/*  Problem Statement: https://www.codechef.com/problems/HS08TEST
 *  Author: striker
*/

#include<stdio.h>
#include<stdlib.h>

#define BANK_CHARGES 0.5

int main(void) {
    #ifndef ONLINE_JUDGE
        freopen("test-cases/test-case-1.in", "r", stdin);
        freopen("test-cases/test-case-1.out", "w", stdout);
    #endif
    double withdrawl_amt, curr_balance;
    scanf("%lf%lf", &withdrawl_amt, &curr_balance);
    if(!(((unsigned int) withdrawl_amt) % 5) && (curr_balance >= (withdrawl_amt + BANK_CHARGES))) {
        printf("%0.2lf\n", curr_balance - (withdrawl_amt + BANK_CHARGES));
    } else {
        printf("%0.2lf\n", curr_balance);
    }
    return EXIT_SUCCESS;
}
