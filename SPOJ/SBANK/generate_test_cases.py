"""
Description: Test-Case Generator for Sorting Bank Accounts Problem on SPOJ.
Author: striker
"""
import os
from random import randint

TEST_FILE_NAME = "test-case-3.in"
MAX_ACCNT_NUMBERS = 10**5

def generate_test_cases(test_file):
    total_test_cases = randint(1, 5)
    test_file.write(str(total_test_cases) + os.linesep)
    for test_case in range(total_test_cases):
        max_accnts = randint(1, MAX_ACCNT_NUMBERS)
        test_file.write(str(max_accnts) + os.linesep)
        for a in range(max_accnts):
            test_file.write(f'{randint(10, 10**2 - 1)} {randint(10**7, 10**8 - 1)} {randint(10**3, 10**4 - 1)} {randint(10**3, 10**4 - 1)} {randint(10**3, 10**4 - 1)} {randint(10**3, 10**4 - 1)}' + os.linesep)
        if test_case < total_test_cases - 1:
            test_file.write(os.linesep)

def main():
    with open(f"test-cases/{TEST_FILE_NAME}", 'w') as test_file:
        generate_test_cases(test_file)

if __name__ == "__main__":
    main()