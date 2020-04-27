#include <iostream>

static int compute_last_digit(int, int, const int);

int main(void) {
    std :: ios :: sync_with_stdio(0); std :: cin.tie(NULL);
    int test;
    std :: cin >> test;
    while(test--) {
    	int a, b;
    	std :: cin >> a >> b;
    	std :: cout << compute_last_digit(a, b, 10) << std :: endl;
    }
    return 0;
}

static int compute_last_digit(int a, int b, const int modulus) {
	if(b == 1) {
		return a % 10;
	}
	if(a == 1) {
		return a;
	}
	long long int result = 1;
	for(; b; b >>= 1) {
		if(b & 1) {
			result = (result * a) % modulus;
		}
		a = (a * a) % modulus;
	}
	return result;
}
