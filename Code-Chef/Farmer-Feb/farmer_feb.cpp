/*
 * Problem Statement: https://www.codechef.com/problems/POTATOES
 * Author: striker
*/

#include <bits/stdc++.h>

#define FAST_IO(value) std :: ios :: sync_with_stdio(value); std :: cin.tie(value)
#define MAX_LIMIT 1000

static bool check_prime(const int);

int main(void) {
    FAST_IO(0);
    int test;
    std :: cin >> test;
    while(test--) {
        int x, y;
        std :: cin >> x >> y;
        for(register int i = 1; i <= MAX_LIMIT; ++i) {
            if(check_prime(x + y + i)) {
                std :: cout << i << std :: endl;
                break;
            }
        }
    }
    return 0;
}

static bool check_prime(const int n) {
    if(n == 2 || n == 3) {
        return true;
    }
    if(n == 1 || !(n % 2) || !(n % 3)) {
        return false;
    }
    bool is_prime = true;
    for(register int i = 5; i * i <= n; ++i) {
        if(!(n % i)) {
            is_prime = false;
            break;
        }
    }
    return is_prime;
}
