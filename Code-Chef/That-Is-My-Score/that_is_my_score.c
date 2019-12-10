/*  Problem Statement: https://www.codechef.com/DEC19B/problems/WATSCORE
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<string.h>
#include<assert.h>

#define MAX_NUMBER_OF_PROBLEMS 11

int main(void) {
    int8_t test;
    scanf("%"SCNu8, &test);
    assert(test > 0 && test < 11);
    while(test--) {
        uint8_t total_problems[MAX_NUMBER_OF_PROBLEMS];
        memset(total_problems,0,(sizeof(uint8_t) * MAX_NUMBER_OF_PROBLEMS));
        int16_t no_of_submissions;
        scanf("%"SCNu16, &no_of_submissions);
        assert(no_of_submissions > 0 && no_of_submissions < 1001);
        while(no_of_submissions--) {
            uint8_t problem_id,score;
            scanf("%"SCNu8"%"SCNu8, &problem_id,&score);
            assert((problem_id > 0 && problem_id < 12) && (score >= 0 && score < 101));
            if(problem_id == 9 || problem_id == 10 || problem_id == 11) {
                continue;
            }
            if(total_problems[problem_id - 1] < score) {
                total_problems[problem_id - 1] = score;
            }
        }
        uint32_t total_score = 0;
        for(uint8_t i = 0; i < MAX_NUMBER_OF_PROBLEMS; ++i) {
            total_score += total_problems[i];
        }
        printf("%"PRIu32"\n", total_score);
    }
    return EXIT_SUCCESS;
}