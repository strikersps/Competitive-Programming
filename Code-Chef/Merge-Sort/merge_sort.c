/*  Problem Statement: https://www.codechef.com/problems/MRGSRT
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<assert.h>

#define NOT_POSSIBLE -1

void binary_search(uint16_t,uint16_t,uint16_t);

int main(void) {
    uint16_t test;
    scanf("%"SCNu16,&test);
    assert(test > 0 && test < 10001);
    while(test--) {
        uint16_t start,end,index;
        scanf("%"SCNu16"%"SCNu16"%"SCNu16,&start,&end,&index);
        assert((start >= 0 && start < 1001) && (end >= 0 && end < 1001) && (index >= 0 && index < 1001));
        if(start > index) {
            printf("%"PRId8"\n",NOT_POSSIBLE);
        } else {
            binary_search(start,end,index);
        }
    }
    return 0;
}

void binary_search(uint16_t start,uint16_t end,uint16_t index) {
    static uint16_t depth;
    ++depth;
    printf("%"PRIu16" %"PRIu16"\n",start,end);
    if(start < end) {
        uint16_t mid = ((end - start) >> 1) + start;
        if(index > mid) {
            binary_search((mid + 1),end,index);
        } else {
            binary_search(start,mid,index);
        }
    }
    if(start ==  end) {
        printf("%"PRIu16"\n",depth);
        depth = 0;
    }
}