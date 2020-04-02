'''
Problem Statement: https://www.codechef.com/JUNE19B/problems/KS2/
Author: striker
'''

def main():
    for test in range(int(input().strip())):
        n = input().strip()
        sum_of_digit = sum([ord(digit) - 48 for digit in n])
        print("{0}".format((10 * int(n)) + (0 if not sum_of_digit % 10 else 10 - (sum_of_digit % 10))))

if __name__ == "__main__":
    main()
