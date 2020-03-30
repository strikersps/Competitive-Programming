'''
Problem Statement: https://www.codechef.com/LRNDSA01/problems/FCTRL
Author: striker
'''

def compute_trailing_zeroes(n):
    count_trailing_zeroes = 0
    i = 5
    while n // i >= 1:
        count_trailing_zeroes += (n // i)
        i *= 5
    return count_trailing_zeroes

def main():
    for test in range(int(input().strip())):
        print("{0}".format(compute_trailing_zeroes(int(input().strip()))))

if __name__ == "__main__":
    main()
