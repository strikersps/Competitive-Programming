"""
Problem Statement: https://leetcode.com/explore/featured/card/top-interview-questions-easy/92/array/727/
Author: striker
"""

def remove_duplicates(sequence : list()) -> int:
    index = 0; i = 1
    while i < len(sequence):
        if sequence[index] != sequence[i]:
            index += 1
            sequence[index] = sequence[i]
        i += 1
    return 1 + index

def main():
    for test in range(int(input().strip())):
        n = int(input().strip())
        sequence = list(map(int, input().strip().split()))
        for index in range(remove_duplicates(sequence)):
            print(sequence[index], end = ' ')
        print()

if __name__ == "__main__":
    main()
