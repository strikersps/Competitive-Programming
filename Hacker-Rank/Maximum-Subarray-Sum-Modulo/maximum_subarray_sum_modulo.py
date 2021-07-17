# Problem Statement: https://www.hackerrank.com/challenges/maximum-subarray-sum/problem
# Author: striker

from bisect import bisect_right, insort

def compute_maximum_subarray_sum_modulo(sequence: list, n: int, m: int) -> int:
    max_mod_sum = pre_mod_sum = 0
    pre_mod_sums = []
    for curr_val in sequence:
        pre_mod_sum = (pre_mod_sum + curr_val) % m
        max_mod_sum = max(max_mod_sum, pre_mod_sum)
        if pre_mod_sums:
            found_index = bisect_right(pre_mod_sums, pre_mod_sum, 0, len(pre_mod_sums))
            if found_index != len(pre_mod_sums):
                max_mod_sum = max(max_mod_sum, (pre_mod_sum - pre_mod_sums[found_index] + m) % m)
        insort(pre_mod_sums, pre_mod_sum)
    return max_mod_sum

def main():
    for _ in range(int(input().strip())):
        n, m = map(int, input().strip().split())
        sequence = list(map(int, input().strip().split()))
        assert n > 0 and m > 0
        print(compute_maximum_subarray_sum_modulo(sequence, n, m))

if __name__ == "__main__":
    main()
