'''
Problem Statement: https://www.spoj.com/problems/ALCATRAZ1/
Author: striker
'''

def main():
    for test in range(int(input().rstrip())):
        number = input().rstrip()
        sum_of_digits = 0
        for digit in number:
            sum_of_digits += ord(digit) - ord('0')
        print(f"{sum_of_digits}")

if __name__ == "__main__":
    main()
