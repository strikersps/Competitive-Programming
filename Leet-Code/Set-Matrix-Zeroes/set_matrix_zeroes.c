/*  Problem Statement: https://leetcode.com/problems/set-matrix-zeroes/
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>
#include<assert.h>

void setZeroes(uint32_t **const,uint32_t,uint32_t*);
void displayMatrix(uint32_t **const,uint32_t,uint32_t);
void freeMemory(uint32_t **const,uint32_t,uint32_t);

int main(void) {
    uint32_t n,m;
    scanf("%"SCNu32"%"SCNu32, &n,&m);
    assert((n > 0) && (m > 0));
    uint32_t **const matrix = calloc(n,sizeof(uint32_t*));
    if(matrix) {
        for(uint32_t i = 0; i < n; ++i) {
            matrix[i] = calloc(m,sizeof(uint32_t));
            if(matrix[i]) {
                for(uint32_t j = 0; j < m; ++j) {
                    scanf("%"SCNu32, &matrix[i][j]);
                }
            }
        }
        setZeroes(matrix,n,&m);
        displayMatrix(matrix,n,m);
        freeMemory(matrix,m,n);
    } else {
        fprintf(stderr,"Not able to allocated %lu bytes of memory\n", n * sizeof(uint32_t*));
    }
    return EXIT_SUCCESS;
}

// This approach have a space-complexity of O(n + m).
/*
void setZeroes(uint32_t **const matrix,uint32_t matrixSize,uint32_t *matrixColSize) {
    bool row_zeroes[matrixSize],col_zeroes[*matrixColSize];
    memset(row_zeroes,false,(sizeof(bool) * matrixSize));
    memset(col_zeroes,false,(sizeof(bool) * (*matrixColSize)));
    for(uint32_t i = 0; i < matrixSize; ++i) {
        for(uint32_t j = 0; j < (*matrixColSize); ++j) {
            if(!matrix[i][j]) {
                row_zeroes[i] = true;
                col_zeroes[j] = true;
            }
        }
    }
    for(uint32_t i = 0; i < matrixSize; ++i) {
        for(uint32_t j = 0; j < (*matrixColSize); ++j) {
            if(row_zeroes[i] || col_zeroes[j]) {
                matrix[i][j] = 0;
            }
        }
    }
}
*/

void setZeroes(uint32_t **const matrix,uint32_t matrixSize,uint32_t *matrixColSize) {
    bool zeroth_row,zeroth_col;
    zeroth_row = zeroth_col = false;
    for(uint32_t i = 0; i < matrixSize; ++i) {
        for(uint32_t j = 0; j < (*matrixColSize); ++j) {
            if(j == 0 && !matrix[i][0] && !zeroth_col) {
                zeroth_col = true;
            }
            if(i == 0 && !matrix[0][j] && !zeroth_row) {
                zeroth_row = true;
                break;
            }
            else {
                if(!matrix[i][j]) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
    }
    for(uint32_t i = 1; i < matrixSize; ++i) {
        for(uint32_t j = 1; j < (*matrixColSize); ++j) {
            if(!matrix[0][j] || !matrix[i][0]) {
                matrix[i][j] = 0;
            }
        }
    }
    if(zeroth_col) {
        for(uint32_t i = 0; i < matrixSize; ++i) {
            matrix[i][0] = 0;
        }
    }
    if(zeroth_row) {
        for(uint32_t i = 0; i < (*matrixColSize); ++i) {
            matrix[0][i] = 0;
        }
    }
}

void displayMatrix(uint32_t **const matrix,uint32_t n,uint32_t m) {
    for(uint32_t i = 0; i < n; ++i) {
        for(uint32_t j = 0; j < m; ++j) {
            printf("%"PRIu32" ", matrix[i][j]);
        }
        printf("\n");
    }
}

void freeMemory(uint32_t **const matrix,uint32_t n,uint32_t m) {
    for(uint32_t i = 0; i < n; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}