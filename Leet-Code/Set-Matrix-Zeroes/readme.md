# Editorial for [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/solution/)  

**NOTE**: While submitting the code in Leet Code, you don't need to write the whole program, you just need the write the function, so, while referring to the code for this problem, refer to the function `void setZeroes(uint32_t **const matrix,uint32_t matrixSize,uint32_t *matrixColSize)` for the logic which I have implemented.  

The question seems to be pretty simple but the trick here is that we need to modify the given matrix in place i.e. our space complexity needs to `O(1)`.

We will go through two different approaches to the question. The first approach makes use of additional memory while the other one don't.  

**Approach-1:**  
**Intuition**:
If any cell of the matrix has a zero we can record its row and column number. All the cells of this recorded row and column can be marked zero in the next iteration.  

**Algorithm**

*   We make a pass over our original array and look for zero entries.  
*   If we find that an entry at `[i, j]` is 0, then we need to record somewhere the row `i` and column `j`.
So, we use two lists, one for the rows and one for the columns.  
```C  
if(!matrix[i][j]) {
    row_zeroes[i] = true
    column_zeroes[j] = true
}
```

*   Finally, we iterate over the original matrix. For every cell we check if the row `r` or column `c` had been marked earlier. If any of them was marked, we set the value in the cell to `0`.
```C
    for(uint32_t i = 0; i < matrixSize; ++i) {
        for(uint32_t j = 0; j < (*matrixColSize); ++j) {
            if(row_zeroes[i] || col_zeroes[j]) {
                matrix[i][j] = 0;
            }
        }
    }
```  
 The commented part of the code implements this algorithm.  

**Complexity Analysis**

Time Complexity: `O(M×N)`.  
Space Complexity: `O(M+N)`.

where `M` and `N` are the number of rows and columns respectively.  

**As the "Space Complexity is `O(M + N)`", the question arises that, Can we do better?**

**Approach-2**:  From approach-1 we understood that once the `matrix[i][j] = 0`, then no matter what the previous data is there in the row `i` and column `j`, all will be set to `0`.  

So, instead of using an `O(m + n)` space, why don't we use the first row and first column to record all the `0's`.  

And it turns out that, we can actually do it. But you need to take care of the condition, that if there is any `0's` in first row or first column.  

**Algorithm**:  

*   First we need to check whether the first row or first column has zero or not.  
If first row has zero then `zeroth_row` will be marked as `true`.  
If first column has zero then `zeroth_col` will be marked as 'true'. 
I have used a different approach to do that, you can refer to the code in the current repository.  

*   Now, we iterate over the original matrix starting from second row and second column `i.e. matrix[1][1]` onwards. For every cell we check if the row `r` or column `c` had been marked earlier by checking the respective first row cell or first column cell. If any of them was marked, we set the value in the cell to `0`.  
Note the first row and first column serve as the `row_zeroes` and `col_zeroes` that we used in the first approach.  

*   If the `zeroth_row` is set, then make all the member of the zeroth row as `0`.  
*   If the `zeroth_col` is set, then make all the members of the zeroth column as `0`.  

**Complexity**  
Time Complexity : `O(M×N)`.  
Space Complexity : `O(1)`.  
where `M` and `N` are the number of rows and columns respectively.  
