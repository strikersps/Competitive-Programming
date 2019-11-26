/*  Problem Statement: https://www.hackerrank.com/challenges/constructing-a-number/problem
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<assert.h>

int main(void) {
    uint8_t test;
    scanf("%"SCNu8, &test);
    assert(test > 0 && test < 101);
    while(test--) {
        uint8_t n;
        scanf("%"SCNu8, &n);
        assert(n > 0 && n < 101);
        uint64_t number, sum_of_numbers = 0;
        for(uint8_t i = 0; i < n; ++i) {
            scanf("%"SCNu64, &number);
            assert(number > 0 && number < 1000000001);
            sum_of_numbers += number;
        }
        printf("%s", ((sum_of_numbers % 3) ? "No\n" : "Yes\n"));
    }
    return EXIT_SUCCESS;
}