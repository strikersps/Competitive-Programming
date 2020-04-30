"""
Problem Statement: https://codeforces.com/problemset/problem/705/A
Author: striker
"""

def main():
    n = int(input().strip())
    str1 = "I hate"; str2 = "I love"
    print(str1, end = '')
    if n > 1:
        for number in range(2, n + 1):
            if not number % 2:
                print(f' that {str2}', end = '')
                continue
            print(f' that {str1}', end = '')
    print(" it")

if __name__ == "__main__":
    main()
