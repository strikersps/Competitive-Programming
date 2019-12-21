/*  Problem Statement: https://www.codechef.com/problems/FLOW005
    Author: striker
*/

#include<bits/stdc++.h>

using namespace std;

int main(void) {
    int test;
    std :: cin >> test;
    while(test--) {
        unsigned int n, number_of_notes;
        std :: cin >> n;
        number_of_notes = 0;
        while(n) {
            if(n >= 100) {
                number_of_notes += n / 100;
                n %= 100;
            } else if(n >= 50) {
                number_of_notes += n / 50;
                n %= 50;
            } else if(n >= 10) {
                number_of_notes += n / 10;
                n %= 10;
            } else if(n >= 5) {
                number_of_notes += n / 5;
                n %= 5;
            } else if(n >= 2) {
                number_of_notes += n / 2;
                n %= 2;
            } else if(n >= 1) {
                number_of_notes += number_of_notes;
                n = 0;
            }
        }
        std :: cout << number_of_notes << endl;
    }
    return 0;
}
