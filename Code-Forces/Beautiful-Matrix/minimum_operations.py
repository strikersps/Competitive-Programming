"""
Problem Statement: https://codeforces.com/problemset/problem/263/A
Author: striker
"""

MAX_ROWS = 5
MAX_COLS = 5

def main():
    matrix = [list(map(int, input().strip().split())) for row in range(MAX_ROWS)]
    one_loc = tuple()
    for row in range(MAX_ROWS):
        for col in range(MAX_COLS):
            if matrix[row][col]:
                one_loc = (row, col)
    print(f'{abs(2 - one_loc[0]) + abs(2 - one_loc[1])}')

if __name__ == "__main__":
    main()
