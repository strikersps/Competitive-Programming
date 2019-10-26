/*
    PROBLEM : https://leetcode.com/problems/edit-distance/
    AUTHOR: Rhythm Gupta (https://rhuthmos.github.io/)
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        if (m==0){
            return n;
        }
        else if (n==0){
            return m;
        }
        else{
            int dp[m][n];
        for (int i = m-1; i>=0; i-- ){
            for(int j = n-1; j>=0; j--){
                if (i == m-1){
                    if (j==n-1){
                        if (word1.at(i)==word2.at(j)){
                            dp[i][j] = 0;
                        }
                        else{
                            dp[i][j] = 1;  // replace the ith character
                        }
                    }
                    else{
                        if (word1.at(i)==word2.at(j)){
                            dp[i][j] = n-(j+1);   // insert n-j characters at the end
                        }
                        else{
                            dp[i][j] = min(1 + dp[i][j+1],1 + n-(j+1));  //min(insert, replace one char and then insert the rest) 
                        }
                    }
                }
                else{
                    if (j==n-1){
                        if (word1.at(i)==word2.at(j)){
                            dp[i][j] = m-(i+1); //delete the rest
                        }
                        else{
                            dp[i][j] = min(1 + m-(i+1), 1 + dp[i+1][j]); // min(replace and delete the rest, delete the first and proceed further)
                        }
                    }
                    else{
                        if (word1.at(i)==word2.at(j)){
                            dp[i][j] = dp[i+1][j+1];
                        }
                        else{
                            dp[i][j] = min(1 + dp[i][j+1], min(1 + dp[i+1][j], 1+ dp[i+1][j+1])) ; // min(insert the first, delete the first, replace the first)
                        }
                    }
                }
            }
        }
        
        return dp[0][0];    
        }
        
    }
};