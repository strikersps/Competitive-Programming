#include<stdio.h>
#include<stdlib.h>

#define MODULUS 10

static int compute_last_digit(int, int);

int main(void) {
	int test;
	scanf("%d", &test);
	while(test--) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", compute_last_digit(a, b));
	}
	return EXIT_SUCCESS;
}

static int compute_last_digit(int base, int exponent) {
	int result;
	if(!base) {
		result = 0;
	} else if(!exponent) {
		result = 1;
	} else {
		result = 1;
		while(exponent) {
			if(exponent & 1) {
				result = (result * (base)) % MODULUS;
			}
			base = (base * base) % MODULUS;
			exponent >>= 1;
		}
	}
	return result;
}
