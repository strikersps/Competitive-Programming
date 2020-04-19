"""
Problem Statement: https://www.hackerrank.com/challenges/handshake/problem
Author: striker
"""

def main():
    for test in range(int(input().strip())):
        n = int(input().strip())
        print(f"{(n * (n - 1)) >> 1}")

if __name__ == "__main__":
    main()
