"""
Problem Description: https://www.hackerrank.com/challenges/designer-door-mat/problem
Author: striker
"""

def solve():
    n, m = map(int, input().strip().split())
    count = 1
    middle_reached = False
    for i in range(n):
        if i == n // 2:
            middle_reached = True
            dashes_count = m - 7
            for j in range(dashes_count // 2):
                print("-", end = '')
            print("WELCOME", end = '')
            for j in range(dashes_count // 2):
                print("-", end = '')
        else:
            dashes_count = m - (3 * count)
            for j in range(dashes_count // 2):
                print("-", end = '')
            for k in range(count):
                print(".|.", end = '')
            for j in range(dashes_count // 2):
                print("-", end = '')
        count = count + 2 if not middle_reached else count - 2
        print()

if __name__ == "__main__":
    solve()