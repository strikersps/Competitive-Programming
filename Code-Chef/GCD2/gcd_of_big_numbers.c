#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGITS 251

typedef unsigned long long ull_t;

static ull_t compute_mod(char[], const ull_t);
static ull_t compute_gcd(ull_t, ull_t);

int main(void) {
    int test;
    scanf("%d", &test);
    while(test--) {
        ull_t a;
        char b[MAX_DIGITS];
        scanf("%llu%s", &a, b);
        if(!a) {
            printf("%s\n", b);
        } else {
            ull_t b_mod_a = compute_mod(b, a);
            printf("%llu\n", compute_gcd(a, b_mod_a));
        }
    }
    return EXIT_SUCCESS;
}

static ull_t compute_mod(char b[], const ull_t modulus) {
    ull_t remainder = 0;
    if(modulus) {
        for(unsigned int i = 0; '\0' != b[i]; ++i) {
            remainder = (10 * remainder + (b[i] - '0')) % modulus;
        }
    }
    return remainder;
}

static ull_t compute_gcd(ull_t a, ull_t b) {
    if(!b) {
        return a;
    }
    return compute_gcd(b, (a % b));
}
