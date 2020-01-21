/*  Problem Statement: https://www.codechef.com/problems/CHFCHK
 *  Author: striker
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); // For Fast IO
    int test;
    std::cin >> test;
    while(test--) {
        int n;
        std::cin >> n;
        std::vector<int> data(n);
        for(unsigned int i = 0; i < data.size(); ++i) {
            cin >> data[i];
        }
        std::cout << *std::min_element(data.begin(), data.end()) << endl;
    }
    return 0;
}
