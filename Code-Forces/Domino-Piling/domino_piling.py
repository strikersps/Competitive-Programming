"""
Problem Statement: https://codeforces.com/problemset/problem/50/A
Author: striker
"""

def main():
    nrows, ncols = map(int, input().strip().split())
    print((nrows * ncols) // 2)

if __name__ == "__main__":
    main()
