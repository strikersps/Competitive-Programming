"""
Problem Statement: https://cses.fi/problemset/task/1071
Author: striker
"""

def compute_value(row_index: int, col_index: int) -> int:
    go_up = False
    if row_index < col_index:
        go_up = True
        col_index, row_index = row_index, col_index
    diagonal_val = (row_index * row_index) - row_index + 1
    if(row_index == col_index):
        return diagonal_val
    if row_index % 2:
        if go_up:
            diagonal_val += (row_index - col_index)
        else:
            diagonal_val -= (row_index - col_index)
    else:
        if go_up:
            diagonal_val -= (row_index - col_index)
        else:
            diagonal_val += (row_index - col_index)
    return diagonal_val

def main():
    for _ in range(int(input().strip())):
        row_index, col_index = map(int, input().strip().split())
        print(compute_value(row_index, col_index))

if __name__ == "__main__":
    main()
