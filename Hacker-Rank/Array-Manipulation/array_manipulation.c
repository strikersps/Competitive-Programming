/*  Problem Statement:  https://www.hackerrank.com/challenges/crush/problem
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<assert.h>

int main(void) {
    uint32_t n, m, start, end, k;
    int64_t *sequence = NULL;
    scanf("%"SCNu32"%"SCNu32, &n, &m);
    assert((n > 2 && n < 10000001) && (m > 0 && m < 200001));
    sequence = calloc(n, sizeof*sequence);
    if(sequence) {
        int64_t max_val = 0;
        for(uint32_t i = 0; i < m; ++i) {
            scanf("%"SCNu32"%"SCNu32"%"SCNu32, &start, &end, &k);
            assert((start > 0 && start <= end) && (end > 0 && end <= n));
			sequence[--start] += k;
            if(end < n) {
                sequence[end] -= k;
            }
        }
        uint64_t val = 0;
        for(uint32_t i = 0; i < n; ++i) {
            val += sequence[i];
            if(val > max_val) {
                max_val = val;
            }
        }
        printf("%"PRIu64"\n", max_val);
        free(sequence);
    } else {
        fprintf(stderr,"Memory not allocated to pointer name sequence!\n");
    }
    return 0;
}
