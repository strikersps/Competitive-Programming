"""
Problem Statement: https://www.codechef.com/problems/TRISQ
Author: striker
"""

SQUARE_SIDE_LENGTH = 2

def main():
    for test in range(int(input().strip())):
        base_length = int(input().strip())
        base_length_by_side_length = base_length // SQUARE_SIDE_LENGTH
        print(((base_length_by_side_length - 1) * base_length_by_side_length) // 2)

if __name__ == "__main__":
    main()
