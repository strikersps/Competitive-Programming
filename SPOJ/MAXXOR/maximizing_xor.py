'''
Problem Statement: https://www.spoj.com/problems/MAXXOR/
Author: striker
'''

import math

def main():
    start_range, end_range = tuple(map(int, input().rstrip().split()))
    xored = start_range ^ end_range
    print("{0}".format(xored | ((1 << (1 + int(math.log2(xored)))) - 1)))

if __name__ == "__main__":
    main()
