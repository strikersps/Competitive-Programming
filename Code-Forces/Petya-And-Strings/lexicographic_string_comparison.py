"""
Problem Statement: https://codeforces.com/problemset/problem/112/A
Author: striker
"""

def main():
    string1 = input().strip().lower()
    string2 = input().strip().lower()
    print(1 if string1 > string2 else -1 if string1 < string2 else 0)

if __name__ == "__main__":
    main()
