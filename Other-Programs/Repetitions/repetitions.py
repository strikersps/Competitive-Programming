"""
Problem Statement: https://cses.fi/problemset/task/1069/
Author: striker
"""

def compute_max_substring_len(dna_string):
    substring_len = 1; max_substring_len = 0
    for index in range(1, len(dna_string)):
        if dna_string[index - 1] == dna_string[index]:
            substring_len += 1
            continue
        max_substring_len = max(max_substring_len, substring_len)
        substring_len = 1
    max_substring_len = max(max_substring_len, substring_len)
    return max_substring_len

def main():
    print(f'{compute_max_substring_len(input().strip())}')

if __name__ == "__main__":
    main()
