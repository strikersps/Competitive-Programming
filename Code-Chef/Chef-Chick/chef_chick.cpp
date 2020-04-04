/*  Problem Statement: https://www.codechef.com/problems/CHFCHK
 *  Author: striker
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std :: ios :: sync_with_stdio(false); std :: cin.tie(0); // For Fast IO
    int test;
    std::cin >> test;
    while(test--) {
        int n;
        std :: cin >> n;
        std :: vector <int> data(n);
        for(unsigned int i = 0; i < data.size(); ++i) {
            std :: cin >> data[i];
        }
        std::cout << *min_element(data.begin(), data.end()) << std :: endl;
    }
    return 0;
}
