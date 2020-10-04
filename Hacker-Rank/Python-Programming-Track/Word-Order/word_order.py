"""
Problem Statement: https://www.hackerrank.com/challenges/word-order/problem
Author: striker
"""

from collections import OrderedDict, Counter

def main():
    words = OrderedDict()
    for _ in range(int(input().strip())):
        word = input().strip()
        if word not in words:
            words[word] = 1
            continue
        words[word] += 1
    print(len(words))
    print(' '.join(str(value) for value in words.values()))

if __name__ == "__main__":
    main()