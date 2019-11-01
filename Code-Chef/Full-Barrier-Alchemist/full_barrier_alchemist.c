/*  Problem Statement: https://www.codechef.com/DCOD19A/problems/PIPSQUIK
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int main(void) {
    int test;
    scanf("%d", &test);
    while(test--) {
        int n,h,y_1,y_2,l;
        scanf("%d%d%d%d%d", &n,&h,&y_1,&y_2,&l);
        int barrier_crossed_count = 0;
        for(int i = 0; i < n; ++i) {
            int type;
            int barrier_height;
            scanf("%d%d", &type,&barrier_height);
            if((type == 1) && ((h - y_1) > barrier_height)) {
                --l;
            } else if((type == 2) && (barrier_height > y_2)) {
                --l;
            }
            if(l > 0) {
                ++barrier_crossed_count;
            }
        }
        printf("%d\n", barrier_crossed_count);
    }
    return EXIT_SUCCESS;
}