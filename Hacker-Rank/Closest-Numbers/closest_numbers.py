"""
Problem Statement: https://www.hackerrank.com/challenges/closest-numbers/problem
Author: striker
"""

def main():
    n = int(input().strip())
    sequence = list(map(int, input().strip().split()))
    sequence.sort()
    min_diff = 10**9
    for index in range(1, len(sequence)):
        if sequence[index] - sequence[index - 1] < min_diff:
            min_diff = sequence[index] - sequence[index - 1]
    for index in range(len(sequence) - 1):
        if sequence[index + 1] - sequence[index] == min_diff:
            print(f"{sequence[index]} {sequence[index + 1]}", end = " ")

if __name__ == "__main__":
    main()
