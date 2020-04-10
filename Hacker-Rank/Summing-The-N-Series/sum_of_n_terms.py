'''
Problem Statement: https://www.hackerrank.com/challenges/summing-the-n-series/problem
Author: striker
'''

MOD = 10**9 + 7

def main():
    for test in range(int(input().strip())):
        print(f"{int(input().strip())**2 % MOD}")

if __name__ == "__main__":
    main()
