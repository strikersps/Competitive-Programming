'''
Problem Statement: https://www.hackerrank.com/challenges/maximizing-xor/problem
Author: striker
'''

import math

def main():
    xored = int(input().rstrip()) ^ int(input().rstrip())
    print("{}".format(xored | ((1 << (1 + int(math.log2(xored)))) - 1)))

if __name__ == "__main__":
    main()
