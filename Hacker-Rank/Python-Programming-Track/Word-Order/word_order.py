"""
Problem Statement: https://www.hackerrank.com/challenges/word-order/problem
Author: striker
"""

from collections import OrderedDict

def main():
    words = OrderedDict()
    for _ in range(int(input().strip())):
        word = input().strip()
        words[word] = words.get(word, 0) + 1
    print(len(words))
    print(' '.join(str(value) for value in words.values()))

if __name__ == "__main__":
    main()
