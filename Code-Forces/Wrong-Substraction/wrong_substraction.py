"""
Problem Statement: https://codeforces.com/problemset/problem/977/A
Author: striker
"""

def update_number(n, k):
    while k:
        last_digit = n % 10
        if not last_digit:
            k -= 1
            n //= 10
            continue
        if last_digit >= k:
            n -= k
            break
        n -= last_digit
        k -= last_digit
    return n

def main():
    n, k = tuple(map(int, input().strip().split()))
    print(update_number(n, k))

if __name__ == "__main__":
    main()
