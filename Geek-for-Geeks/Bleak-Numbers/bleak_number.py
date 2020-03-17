'''
Problem Statement: https://practice.geeksforgeeks.org/problems/bleak-numbers/0
Author: striker
'''

import math

def compute_set_bit_count(n):
    set_bit_count = 0
    while n:
        n &= (n -1)
        set_bit_count += 1
    return set_bit_count

def main():
    for test in range(int(input().rstrip())):
        n = int(input().rstrip())
        print("{0}".format(["1", "0"][any(n == number + compute_set_bit_count(number) for number in range(n - int((math.log2(n) + 1)), n))]))

if __name__ == "__main__":
    main()
