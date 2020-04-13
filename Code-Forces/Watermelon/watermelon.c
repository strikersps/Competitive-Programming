/*  Problem Statement: https://codeforces.com/problemset/problem/4/A
    Author: striker
*/

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

bool is_partition_possible(uint8_t);

int main(void) {
    uint8_t weight;
    scanf("%"SCNu8,&weight);
    assert(weight > 0 && weight < 101);
    if(is_partition_possible(weight)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}

bool is_partition_possible(uint8_t weight) {
    bool flag = false;
    if(!(weight & 1)) {
        uint8_t quotient = weight >> 1;
        while((quotient & 1) && (quotient != 1)) {
            quotient = weight / quotient;
        }
        if (!((weight - quotient) & 1)) {
            flag = true;
        }
    } else {
        flag = false;
    }
    return flag;
}
