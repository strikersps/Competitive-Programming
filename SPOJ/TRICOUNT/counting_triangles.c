#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int test;
    if(1 == scanf("%d", &test)) {
        while(test--) {
            long long int n;
            if(1 == scanf("%lld", &n)) {
                long long int total_triangle = (n * (n + 2) * ((n << 1) + 1)) / 8;
                printf("%lld\n", total_triangle);
                continue;
            }
        }
    }
    return EXIT_SUCCESS;
}
