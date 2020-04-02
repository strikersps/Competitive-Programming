/*
 * Problem Statement: https://www.codechef.com/CHPTRS01/problems/FUNRUN/
 * Author: striker
*/

#include <bits/stdc++.h>
using namespace std;

#define FAST_IO(value) ios :: sync_with_stdio(value); cin.tie(value)

int main() {
    FAST_IO(0);
    int test;
    cin >> test;
    while(test--) {
        int n;
        cin >> n;
        vector <int> team_a(n), team_b(n);
        for(register int i=0; i < n; i++) {
            cin >> team_a[i];
        }
        for(register int i = 0; i < n; i++) {
            cin >> team_b[i];
        }
        cout << (*max_element(team_a.begin(), team_a.end()) == *max_element(team_b.begin(), team_b.end()) ? "NO" : "YES") << endl;
    }
    return 0;
}
