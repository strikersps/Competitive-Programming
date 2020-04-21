"""
Problem Statement: https://leetcode.com/problems/valid-mountain-array/
Author: striker
"""

def check_mountain_array(n, sequence):
    if n < 3:
        return False
    left_end = 0; right_end = n - 1
    while left_end < n - 1 and sequence[left_end] < sequence[left_end + 1]:
        left_end += 1
    while right_end > 0 and sequence[right_end] < sequence[right_end - 1]:
        right_end -= 1
    return False if left_end == n - 1 or right_end == 0 or left_end != right_end else True

def main():
    for test in range(int(input().strip())):
        print(f"{'true' if check_mountain_array(int(input().strip()), list(map(int, input().strip().split()))) else 'false'}")

if __name__ == "__main__":
    main()
