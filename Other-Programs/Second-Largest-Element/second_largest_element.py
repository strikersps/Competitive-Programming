'''
Problem Statement: Refer to the readme.md.
Author: striker
'''

def find_second_largest(sequence):
    max_val = second_max_val = -2**32
    for integer in sequence:
        if max_val < integer:
            second_max_val = max_val
            max_val = integer
        elif max_val != integer and second_max_val < integer:
            second_max_val = integer
    return second_max_val

def main():
    for test in range(int(input().rstrip())):
        n = int(input().rstrip())
        print("{}".format(find_second_largest(list(map(int, input().rstrip().split())))))

if __name__ == "__main__":
    main()
