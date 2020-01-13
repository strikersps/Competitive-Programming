/*  Problem Statement: https://www.codechef.com/JAN20B/problems/CHFDORA
 *  Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef unsigned long long ull_t;
typedef long long ll_t;

#define MEMORY_ALLOCATION_FAILED_ERROR(variable, bytes) fprintf(stderr, "Line number: %u: Not able to allocate <%lu> bytes of memory for <%s> variable.\n", __LINE__, (bytes), #variable)
#define CONSTRAINTS_OUT_OF_BOUND_ERROR(variable, constraints) fprintf(stderr, "Line number: %u: Constraints not satisfied for the <%s> variable, i.e. %s.\n", __LINE__, #variable, #constraints)
#define INITIALISE_CONTAINER(container, bytes) memset(container, 0, (bytes));
#define FIND_MAX(a, b) (a) > (b) ? (a) : (b)
#define FIND_MIN(a, b) (a) < (b) ? (a) : (b)

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static ull_t compute_number_of_valid_pairs(int **const, const int, const int);
static void free_memory(int **const, const int);

int main(void) {
    #ifndef ONLINE_JUDGE
        freopen("test-cases/test-case-1.in", "r", stdin);
        freopen("test-cases/test-case-1.out", "w", stdout);
    #endif
    int test;
    scanf("%d", &test);
    if(test < 1 || test > 100) {
        CONSTRAINTS_OUT_OF_BOUND_ERROR(test, 1 <= test <= 100);
        exit(0);
    }
    while(test--) {
        int n, m;
        scanf("%d%d", &n, &m);
        if(n < 1) {
            CONSTRAINTS_OUT_OF_BOUND_ERROR(n, Dimensions of the matrix cannot be -ve);
            exit(0);
        }
        if(m < 1) {
            CONSTRAINTS_OUT_OF_BOUND_ERROR(m, Dimesions of the matrix cannot be -ve);
            exit(0);
        }
        if((n * m) > 100000) {
            CONSTRAINTS_OUT_OF_BOUND_ERROR(n * m, Number of grids int the matrix should not exceed n * m);
            exit(0);
        }
        int **const matrix = calloc(n, sizeof(*matrix));
        if(matrix) {
            for(int i = 0; i < n; ++i) {
                matrix[i] = calloc(m, sizeof(**matrix));
                if(matrix[i]) {
                    for(int j = 0; j < m; ++j) {
                        scanf("%d", &matrix[i][j]);
                        if(matrix[i][j] < 1 ||  matrix[i][j] > 1000000) {
                            CONSTRAINTS_OUT_OF_BOUND_ERROR(matrix[i][j], 1 <= matrix[i][j] <= 10^6);
                            exit(0);
                        }
                    }
                } else {
                    MEMORY_ALLOCATION_FAILED_ERROR(matrix[i], m * sizeof(**matrix));
                    exit(0);
                }
            }
            printf("%llu\n", compute_number_of_valid_pairs(matrix, n, m));
            free_memory(matrix, n);
        } else {
            MEMORY_ALLOCATION_FAILED_ERROR(matrix, n * sizeof(*matrix));
            exit(0);
        }
    }
    return EXIT_SUCCESS;
}

static ull_t compute_number_of_valid_pairs(int **const matrix, const int nrows, const int ncols) {
    ull_t count_valid_pairs = nrows * ncols;
    for(int i = 1; i < (nrows - 1); ++i) {
        for(int j = 1; j < (ncols - 1); ++j) {
            for(int k = 1; ((i - k) >= 0 && (i + k) < nrows) && ((j - k) >= 0 && (j + k) < ncols); ++k) {
                if((matrix[i][j - k] == matrix[i][j + k]) && (matrix[i - k][j] == matrix[i + k][j])) {
                    ++count_valid_pairs;
                } else {
                    break;
                }
            }
        }
    }
    return count_valid_pairs;
}

static void free_memory(int **const matrix, const int nrows) {
    for(int i = 0; i < nrows; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}
