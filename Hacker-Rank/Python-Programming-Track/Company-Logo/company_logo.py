"""
Problem Statement: https://www.hackerrank.com/challenges/most-commons/problem
Author: striker
"""

from collections import Counter

def decide_logo(alphabet_freq: tuple) -> list:
    is_all_freq_same = all(alphabet_freq[0][1] == t[1] for t in alphabet_freq)
    if is_all_freq_same:
        return sorted(alphabet_freq)
    alphabet_freq = sorted(alphabet_freq, key = lambda x: x[1], reverse = True)
    for index in range(len(alphabet_freq) - 1):
        if alphabet_freq[index][1] == alphabet_freq[index + 1][1] and alphabet_freq[index][0] > alphabet_freq[index + 1][0]:
            alphabet_freq[index], alphabet_freq[index + 1] = alphabet_freq[index + 1], alphabet_freq[index]
    return alphabet_freq

def main():
    for key, value in decide_logo(tuple(Counter(input().strip()).items()))[:3]:
        print(f'{key} {value}')


if __name__ == "__main__":
    main()