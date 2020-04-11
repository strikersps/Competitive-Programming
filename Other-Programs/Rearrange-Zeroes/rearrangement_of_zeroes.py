'''
Problem Statement: Refer to readme.md file.
Author: striker
'''

def rearrange_zeroes(sequence):
    index = 0
    for data in sequence:
        if data:
            sequence[index] = data
            index += 1
    while index < len(sequence):
        sequence[index] = 0
        index += 1
    return " ".join(map(str, sequence))

def main():
    for test in range(int(input().strip())):
        n = int(input())
        print("{}".format(rearrange_zeroes(list(map(int, input().strip().split())))))

if __name__ == "__main__":
    main()
