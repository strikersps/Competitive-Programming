*   You can refer to the problem statement:
[Unique Paths II](https://leetcode.com/problems/unique-paths-ii/).

*   This probem is based on Dynamic Programming.
*    We have maintained an array `mem` such that `mem[i-1][j-1]` stores the number of unique paths from position `(i,j)` to end point.  
Note that when robot is free to move in right and downward direction,and there are no obstacles, then, `mem[i-1][j-1]` will be sum of `mem[i-1][j]` and `mem[i][j-1]` i.e. sum of paths from the adjoining right block and those from adjoining downward block. But since there might be obstacles on the adjoining right block or bottom block, so, in case `(i,j)` is itself free of obstacle, then,  
`mem[i-1][j-1] = ((1-obstacleGrid[i][j-1])*mem[i][j-1]) + ((1-obstacleGrid[i-1][j])*mem[i-1][j])`.
*   But it isn't necessary that `(i,j)` is itself free of obstacle, so accounting for that, we have, `mem[i-1][j-1] = (1 - obstacleGrid[i-1][j-1])*(((1-obstacleGrid[i][j-1])*mem[i][j-1]) + ((1-obstacleGrid[i-1][j])*mem[i-1][j]))`.
*   However, when he is in rightmost column, he can go only downwards and when in bottommost column, he can only go rightwards. We handle the obstacles in these corner cases as done above.
*   So the problem is solvable by a bottom-up DP with time complexity `O(m*n)`.
