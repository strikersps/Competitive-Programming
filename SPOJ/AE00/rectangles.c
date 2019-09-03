/*  Problem Statement: https://www.spoj.com/problems/AE00/
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<math.h>
#include<assert.h>

uint32_t find_number_rectangles(uint16_t);

int main(void) {
    uint16_t n; // number of square of side-length 1.
    scanf("%"SCNu16,&n);
    assert(n > 0 && n < 10001);
    printf("%"PRIu32"\n",find_number_rectangles(n));
    return 0;
}

uint32_t find_number_rectangles(uint16_t n) {
    uint32_t ans = n;
    uint32_t n_rows = floor(sqrt(n));
    for(uint16_t i=2;i<=n_rows;ans += (n/i),++i);
    ans -= ((n_rows * (n_rows-1)) >> 1);
    return ans;
}
