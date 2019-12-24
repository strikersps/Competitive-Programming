'''
Problem Statement: https://www.codechef.com/problems/STONES
Author: striker
'''

def compute_total_jewels_present(jewel_stones, mined_stones):
    jewel_count = 0
    for stone in mined_stones:
        if stone in jewel_stones:
            jewel_count += 1
    return jewel_count

def main():
    for test_case in range(int(input())):
        jewel_stones = input()
        mined_stones = input()
        print(compute_total_jewels_present(jewel_stones, mined_stones))

if __name__ == "__main__":
    main()
