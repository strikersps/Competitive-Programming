/*  Problem Statement: https://www.hackerrank.com/challenges/sherlock-and-squares/problem
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<math.h>
#include<assert.h>

int main(void) {
    uint8_t test;
    printf("Enter the number of test cases\n");
    scanf("%"SCNu8,&test);
    assert(test > 0 && test < 101);
    while(test--) {
        uint64_t start,end;
        printf("Enter the start & end range\n");
        scanf("%"SCNu64"%"SCNu64,&start,&end);
        assert((start > 0 && start <= end) && (end >= 0 && end <= 1000000001));
        int64_t no_of_square_int = 0;
        if(!(end - start)) {
            if(sqrt(start) == (uint64_t)sqrt(start)) {
                ++no_of_square_int;
            }
        } else {
            no_of_square_int = ((floor(sqrt(end)) - ceil(sqrt(start)))) + 1;
        }
        printf("%"PRIu64"\n",no_of_square_int);
    }
    return 0;
}