"""
Problem Statement: https://www.codechef.com/problems/DECINC
Author: striker
"""

def main():
    n = int(input().strip())
    last_two_digits = n % 100
    print(f"{n + 1}" if not last_two_digits % 4 else f"{n - 1}")

if __name__ == "__main__":
    main()
