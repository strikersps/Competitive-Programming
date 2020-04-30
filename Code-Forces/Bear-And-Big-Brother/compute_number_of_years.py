"""
Problem Statement: https://codeforces.com/problemset/problem/791/A
Author: striker
"""

from math import log2

def main():
    a, b = tuple(map(int, input().strip().split()))
    print(f'{int(1 + ((log2(b) - log2(a)) // (log2(3) - 1)))}')

if __name__ == "__main__":
    main()
