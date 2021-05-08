"""
Problem Statement: Compute the gcd of the given sequence S.
Author: striker
"""

from functools import reduce
from itertools import accumulate

def compute_gcd(a: int, b: int) -> int:
    return a if not b else compute_gcd(b, a % b)

def main():
    for _ in range(int(input().strip())):
        sequence = list(map(int, input().strip().split()))
        print(reduce(compute_gcd, sequence))

if __name__ == "__main__":
    main()
