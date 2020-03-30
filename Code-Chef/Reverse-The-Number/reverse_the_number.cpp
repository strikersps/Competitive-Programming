/*  Problem Statement: https://www.codechef.com/problems/FLOW007
    Author: striker
*/

#include <bits/stdc++.h>

static unsigned int compute_reverse_number(unsigned int);

int main(void) {
    int test;
    std :: cin >> test;
    while(test--) {
        unsigned int n;
        std :: cin >> n;
        std :: cout << compute_reverse_number(n) << std :: endl;
    }
    return 0;
}

static unsigned int compute_reverse_number(unsigned int n) {
    unsigned int reverse_number = 0;
    while(n) {
        reverse_number = (10 * reverse_number) + (n % 10);
        n /= 10;
    }
    return reverse_number;
}
