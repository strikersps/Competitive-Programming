/*  Problem Statement: https://www.hackerrank.com/challenges/strange-advertising/problem
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<assert.h>

int main(void) {
    uint8_t number_of_days;
    scanf("%"SCNu8, &number_of_days);
    assert(number_of_days > 0 && number_of_days < 51);
    uint32_t recipients  = 5, no_of_people_liked = 0;
    for(uint8_t i = 0; i < number_of_days; ++i) {
        no_of_people_liked += recipients >> 1;
        recipients = (recipients >> 1) * 3;
    }
    printf("%"PRIu32"\n", no_of_people_liked);
    return EXIT_SUCCESS;
}