"""
Problem Statement: https://www.codechef.com/LRNDSA03/problems/DPAIRS
Author: striker
"""

INF = 1e10

def compute_distinct_pairs(sequence1, sequence2):
    min_value = INF
    for index, number in enumerate(sequence1):
        if number < min_value:
            min_value = number
            s1_min_index = index
    max_value = -INF
    for index, number in enumerate(sequence2):
        if number > max_value:
            max_value = number
            s2_max_index = index
    for index in range(len(sequence2)):
        print(f"{s1_min_index} {index}")
    for index in range(len(sequence1)):
        if index == s1_min_index:
            continue
        print(f"{index} {s2_max_index}")

def main():
    n, m = tuple(map(int, input().strip().split()))
    sequence1 = list(map(int, input().strip().split()))
    sequence2 = list(map(int, input().strip().split()))
    compute_distinct_pairs(sequence1, sequence2)

if __name__ == "__main__":
    main()
