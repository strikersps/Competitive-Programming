/*  Problem Statement:  https://codeforces.com/problemset/problem/231/A
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct contest_problem {
     unsigned short int member_1,member_2,member_3;
};
typedef struct contest_problem contest_problem_t;

const size_t count_solved_problems(contest_problem_t *const,size_t);

int main(void) {
    size_t n;
    scanf("%lu",&n);
    assert(n > 0 && n < 1001);
    contest_problem_t *const tot_problems_in_contest = malloc(n * sizeof(contest_problem_t));
    if(tot_problems_in_contest) {
        printf("%lu\n",count_solved_problems(tot_problems_in_contest,n));
        free(tot_problems_in_contest);
    } else {
        fprintf(stderr,"Memory not allocated to *tot_problems_in_contest pointer!\n");
    }
    return 0;
}

const size_t count_solved_problems(contest_problem_t *const tot_problems_in_contest,size_t n) {
    size_t tot_solved = 0;
    for(size_t i = 0; i < n; ++i) {
        scanf("%hu%hu%hu",&(tot_problems_in_contest[i].member_1),&(tot_problems_in_contest[i].member_2),&(tot_problems_in_contest[i].member_3));
        if((tot_problems_in_contest[i].member_1 && tot_problems_in_contest[i].member_2) || (tot_problems_in_contest[i].member_1 && tot_problems_in_contest[i].member_3) || (tot_problems_in_contest[i].member_2 && tot_problems_in_contest[i].member_3)){
            ++tot_solved;
        }
    }
    assert(tot_solved < 1001);  // answer will always be less than n
    return tot_solved;
}