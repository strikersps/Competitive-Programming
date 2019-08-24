/*  Problem Statement: https://www.spoj.com/problems/AP2/
    Author: Suraj Sharma
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<math.h>
#include<stdbool.h>
#include<assert.h>

typedef long long ll;

void print_series(ll,ll,ll); // Print the members of the series.

int main(void) {
    uint16_t test;
    ll third_term,third_last_term,series_sum,no_of_terms,common_diff,first_term;
    fscanf(stdin,"%hd",&test);
    assert(test>0 && test<101);
    while(test--) {
        fscanf(stdin,"%lld%lld%lld",&third_term,&third_last_term,&series_sum);
        no_of_terms = floor(2*((double)((double)series_sum/(double)(third_term+third_last_term))));
        fprintf(stdout,"%lld\n",no_of_terms);
        common_diff = (third_term-third_last_term)/(2-no_of_terms+3); // common_diff = first_term - second_term
        first_term = third_term-(2*common_diff);
        print_series(first_term,common_diff,no_of_terms);
    }
    return 0;
}

void print_series(ll first_term,ll common_diff,ll no_of_terms) {
    for(ll i=0;i<no_of_terms;++i) fprintf(stdout,"%lld ",(first_term+(i*common_diff)));
    fprintf(stdout,"\n");
}