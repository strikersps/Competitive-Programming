/*  Problem Statement: https://www.hackerrank.com/contests/core-intra/challenges/clock-hands/problem
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<string.h>
#include<math.h>
#include<assert.h>

#define MAX_LENGTH 6

static double compute_angle_between_hands(const uint8_t,const uint8_t);

int main(void) {
    uint8_t test;
    scanf("%"SCNu8, &test);
    assert(test > 0 && test < 11);
    while(test--) {
        char time[MAX_LENGTH];
        scanf("%s", time);
        uint8_t len = strlen(time) + 1;
        char *buffer = calloc(sizeof(char),len);
        snprintf(buffer,len,"%s",time);
        uint8_t hr = atoi(__strtok_r(buffer,":",&buffer));
        uint8_t min = atoi(__strtok_r(NULL,":",&buffer));
        assert(min >= 0 && min < 61);
        if(min == 60) {
            min = 0;
            hr += 1;
        }
        if(hr > 12 && hr < 25) {
            hr %= 12;
        }
        assert(hr >= 0 && hr < 13);
        double angle_between_hands = compute_angle_between_hands(hr,min);
        if(floor(angle_between_hands) == angle_between_hands) {
            printf("%"PRIu8"\n", (int)(angle_between_hands));
        } else {
            printf("%0.1lf\n", angle_between_hands);
        }
    }
    return EXIT_SUCCESS;
}

static double compute_angle_between_hands(const uint8_t hr,const uint8_t min) {
    double hr_angle,min_angle;
    hr_angle = (30 * hr) + (0.5 * min);
    min_angle = 6 * min;
    double angle_between_hands = 0.0;
    angle_between_hands = fabs(hr_angle - min_angle);
    if(angle_between_hands > 180) {
        angle_between_hands = 360 - angle_between_hands;
    }
    return angle_between_hands;
}