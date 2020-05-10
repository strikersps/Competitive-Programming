"""
Problem Statement: https://www.spoj.com/problems/ANARC09A/
Author: striker
"""

def compute_minimum_operations(bracket_string):
    open_count = 0; min_ops = 0
    for bracket in bracket_string:
        if bracket == '{':
            open_count += 1
        elif not open_count:
            open_count += 1; min_ops += 1
        else:
            open_count -= 1
    return min_ops + (open_count >> 1)

def main():
    test_case = 1
    while True:
        bracket_string = input().strip()
        if bracket_string[0] == '-':
            break
        print(f'{test_case}. {compute_minimum_operations(bracket_string)}')
        test_case += 1

if __name__ == "__main__":
    main()
