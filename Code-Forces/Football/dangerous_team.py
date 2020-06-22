"""
Problem Statement: https://codeforces.com/problemset/problem/96/A
Author: striker
"""

def main():
    binary_string = input().strip()
    print("YES" if '0000000' in binary_string or '1111111' in binary_string else "NO")

if __name__ == "__main__":
    main()
