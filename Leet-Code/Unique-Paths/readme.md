*   You can refer to the problem statement:
[Unique Paths](https://leetcode.com/problems/unique-paths/).

*   This is a simple problem based on dynamic programming. We have maintained an array `mem` such that `mem[i-1][j-1]` stores the number of unique paths from position `(i,j)` to end point. Note that when robot is free to move in right and downward direction, `mem[i-1][j-1]` will be sum of `mem[i-1][j]` and `mem[i][j-1]` that is sum of paths from the adjoining right block and those from adjoining downward block. However, when he is in rightmost column, he can go only downwards and when in bottommost column, he can oly go rightwards.
So the problem is solvable by a bottom-up DP with time complexity `O(m*n)`.
