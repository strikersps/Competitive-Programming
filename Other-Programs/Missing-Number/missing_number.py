"""
Problem Statement: https://cses.fi/problemset/task/1083/
Author: striker
"""

def main():
    n = int(input().strip())
    print(f'{((n * (n + 1)) // 2) - sum(list(map(int, input().strip().split())))}')

if __name__ == "__main__":
    main()
