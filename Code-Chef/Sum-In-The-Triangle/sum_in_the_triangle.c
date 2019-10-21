/*  Problem Statement: https://www.codechef.com/problems/SUMTRIAN
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<assert.h>

#define MAX_SIZE 100

const uint32_t print_maximum_sum(uint32_t **const grid,uint32_t);
const uint32_t find_maximum(uint32_t,uint32_t);
void free_memory(uint32_t **const,uint32_t);

int main(void) {
    uint16_t test;
    printf("Enter the number of test-cases\n");
    scanf("%"SCNu16, &test);
    assert(test > 0 && test < 1001);
    while(test--) {
        uint32_t grid_size;
        scanf("%"SCNu32, &grid_size);
        assert(grid_size > 0 && grid_size < 101);
        uint32_t **const grid = calloc(grid_size,sizeof(uint32_t*));
        if(grid) {
            for(uint32_t i = 0; i < grid_size; ++i) {
                grid[i] = calloc(grid_size,sizeof(uint32_t));
                for(uint32_t j = 0; j <= i; ++j) {
                    scanf("%"SCNu32, &grid[i][j]);
                    assert(grid[i][j] >= 0 && grid[i][j] < 100);
                }
            }
            if(grid_size == 1) {
                printf("%"PRIu32"\n", grid[0][0]);
            } else {
                printf("%"PRIu32"\n", print_maximum_sum(grid,grid_size));
            }
            free_memory(grid,grid_size);
        } else {
            fprintf(stderr,"Memory not allocated to **grid pointer!\n");
        }
    }
    return EXIT_SUCCESS;
}

const uint32_t print_maximum_sum(uint32_t **const grid,uint32_t n) {
    for(uint32_t i = 1; i < n; ++i) {
        for(uint32_t j = 0; j <= i; ++j) {
            if(j == 0) {
                grid[i][j] += grid[i - 1][j];
            } else if(j == i) {
                grid[i][j] += grid[i - 1][j - 1];
            } else {
                grid[i][j] += find_maximum(grid[i - 1][j],grid[i - 1][j - 1]);
            }
        }
    }
    uint32_t max_cost = 0;
    for(uint32_t i = 0; i < n; ++i) {
        if(max_cost < grid[n - 1][i]) {
            max_cost = grid[n - 1][i];
        }
    }
    return max_cost;
}

const uint32_t find_maximum(uint32_t a,uint32_t b) {
    return (a > b ? a : b);
}

void free_memory(uint32_t **const grid,uint32_t grid_size) {
    for(uint32_t i = 0; i < grid_size; ++i) {
        free(grid[i]);
    }
    free(grid);
}