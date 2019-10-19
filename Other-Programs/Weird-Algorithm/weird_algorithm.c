/*  Problem Statement: https://cses.fi/problemset/task/1068 or Refer to the readme.md file.
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<assert.h>

int main(void) {
    uint32_t n;
    printf("Enter the value of n\n");
    scanf("%"SCNu32, &n);
    assert(n > 0 && n < 1000001);
    while(n != 1) {
        printf("%"PRIu32" ", n);
        n = ((n & 1) ? ((3 * n) + 1) : n >> 1);
    }
    printf("%"PRIu32"\n", n);
    return 0;
}