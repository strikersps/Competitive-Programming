/*  Problem Statement: https://www.spoj.com/problems/CANDY3/
    Author: Suraj Sharma
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>
#include<assert.h>

int main(void) {
    uint64_t test;
    scanf("%"SCNu64,&test);
    assert(test > 0);
    while(test--) {
        uint64_t no_of_students,left_out_chocolates = 0;
        scanf("%"SCNu64,&no_of_students);
        assert(no_of_students > 0);
        for(uint64_t i=0;i<no_of_students;++i) {
            uint64_t no_of_chocolates;
            scanf("%"SCNu64,&no_of_chocolates);
            assert(no_of_chocolates >= 0);
            left_out_chocolates += (no_of_chocolates % no_of_students);
        }
        if(!(left_out_chocolates % no_of_students)) {
                printf("YES\n");
        } else {
                printf("NO\n");
        }
    }
    return 0;
}