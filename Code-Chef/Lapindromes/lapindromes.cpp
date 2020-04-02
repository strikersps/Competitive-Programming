/*
 * Problem Statement: https://www.codechef.com/problems/LAPIN
 * Author: striker
*/

#include <bits/stdc++.h>

#define FAST_IO(value) std :: ios :: sync_with_stdio(value); std :: cin.tie(value)

static bool check_lapindrome(std :: string &);

int main(void) {
    FAST_IO(0);
    int test;
    std :: cin >> test;
    while(test--) {
        std :: string word;
        std :: cin >> word;
        std :: cout << (check_lapindrome(word) ? "YES" : "NO") << std :: endl;
    }
    return 0;
}

static bool check_lapindrome(std :: string & word) {
    std :: unordered_map <char, int> alphabet_freq_map;
    int word_len = word.length();
    for(register int i = 0; i < word_len; ++i) {
        if(i < (word_len >> 1)) {
            ++alphabet_freq_map[word[i]];
            continue;
        }
        if(i == (word_len >> 1) && word_len % 2) {
            continue;
        }
        --alphabet_freq_map[word[i]];
    }
    size_t zero_count = 0;
    for(auto &alphabet : alphabet_freq_map) {
        if(alphabet.second) {
            break;
        }
        ++zero_count;
    }
    return zero_count == alphabet_freq_map.size() ? true : false;
}
