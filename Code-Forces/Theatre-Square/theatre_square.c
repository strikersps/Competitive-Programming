/*  Problem Statement:  https://codeforces.com/contest/1/problem/A
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>

#define MAX_VALUE 1000000001

typedef unsigned long ul;
typedef unsigned long long ull;

int main(void) {
    ull length, breadth, side_length;
    scanf("%llu%llu%llu", &length,&breadth,&side_length);
    assert((length > 0 && length < MAX_VALUE) && (breadth > 0 && breadth < MAX_VALUE) && (side_length > 0 && side_length < MAX_VALUE));
    ull min_number_of_flagstones = 0;
    min_number_of_flagstones = ceil(((double) length / (double) side_length)) * ceil(((double) breadth / (double) side_length));
    printf("%llu\n", min_number_of_flagstones);
    return 0;
}