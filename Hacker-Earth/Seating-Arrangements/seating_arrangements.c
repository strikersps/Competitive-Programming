/*  Problem Statement: https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/seating-arrangement-1/description/
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<assert.h>

void find_front_seat(uint8_t);

int main(void) {
    uint32_t test;
    scanf("%"SCNu32,&test);
    assert(test > 0 && test < 100001);
    while(test--) {
        uint8_t seat_no;
        scanf("%"SCNu8,&seat_no);
        assert(seat_no > 0 && seat_no < 109);
        find_front_seat(seat_no);
    }
    return 0;
}

void find_front_seat(uint8_t seat_no) {
    switch(seat_no % 12) {
        case 0:
            printf("%"PRIu8" WS\n",(seat_no - 11));
            break;
        case 1:
            printf("%"PRIu8" WS\n",(seat_no + 11));
            break;
        case 2:
            printf("%"PRIu8" MS\n",(seat_no + 9));
            break;
        case 3:
            printf("%"PRIu8" AS\n",(seat_no + 7));
            break;
        case 4:
            printf("%"PRIu8" AS\n",(seat_no + 5));
            break;
        case 5:
            printf("%"PRIu8" MS\n",(seat_no + 3));
            break;
        case 6:
            printf("%"PRIu8" WS\n",(seat_no + 1));
            break;
        case 7:
            printf("%"PRIu8" WS\n", (seat_no - 1));
            break;
        case 8:
            printf("%"PRIu8" MS\n",(seat_no - 3));
            break;
        case 9:
            printf("%"PRIu8" AS\n",(seat_no - 5));
            break;
        case 10:
            printf("%"PRIu8" AS\n",(seat_no - 7));
            break;
        case 11:
            printf("%"PRIu8" MS\n",(seat_no - 9));
            break;
    }
}