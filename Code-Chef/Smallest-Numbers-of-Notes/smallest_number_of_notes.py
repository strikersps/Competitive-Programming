"""
Problem Statement: https://www.codechef.com/problems/FLOW005
Author: striker
"""

def compute_smallest_numbers_of_notes(amount: int) -> int:
    total_notes = 0
    while amount:
        if amount >= 100:
            total_notes += amount // 100
            amount %= 100
        elif amount >= 50:
            total_notes += amount // 50
            amount %= 50
        elif amount >= 10:
            total_notes += amount // 10
            amount %= 10
        elif amount >= 5:
            total_notes += amount // 5
            amount %= 5
        elif amount >= 2:
            total_notes += amount // 2
            amount %= 2
        else:
            total_notes += amount
            break
    return total_notes

def main():
    for _ in range(int(input().strip())):
        print(compute_smallest_numbers_of_notes(int(input().strip())))

if __name__ == "__main__":
    main()