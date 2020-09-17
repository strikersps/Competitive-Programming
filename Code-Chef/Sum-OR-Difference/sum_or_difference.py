"""
Problem Statement: https://www.codechef.com/problems/DIFFSUM
Author: striker
"""

def main():
    n1 = int(input().strip())
    n2 = int(input().strip())
    print(f'{n1 - n2 if n1 > n2 else n1 + n2}')

if __name__ == "__main__":
    main()