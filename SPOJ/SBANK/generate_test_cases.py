"""
Description: Test-Case Generator for Sorting Bank Accounts Problem on SPOJ.
Author: striker
"""

"""[Program Description]
    * The following source-code is a simple test case generator for this specific problem in order to check whether my solution is giving the correct answers or not. Using it is pretty simple and you can follow the instruction given below.
    * How to use the generator:
        * I have created two global variables in my program i.e. FILE_PATH and MAX_ACCNT_NUMBERS.
        * FILE_PATH stores the path of the test-case file which your program will create/write to.
        * MAX_ACCNTS_NUMBERS stores what is the maximum limit of account numbers which you are going to sort so that the random number generator will generate the number below that maximum limit.
        * I have used random number generators to genrate account numbers randomly in order create much better test cases (relatively) for the problem.
        * If you want to change anything, you need to change the above variables i.e (FILE_PATH, MAX_ACCNT_NUMBERS) only and just run the program without any input from yourself and it will create a test case file with .in extension in the directory test-cases/ in your current working directory if that file doesn't exist.
    
    * After generating the test cases, run your program using the following command:
                python3 name_of_file.py < test-cases/test-_case_filename.in (Linux based OS).
"""
import os
from random import randint

FILE_PATH = "test-cases/test-case-3.in"
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
    if not os.path.isfile(FILE_PATH):
        with open(FILE_PATH, 'w') as test_file:
            generate_test_cases(test_file)
    else:
        print('{} file already exist in the specified-path "{}". Use a different file-name.'.format(FILE_PATH.split('/')[1], FILE_PATH))

if __name__ == "__main__":
    main()