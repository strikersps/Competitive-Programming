/*
PROBLEM : https://leetcode.com/problems/unique-paths-ii/
AUTHOR: Rhythm Gupta (https://rhuthmos.github.io/)
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        long mem[n][m];

        for (int i = n;i>=1; i--){
            for (int j = m; j>=1; j--){
                if (j==m){
                    if (i==n){
                        if (obstacleGrid[n-1][m-1] == 1){
                            mem[i-1][j-1] = 0;
                        }
                        else{
                            mem[i-1][j-1] = 1;
                        }
                    }
                    else{
                        mem[i-1][j-1] = (1-obstacleGrid[i-1][j-1])*(1 - obstacleGrid[i][j-1])*(mem[i][j-1]);
                    }
                }
                else{
                    if (i==n){
                        
                         mem[i-1][j-1] = (1-obstacleGrid[i-1][j-1])*(1 - obstacleGrid[i-1][j])*(mem[i-1][j]);
                    }
                    else{
                        mem[i-1][j-1] = (1 - obstacleGrid[i-1][j-1])*(((1-obstacleGrid[i][j-1])*mem[i][j-1]) + ((1-obstacleGrid[i-1][j])*mem[i-1][j]));
                    }
                }
            }
        }
        return mem[0][0];
    }
};