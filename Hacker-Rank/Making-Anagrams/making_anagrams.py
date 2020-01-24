'''
Problem Statement: https://www.hackerrank.com/challenges/ctci-making-anagrams/problem
Author: striker
'''

from collections import Counter

def main():
    string_a = Counter(input().rstrip())
    string_b = Counter(input().rstrip())
    min_ops = 0
    for ascii_code in range(ord('a'), ord('z') + 1):
        min_ops += abs(string_a[chr(ascii_code)] - string_b[chr(ascii_code)])
    print("{}".format(min_ops))

if __name__ == "__main__":
    main()
