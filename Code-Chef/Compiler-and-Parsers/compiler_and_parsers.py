'''
Problem Statement: https://www.codechef.com/LRNDSA02/problems/COMPILER
Author: striker
'''

def compute_length_of_prefix(expression):
    length_of_longest_prefix = 0
    open_count = 0
    for index, e in enumerate(expression):
        if e == '<':
            open_count += 1
        else:
            open_count -= 1
        if open_count < 0:
            break
        if not open_count:
            length_of_longest_prefix = index + 1
    return length_of_longest_prefix

def main():
    for test in range(int(input().strip())):
        print(f"{compute_length_of_prefix(input().strip())}")

if __name__ == "__main__":
    main()
