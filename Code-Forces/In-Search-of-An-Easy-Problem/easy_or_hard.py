"""
Problem Statement: https://codeforces.com/problemset/problem/1030/A
Author: striker
"""

def main():
    n = int(input().strip())
    opinion = list(map(int, input().strip().split()))
    print(f'{"HARD" if any(opinion) else "EASY"}')

if __name__ == "__main__":
    main()
