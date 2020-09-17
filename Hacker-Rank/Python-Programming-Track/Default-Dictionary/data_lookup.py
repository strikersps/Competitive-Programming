"""
Problem Statement: https://www.hackerrank.com/challenges/defaultdict-tutorial/problem
Author: striker
"""

from collections import defaultdict

def main():
    n, m = map(int, input().strip().split())
    words_in_grp_A = defaultdict(list)
    for index in range(1, n + 1):
        words_in_grp_A[input().strip()].append(str(index))
    words_in_grp_B = [input().strip() for _ in range(m)]
    for word in words_in_grp_B:
        if word not in words_in_grp_A.keys():
            words_in_grp_A[word].append(str(-1))
        print(" ".join(words_in_grp_A[word]))

if __name__ == "__main__":
    main()