#include<stdio.h>
#include<inttypes.h>
#include<assert.h>

uint32_t find_last_digit(uint32_t,uint32_t);

int main(void) {
    uint8_t test;
    uint32_t a,b;
    for(scanf("%"SCNu8,&test);test;--test) {
        scanf("%"SCNu32"%"SCNu32,&a,&b);
        assert((a>=0 && a<21)&&(b>=0 && b<2147483001));
        printf("%"PRIu32"\n",find_last_digit(a,b));
    }
    return 0;
}

uint32_t find_last_digit(uint32_t base,uint32_t exponent) {
    uint32_t result = 1;
    while(exponent) {
        if(exponent & 1) result = (result*base) % 10;
        base = (base*base) % 10;
        exponent >>= 1;
    }
    return result;
}