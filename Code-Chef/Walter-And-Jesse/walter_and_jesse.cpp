/*
 * Problem Statement: https://www.codechef.com/CHPTRS01/problems/FUNRUN/
 * Author: striker
*/

#include <bits/stdc++.h>

#define FAST_IO(value) std :: ios :: sync_with_stdio(value); std :: cin.tie(value)

int main() {
    FAST_IO(0);
    int test;
    std :: cin >> test;
    while(test--) {
        int n;
        std :: cin >> n;
        std :: vector <int> team_a(n), team_b(n);
        for(register int i=0; i < n; i++) {
            std :: cin >> team_a[i];
        }
        for(register int i = 0; i < n; i++) {
            std :: cin >> team_b[i];
        }
        std :: cout << (*max_element(team_a.begin(), team_a.end()) == *max_element(team_b.begin(), team_b.end()) ? "NO" : "YES") << std :: endl;
    }
    return 0;
}
