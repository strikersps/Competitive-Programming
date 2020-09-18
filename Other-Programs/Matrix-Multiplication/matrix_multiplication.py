"""
Problem Statement: Refer to the readme.md file.
Author: striker
"""

def display_matrix(matrix: list) -> None:
    for row in matrix:
        for data in row:
            print(f'{data: >5}', end = ' ')
        print()

def compute_matrix_multiplication(matrixA: list, matrixB: list, n: int, m: int) -> list:
    result_matrix = [[0] * m for _ in range(n)]
    for row_index in range(n):
        for col_index in range(m):
            for k in range(len(matrixB)):
                result_matrix[row_index][col_index] += (matrixA[row_index][k] * matrixB[k][col_index])
    return result_matrix

def main():
    matrixA_rows, matrixA_cols = map(int, input().strip().split())
    matrixA = [list(map(int, input().strip().split())) for row in range(matrixA_rows)]
    print("Matrix-A:")
    display_matrix(matrixA)
    matrixB_rows, matrixB_cols = map(int, input().strip().split())
    matrixB = [list(map(int, input().strip().split())) for row in range(matrixB_rows)]
    print("Matrix-B:")
    display_matrix(matrixB)
    try:
        assert(matrixA_rows == matrixB_cols) # Matrix Multiplication can only be performed if number of rows in matrix-A == number of cols in matrix-B.
        print("Result-Matrix:")
        display_matrix(compute_matrix_multiplication(matrixA, matrixB, matrixA_rows, matrixB_cols))
    except AssertionError:
        print("Basic Condition of Matrix-Multiplication is not Satisfied."
        "\ni.e. Matrix Multiplication can only be perfomed if Number of rows in matrix-A == Number of cols in matrix-B.")

if __name__ == "__main__":
    main()