"""
Problem Statement: https://cses.fi/problemset/task/1094/
Author: striker
"""

def compute_minimum_operations(n, sequence):
    min_operations = 0
    for index in range(1, n):
        if sequence[index - 1] > sequence[index]:
            min_operations += (sequence[index - 1] - sequence[index])
            sequence[index] = sequence[index - 1]
    return min_operations

def main():
    print(f'{compute_minimum_operations(int(input().strip()), list(map(int, input().strip().split())))}')

if __name__ == "__main__":
    main()
