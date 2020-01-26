'''
Problem Statement: https://www.hackerrank.com/contests/projecteuler/challenges/euler025/problem
Author: striker
'''

import math

GOLDEN_RATIO = 1.61803398875

def main():
    for test in range(int(input().rstrip())):
        n = int(input().rstrip())
        print("{}".format(int(math.ceil((n - 1 + (math.log10(5) * 0.5)) / math.log10(GOLDEN_RATIO)))))

if __name__ == "__main__":
    main()
