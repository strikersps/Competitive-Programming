/*  Problem Statement: https://www.spoj.com/problems/HANDS/
    Author: srtiker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<string.h>
#include<math.h>
#include<assert.h>

#define STRING_LENGTH 6
#define LOOK_UP_TABLE_LENGTH 11
#define MEET_TIME_CONSTANT_1 5.45454545455
#define MEET_TIME_CONSTANT_2 0.91666666666

typedef struct time_digital {
    uint16_t hr,min;
} time_digital_t;

time_digital_t meet_times_lookup_table[LOOK_UP_TABLE_LENGTH];

uint16_t find_meet_times(char[],char[]);

int main(void) {
    uint64_t test;
    char start_time[STRING_LENGTH],end_time[STRING_LENGTH];
    scanf("%"SCNu64,&test);
    assert(test>0);
    for(uint16_t i=0;i<LOOK_UP_TABLE_LENGTH;++i) {
        meet_times_lookup_table[i].hr = i;
        meet_times_lookup_table[i].min = ceil(MEET_TIME_CONSTANT_1*i); 
    }
    while(test--) {
        scanf("%s%s",start_time,end_time);
        printf("%"PRIu16"\n",find_meet_times(start_time,end_time));
    }
    return 0;
}

uint16_t find_meet_times(char start_time[],char end_time[]) {
    uint16_t start_time_hr,start_time_min,end_time_hr,end_time_min;
    char *buffer = calloc(sizeof(char),STRING_LENGTH);
    start_time_hr = start_time_min = end_time_hr = end_time_min = 0;
    if(buffer) {
        snprintf(buffer,STRING_LENGTH,"%s",start_time);
        start_time_hr = atoi(__strtok_r(buffer,":",&buffer));
        start_time_min = atoi(__strtok_r(NULL,":",&buffer));
        buffer -= strlen(start_time);
        snprintf(buffer,STRING_LENGTH,"%s",end_time);
        end_time_hr = atoi(__strtok_r(buffer,":",&buffer));
        end_time_min = atoi(__strtok_r(NULL,":",&buffer));
        buffer -= strlen(end_time);
        free(buffer);
    } else fprintf(stderr,"Memory not allocated to buffer pointer\n");
    uint16_t meet_count = 0;
    meet_count = (ceil(MEET_TIME_CONSTANT_2*end_time_hr)) - ceil(MEET_TIME_CONSTANT_2*start_time_hr);
    if((!(end_time_hr == 11 || end_time_hr == 23)) && (end_time_min >= (meet_times_lookup_table[end_time_hr%12].min))) {
        ++meet_count;
    }
    if((meet_count > 0) && (!(start_time_hr == 11 || start_time_hr == 23)) && (start_time_min == (meet_times_lookup_table[start_time_hr%12].min))) {
        --meet_count;
    }
    return meet_count;
}
