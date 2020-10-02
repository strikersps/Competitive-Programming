"""
Problem Statement: https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem
Author: striker
"""

from collections import Counter

def check_validity(data_string: str) -> bool:
    freq_map = sorted(Counter(data_string).values())
    unique_numbers = len(set(freq_map))
    if unique_numbers > 2:
        return False
    if unique_numbers == 2:
        min_val, max_val = freq_map[0], freq_map[-1]
        count_max_val = freq_map.count(max_val)
        if (count_max_val == len(freq_map) - 1 and min_val == 1) or (count_max_val == 1 and max_val - min_val == 1):
            return True
        return False
    return True

def main():
    print("YES" if check_validity(input().strip()) else "NO")

if __name__ == "__main__":
    main()
