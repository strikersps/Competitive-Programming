"""
Problem Statement: https://www.codechef.com/QFUN2020/problems/DGTMAGIC
Author: striker
"""

import math

def compute_number_of_digits(a: int, b: int) -> int:
    if not a:
        return ' '.join(['1' for base in range(2, 21)])
    return ' '.join([str(1 + math.floor(b * math.log(a) / math.log(base))) for base in range(2, 21)])

def main():
    for _ in range(int(input().strip())):
        a, b = map(int, input().strip().split())
        print(compute_number_of_digits(a, b))

if __name__ == "__main__":
    main()
