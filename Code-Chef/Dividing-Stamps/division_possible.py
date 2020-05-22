"""
Problem Statement: https://www.codechef.com/problems/DIVIDING
Author: striker
"""

def is_division_possible(n : int, sequence : list) -> bool:
    return sum(sequence) == (n * (n + 1)) >> 1

def main():
    print(["NO", "YES"][is_division_possible(int(input().strip()), list(map(int, input().strip().split())))])

if __name__ == "__main__":
    main()
