/*problem link : https://leetcode.com/problems/unique-paths/
	author : Rhythm Gupta (https://rhuthmos.github.io/)
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        int mem[n][m];

	for (int i = n;i>=1; i--){
		for (int j = m; j>=1; j--){
			if (j==m){
				if (i==n){
					mem[i-1][j-1] = 1;
				}
				else{
					mem[i-1][j-1] = mem[i][j-1]	;
				}
			}
			else{
				if (i==n){
					mem[i-1][j-1] = mem[i-1][j];
				}
				else{
					mem[i-1][j-1] = mem[i][j-1] + mem[i-1][j];
				}
			}
		}
	}
	return mem[0][0];
    }
};