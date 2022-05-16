class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        if(not word1 and not word2):
            return 0
        if(not word1):
            return len(word2)
        if(not word2): 
            return len(word1)
        num_rows = len(word2)
        num_cols = len(word1)
        dp = [[0 for c in range(num_cols)] for r in range(num_rows)]
        if(word1[0] == word2[0]):
            dp[0][0] = 0
        else:
            dp[0][0] = 1
        for i in range(1, num_cols):
            if(word1[i] == word2[0]):
                dp[0][i] = i
            else:
                dp[0][i] = dp[0][i-1]+1
        for i in range(1, num_rows):
            if(word2[i] == word1[0]):
                dp[i][0] = i
            else:
                dp[i][0] = dp[i-1][0]+1
        for i in range(1, num_rows):
            for j in range(1, num_cols): 
                if(word2[i] == word1[j]):
                    dp[i][j] = min(dp[i-1][j]+1, min(dp[i][j-1]+1,dp[i-1][j-1]))
                else:
                    dp[i][j] = min(dp[i-1][j]+1, min(dp[i][j-1]+ 1,dp[i-1][j-1]+ 1))
        return dp[len(word2) -1][len(word1) -1]