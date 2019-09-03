/*  Problem Statement: https://www.hackerrank.com/challenges/grading/problem
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<assert.h>

void take_input(uint8_t*,uint8_t);

int main(void) {
    uint8_t n,*student_grade = NULL;
    printf("Enter the number of students\n");
    scanf("%"SCNu8,&n);
    assert(n > 0 && n < 61);
    student_grade = calloc(sizeof(uint8_t),n);
    if(student_grade) {
        take_input(student_grade,n);
        for(uint8_t i=0;i<n;++i) {
            if(student_grade[i] % 5) {
                uint8_t next_multiple_of_five = (student_grade[i] - (student_grade[i] % 5)) + 5;
                if((student_grade[i] >= 38) && (abs(student_grade[i] - next_multiple_of_five) < 3)) {
                    student_grade[i] = next_multiple_of_five;
                }
            }
            printf("%"PRIu8"\n",student_grade[i]);
        }
        free(student_grade);
    } else {
        fprintf(stderr,"19:Memory not allocated to student_grade pointer!\n");
    }
    return 0;
}

void take_input(uint8_t *student_grade,uint8_t n) {
    for(uint8_t i=0;i<n;++i) {
        scanf("%"SCNu8,&student_grade[i]);
        assert(student_grade[i] > -1 && student_grade[i] < 101);
    }
}