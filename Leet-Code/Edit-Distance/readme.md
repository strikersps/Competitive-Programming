*   You can refer to the problem statement:
[Edit Distance]](https://leetcode.com/problems/edit-distance/).

*   This problem can be solved using Dynamic Programming. In the solution, dp[i][j] denotes minimum number of operations required to convert substring A to substring B where A and B are as follows:
A: substring formed by deleting characters upto index i-1 in word1
B: substring formed by deleting characters upto index j-1 in word2
*   Considering word1, at any index, we can either delete the character present at that index or insert a character or replace it with another character or we can leave it as it is. We will choose the operation that will result in minimum number of operations. Also we will make attempt of making first character of substrings same.
* If we replace character at i in word1 with a character at j then dp[i][j] = 1 + dp[i+1][j+1]
* If we delete character i in word1, we will have to match rest of characters of word1 with substring of word2 i.e, dp[i][j] = 1 + dp[i+1][j]
* If we insert character at i, then dp[i][j] = 1 + dp[i][j+1]
* Taking minimality, we have:
dp[i][j] = min(1 + dp[i][j+1], min(1 + dp[i+1][j], 1+ dp[i+1][j+1]))
* Thought process for corner cases follows from above.
* By bottom up DP, this problem can be solved in O(mn) time complexity where m and n are lengths of word1 and word2 respectively.