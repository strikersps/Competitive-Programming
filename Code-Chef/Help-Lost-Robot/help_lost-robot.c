/*  Problem Statement: https://www.codechef.com/problems/ICPC16A
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<assert.h>

struct coordinates_2d {
    uint8_t x,y;
};
typedef struct coordinates_2d points_t;

void find_direction(points_t,points_t);

int main(void) {
    uint16_t test;
    scanf("%"SCNu16, &test);
    assert(test > 0 && test < 50001);
    while(test--) {
        points_t src,dst;
        scanf("%"SCNu8"%"SCNu8"%"SCNu8"%"SCNu8, &(src.x),&(src.y),&(dst.x),&(dst.y));
        assert(((src.x >= 0 && src.x < 101) && (src.y >= 0 && src.y < 101) && ((dst.x >= 0 && dst.x < 101) && (dst.y >= 0 && dst.y < 101))));
        find_direction(src,dst);
    }
    return EXIT_SUCCESS;
}

void find_direction(points_t src,points_t dst) {
    if(src.x == dst.x) {
        if(dst.y > src.y) {
            printf("up\n");
        } else {
            printf("down\n");
        }
    } else if(src.y == dst.y) {
        if(dst.x > src.x) {
            printf("right\n");
        } else {
            printf("left\n");
        }
    } else {
        printf("sad\n");
    }
}