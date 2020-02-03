'''
Problem Statement: Refer to the readme.md file.
Author: striker
'''

def find_second_smallest(sequence):
    min_val = second_min_val = 2**32
    for integer in sequence:
        if min_val > integer:
            second_min_val = min_val
            min_val = integer
        elif integer != min_val and second_min_val > integer:
            second_min_val = integer
    return second_min_val

def main():
    for test in range(int(input().rstrip())):
        n = int(input().rstrip())
        print("{}".format(find_second_smallest(list(map(int, input().rstrip().split())))))

if __name__ == "__main__":
    main()
