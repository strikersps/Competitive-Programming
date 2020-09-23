"""
Problem Statement: https://www.spoj.com/problems/SBANK/
Author: striker
"""

from collections import Counter

def main():
    total_test_cases = int(input().strip())
    for test_case in range(total_test_cases):
        total_data = input().strip()
        total_data = int(total_data) if total_data else int(input().strip())
        for accnt_number, count in sorted(Counter([input().strip() for _ in range(total_data)]).items()):
            print("{} {}".format(accnt_number, count))
        if test_case < total_test_cases - 1:
            print()

if __name__ == "__main__":
    main()
