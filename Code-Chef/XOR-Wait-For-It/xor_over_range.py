'''
Problem Statement: https://www.codechef.com/problems/XORNEY
Author: striker
'''

def compute_xor(number):
    remainder = (number % 100) % 4
    if not remainder:
        return number
    if 1 == remainder:
        return 1
    if 2 == remainder:
        return number + 1
    if 3 == remainder:
        return 0

def main():
    for test in range(int(input().rstrip())):
        start_range, end_range = tuple(map(int, input().rstrip().split()))
        print("{}".format("Odd" if (compute_xor(end_range) ^ compute_xor(start_range - 1)) & 1 else "Even"))

if __name__ == "__main__":
    main()
