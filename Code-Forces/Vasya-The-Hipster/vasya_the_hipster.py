"""
Problem Statement: https://codeforces.com/problemset/problem/581/A
Author: striker
"""

def main():
    a, b = map(int, input().strip().split())
    min_val = min(a, b)
    max_val = max(a, b)
    print(f'{min_val} {(max_val - min_val) >> 1}')

if __name__ == "__main__":
    main()
