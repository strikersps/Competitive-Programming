/*  Problem Statement: https://www.codechef.com/INFY2019/problems/INF1912
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<inttypes.h>
#include<assert.h>

typedef unsigned long long ull_t;
typedef long long ll_t;

const ull_t compute_gcd(ull_t,ull_t);

int main(void) {
    size_t test;
    scanf("%lu", &test);
    assert(test > 0 && test < 11);
    while(test--) {
        ull_t n,k;
        scanf("%llu%llu", &n,&k);
        assert((n > 0 && n < 100001) && (k > 0 && k < 100001));
        bool *const tot_rows = calloc(n,sizeof(bool));
        bool *const tot_cols = calloc(n,sizeof(bool));
        if(tot_rows && tot_cols) {
            for(size_t i = 0; i < k; ++i) {
                size_t r_i,c_i;
                scanf("%lu%lu", &r_i,&c_i);
                assert((r_i > 0 && r_i <= n) && (c_i > 0 && c_i <= n));
                tot_rows[r_i - 1] = true;
                tot_cols[c_i - 1] = true;
            }
            ull_t tot_empty_grids, tot_empty_row_grid, tot_empty_cols_grids;
            tot_empty_row_grid = tot_empty_cols_grids = 0;
            for(size_t i = 0; i < n; ++i) {
                if(!(tot_rows[i])) {
                    ++tot_empty_row_grid;
                }
                if(!(tot_cols[i])) {
                    ++tot_empty_cols_grids;
                }
            }
            tot_empty_grids = (tot_empty_cols_grids * tot_empty_row_grid);
            if(!tot_empty_grids) {
                printf("Impossible\n");
            } else {
                ull_t gcd_val = compute_gcd(tot_empty_grids,(n * n));
                if(gcd_val == 1) {
                    printf("%llu %llu\n", tot_empty_grids, (n * n));
                } else {
                    printf("%llu %llu\n", (tot_empty_grids / gcd_val),((n * n) / gcd_val));
                }
            }
            free(tot_rows);
            free(tot_cols);
        } else {
            if(tot_rows) {
                fprintf(stderr,"Memory not allocated to *tot_rows pointer!\n");
            } else {
                fprintf(stderr,"Memory not allocated to *tot_cols pointer!\n");
            }
        }
    }
    return 0;
}

const ull_t compute_gcd(ull_t a,ull_t b) {
    if(!b) {
        return a;
    } else {
        return compute_gcd(b,(a % b));
    }
}