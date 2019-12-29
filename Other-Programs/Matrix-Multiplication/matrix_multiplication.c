/*  Problem Statement: Program to compute matrix-multiplication of two matrices of different dimensions.
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>

typedef unsigned long long ull_t;
typedef long long ll_t;

#define MEMORY_ALLOCATION_FAILED_ERROR(variable, bytes) fprintf(stderr, "Line number: %u: Not able to allocate <%lu> bytes of memory to <%s> variable.\n", __LINE__, (bytes), #variable)

#define CONSTRAINTS_NOT_SATISFIED(variable, constraints) fprintf(stderr, "Line number: %u: Constraints not satisfied for the <%s>, i.e. %s\n", __LINE__, #variable, constraints)

static int** take_input_matrix(const size_t, const size_t);
static void display_matrix(int* *const, const size_t, const size_t);
static int** matrix_multiplication(int* *const, const size_t, const size_t, int* *const, const size_t);
static void free_memory(int* *const, const size_t);

int main(void) {
    int matrix_A_rows, matrix_A_cols, matrix_B_rows ,matrix_B_cols; // Dimensions of the matrix
    scanf("%d%d", &matrix_A_rows, &matrix_A_cols);
    if(matrix_A_rows < 1 || matrix_A_cols < 1) {
        CONSTRAINTS_NOT_SATISFIED(matrix_A, "Dimensions of matrix cannot be -ve");
        exit(0);
    }
    int* *const matrix_A = take_input_matrix(matrix_A_rows, matrix_A_cols);
    if(!matrix_A) {
        MEMORY_ALLOCATION_FAILED_ERROR(matrix_A, matrix_A_rows * matrix_A_cols * sizeof(**matrix_A));
        exit(0);
    }
    scanf("%d%d", &matrix_B_rows, &matrix_B_cols);
    if(matrix_B_rows < 1 || matrix_B_cols < 1) {
        CONSTRAINTS_NOT_SATISFIED(matrix_B, "Dimensions of matrix cannot be -ve");
        exit(0);
    }
    int* *const matrix_B = take_input_matrix(matrix_B_rows, matrix_B_cols);
    if(!matrix_B) {
        MEMORY_ALLOCATION_FAILED_ERROR(matrix_B, matrix_B_rows * matrix_B_cols * sizeof(**matrix_B));
        exit(0);
    }
    printf("Matrix-A:\n");
    display_matrix(matrix_A, matrix_A_rows, matrix_A_cols);
    printf("Matrix-B:\n");
    display_matrix(matrix_B, matrix_B_rows, matrix_B_cols);
    if(matrix_A_cols == matrix_B_rows) {
        int* *const result_matrix = matrix_multiplication(matrix_A, matrix_A_rows, matrix_A_cols, matrix_B, matrix_B_cols);
        if(!result_matrix) {
            MEMORY_ALLOCATION_FAILED_ERROR(result_matrix, matrix_A_rows * matrix_B_cols * sizeof(**result_matrix));
            exit(0);
        }
        printf("Result-Matrix:\n");
        display_matrix(result_matrix, matrix_A_rows, matrix_B_cols);
        free_memory(matrix_A, matrix_A_rows);
        free_memory(matrix_B, matrix_B_rows);
        free_memory(result_matrix, matrix_A_rows);
    } else {
        fprintf(stderr, "Line number: %u: Matrix multiplication cannot be performed beacause matrix_A_cols != matrix_B_rows.\n", __LINE__);
        exit(0);
    }
    return EXIT_SUCCESS;
}

static int** take_input_matrix(const size_t nrows, const size_t ncols) {
    int* *const matrix = calloc(nrows, sizeof(*matrix));
    if(matrix) {
        for(unsigned int i = 0; i < nrows; ++i) {
            matrix[i] = calloc(ncols, sizeof(**matrix));
            if(matrix[i]) {
                for(unsigned int j = 0; j < ncols; ++j) {
                    scanf("%d", &matrix[i][j]);
                }
            } else {
                MEMORY_ALLOCATION_FAILED_ERROR(matrix[i], ncols * sizeof(**matrix));
                return NULL;
            }
        }
    }
    return matrix;
}

static void display_matrix(int* *const matrix, const size_t nrows, const size_t ncols) {
    for(unsigned int i = 0; i < nrows; ++i) {
        for(unsigned int j = 0; j < ncols; ++j) {
            printf("%5d", matrix[i][j]);
        }
        printf("\n");
    }
}

static int** matrix_multiplication(int* *const matrix_A, const size_t matrix_A_rows, const size_t matrix_A_cols, int* *const matrix_B, const size_t matrix_B_cols) {
    int* *const result_matrix = calloc(matrix_A_rows, sizeof(*result_matrix));
    if(result_matrix) {
        for(unsigned int i = 0; i < matrix_A_rows; ++i) {
            result_matrix[i] = calloc(matrix_B_cols, sizeof(**result_matrix));
            if(!result_matrix[i]) {
                MEMORY_ALLOCATION_FAILED_ERROR(result_matrix[i], matrix_B_cols * sizeof(**result_matrix));
                return NULL;
            }
        }

        for(unsigned int i = 0; i < matrix_A_rows; ++i) {
            for(unsigned int j = 0; j < matrix_B_cols; ++j) {
                for(unsigned int k = 0; k < matrix_A_cols; ++k) {
                    result_matrix[i][j] += (matrix_A[i][k] * matrix_B[k][j]);
                }
            }
        }
    }
    return result_matrix;
}

static void free_memory(int* *const matrix, const size_t nrows) {
    for(unsigned int i = 0; i < nrows; free(matrix[i]), ++i);
    free(matrix);
}
