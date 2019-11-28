/*  Problem Statement: https://www.hackerrank.com/challenges/library-fine/problem
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<assert.h>

#define DAYS_LATE_FINE 15
#define MONTH_LATE_FINE 500
#define YEAR_LATE_FINE_FIXED 10000

typedef struct date {
    uint16_t day,month,year;
} date_t;

uint32_t compute_total_fine(date_t *const,date_t *const);

int main(void) {
    date_t returned_date,due_date;
    scanf("%"SCNu16"%"SCNu16"%"SCNu16, &returned_date.day,&returned_date.month,&returned_date.year);
    assert((returned_date.day > 0 && returned_date.day < 32) && (returned_date.month > 0 && returned_date.month < 13) && (returned_date.year > 0 && returned_date.year < 3001));
    scanf("%"SCNu16"%"SCNu16"%"SCNu16, &due_date.day,&due_date.month,&due_date.year);
    assert((due_date.day > 0 && due_date.day < 32) && (due_date.month > 0 && due_date.month < 13) && (due_date.year > 0 && due_date.year < 3001));
    printf("%"PRIu32"\n", compute_total_fine(&returned_date,&due_date));
    return EXIT_SUCCESS;
}

uint32_t compute_total_fine(date_t *const returned_date,date_t *const due_date) {
    uint32_t total_fine = 0;
    if((returned_date->year) != (due_date->year)) {
        if((returned_date->year) > (due_date->year)) {
            total_fine = YEAR_LATE_FINE_FIXED;
        }
    } else if((returned_date->month) != (due_date->month)) {
        if((returned_date->month) > (due_date->month)) {
            total_fine = MONTH_LATE_FINE * ((returned_date->month) - (due_date->month));
        }
    } else {
        if((returned_date->day) > (due_date->day)) {
            total_fine = DAYS_LATE_FINE * ((returned_date->day) - (due_date->day));
        }
    }
    return total_fine;
}