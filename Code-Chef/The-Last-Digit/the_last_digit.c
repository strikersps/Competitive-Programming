/*	Problem Statement: https://www.codechef.com/problems/DEM8
	Author: striker
*/

#include<stdio.h>
#include<stdlib.h>

typedef unsigned long long ull_t;
typedef long long ll_t;

#define MEMORY_NOT_ALLOCATED_ERROR(variable, bytes) fprintf(stderr, "Line number: %u: Not able to allocate <%lu> bytes of memory to %s variable.\n", __LINE__, (bytes), (#variable))
#define CONSTRAINTS_NOT_SATISFIED_ERROR(variable, constraints) fprintf(stderr, "Line number: %u: Constraints not satisfied for the variable <%s> i.e. %s\n", __LINE__, #variable, #constraints)
#define MODULUS 10

static int compute_last_digit(int, int);

int main(void) {
	#ifndef ONLINE_JUDGE
		freopen("test-cases/test-case-1.in", "r", stdin);
		freopen("test-cases/test-case-1.out", "w", stdout);
	#endif
	int test;
	scanf("%d", &test);
	if(test < 1 || test > 30) {
		CONSTRAINTS_NOT_SATISFIED_ERROR(test, 1 <= test <= 30);
		exit(0);
	}
	while(test--) {
		int a, b;
		scanf("%d%d", &a, &b);
		if(a < 0 || a > 20) {
			CONSTRAINTS_NOT_SATISFIED_ERROR(a, 0 <= a <= 20);
			exit(0);
		}
		if(b < 0 || b > 2147483000) {
			CONSTRAINTS_NOT_SATISFIED_ERROR(b, 0 <= b <= 2147483000);
			exit(0);
		}
		if(!a && !b) {
			fprintf(stderr, "Line number: Both a and b cannot be zero\n");
			exit(0);
		}
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