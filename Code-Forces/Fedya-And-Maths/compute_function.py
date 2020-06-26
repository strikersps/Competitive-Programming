"""
Problem Statement: https://codeforces.com/problemset/problem/456/B
Author: striker
"""

def main():
    print(4 if not int(input().strip()[-2: : ]) % 4 else 0)

if __name__ == "__main__":
    main()
