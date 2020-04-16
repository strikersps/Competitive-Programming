/*
 * Problem Statement: https://www.codechef.com/APRIL20B/problems/CARSELL
 * Author: striker
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define FAST_IO(value) std :: ios :: sync_with_stdio(value); std :: cin.tie(value)
#define MOD 1000000007

static int compute_maximum_profit(std :: vector <int> &, const int);

int main(void) {
    FAST_IO(0);
    int test;
    std :: cin >> test;
    while(test--) {
        int n;
        std :: cin >> n;
        std :: vector <int> car_price(n);
        for(int i = 0; i < n; ++i) {
            std :: cin >> car_price[i];
        }
        std :: sort(car_price.rbegin(), car_price.rend()); // Sorts the data in decreasing order.
        std :: cout << compute_maximum_profit(car_price, n) << std :: endl;
    }
    return 0;
}

static int compute_maximum_profit(std :: vector <int> & car_price, const int n) {
    int max_profit = 0;
    for(int i = 0; i < n; ++i) {
        if(car_price[i] - i > 0) {
            car_price[i] -= i;
            max_profit = (max_profit + car_price[i]) % MOD;
        }
    }
    return max_profit;
}
