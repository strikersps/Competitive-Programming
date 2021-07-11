"""
Problem Statement: https://www.hackerrank.com/contests/hack-the-interview-vi-asia-pacific/challenges/maximum-sum-10-1/problem
Author: striker
"""

from itertools import count, islice

def binary_search(sequence: list, search_data: int, start_index: int, end_index: int) -> bool:
    is_found = False
    while start_index <= end_index:
        mid_index = (end_index - start_index) // 2 + start_index
        if sequence[mid_index] == search_data:
            is_found = True
            break
        elif sequence[mid_index] > search_data:
            end_index = mid_index - 1
        else:
            start_index = mid_index + 1
    return is_found

def main():
    n, m = map(int, input().strip().split())
    sequence = list(islice(count(start = 1), n))
    sequence_sum = sum(sequence)
    for _ in range(m):
        q_val = int(input().strip())
        if q_val == sequence[0] or q_val == sequence[-1] or binary_search(sequence, q_val, 1, n - 2):
            sequence[0], sequence[-1] = sequence[-1], sequence[0]
        else:
            sequence_sum -= sequence.pop()
            sequence.append(q_val)
            sequence_sum += q_val
        print(sequence_sum)

if __name__ == "__main__":
    main()