'''
Problem Statement: https://practice.geeksforgeeks.org/problems/rotate-array-by-n-elements/0
Author: striker
'''

def main():
    for test in range(int(input().rstrip())):
        n, d = tuple(map(int, input().rstrip().split()))
        sequence = list(map(int, input().rstrip().split()))
        rotated_list = sequence.copy()
        for index, integer in enumerate(sequence):
            rotated_list[index - d] = integer
        print("{}".format(" ".join(list(map(str, rotated_list)))))


if __name__ == "__main__":
    main()
