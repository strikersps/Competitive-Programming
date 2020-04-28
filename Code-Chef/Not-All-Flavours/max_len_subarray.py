"""
Problem Statement: https://www.codechef.com/LRNDSA02/problems/NOTALLFL
Author: striker
"""

from collections import defaultdict

def compute_max_subarray_len(cake_flavour, n, k):
    if k > n:
        return n
    subarray_len = 0; max_subarray_len = 0; unique_flavour_count = 0
    freq_map = defaultdict(int)
    start = 0; end = 0
    while start < n:
        while end < n and (freq_map[cake_flavour[end]] or unique_flavour_count < (k - 1)):
            subarray_len += 1
            if not freq_map[cake_flavour[end]]:
                unique_flavour_count += 1
            freq_map[cake_flavour[end]] += 1
            end += 1
        max_subarray_len = max(max_subarray_len, subarray_len)
        freq_map[cake_flavour[start]] -= 1
        if not freq_map[cake_flavour[start]]:
            unique_flavour_count -= 1
        start += 1; subarray_len -= 1
    return max_subarray_len

def main():
    for test in range(int(input().strip())):
        n, k = tuple(map(int, input().strip().split()))
        print(f'{compute_max_subarray_len(list(map(int, input().strip().split())), n, k)}')

if __name__ == "__main__":
    main()
