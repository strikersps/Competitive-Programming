"""
Problem Statement: https://www.hackerrank.com/challenges/diwali-lights/problem
Author: striker
"""

def main():
    for test in range(int(input().strip())):
        n = int(input().strip())
        print(f"{((2**n) - 1) % 10**5}")

if __name__ == "__main__":
    main()
