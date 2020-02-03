'''
Problem Statement: Refer to the readme.md file.
Author: striker
'''

def find_missing_complimentary_number(sequence):
    count_negatives = 0
    for integer in sequence:
        if integer < 0:
            count_negatives += 1
    return sum(sequence) // (len(sequence) - (count_negatives << 1))

def main():
    for test in range(int(input().rstrip())):
        n = int(input().rstrip())
        print("{}".format(find_missing_complimentary_number(list(map(int, input().rstrip().split())))))

if __name__ == "__main__":
    main()
