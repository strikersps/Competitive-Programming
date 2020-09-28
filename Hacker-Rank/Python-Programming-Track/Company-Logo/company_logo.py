"""
Problem Statement: https://www.hackerrank.com/challenges/most-commons/problem
Author: striker
"""

from collections import Counter

def main():
    for key, value in sorted(Counter(input().strip()).most_common(), key = lambda x: (-x[1], x[0]))[:3]:
        print(f'{key} {value}')


if __name__ == "__main__":
    main()