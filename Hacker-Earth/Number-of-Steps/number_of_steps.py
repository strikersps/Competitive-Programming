"""
Problem Statement: https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/make-all-equal-90a21ab2/description/?layout=old
Author: striker
"""

def compute_minimum_operations(sequence_a: list, sequence_b: list, sequence_size: int) -> int:
    if sequence_size == 1:
        return 0
    min_sequence_a = min(sequence_a)
    for target in range(min_sequence_a, -1, -1):
        min_operations = 0
        for a_i, b_i in zip(sequence_a, sequence_b):
            if target == a_i:
                continue
            if b_i > 0 and (a_i - target) % b_i == 0:
                min_operations += (a_i - target) // b_i;
                continue
            min_operations = -1
            break
        if min_operations > -1:
            break
    return min_operations


def main():
    sequence_size = int(input().strip())
    sequence_a = list(map(int, input().strip().split()))
    sequence_b = list(map(int, input().strip().split()))
    print(compute_minimum_operations(sequence_a, sequence_b, sequence_size))

if __name__ == "__main__":
    main()