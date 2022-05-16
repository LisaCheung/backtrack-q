class Solution {
    public int minDistance(String word1, String word2) {
        if(word1.isEmpty() && word2.isEmpty()){
            return 0; 
        }
        else if(word1.isEmpty()){
            return word2.length(); 
        }
        else if(word2.isEmpty()){
            return word1.length(); 
        }
        int numRows = word2.length(); 
        int numCols = word1.length(); 
        int[][] dp = new int[numRows][numCols]; 
        if(word1.charAt(0) == word2.charAt(0)){
            dp[0][0] = 0; 
        }
        else{
            dp[0][0] = 1; 
        }
        for(int i = 1; i < numCols; i++){
            if(word1.charAt(i) == word2.charAt(0)){
                dp[0][i] = i; 
            }
            else{
                dp[0][i] = dp[0][i-1]+1; 
            }
        }
        for(int i = 1; i < numRows; i++){
            if(word2.charAt(i) == word1.charAt(0)){
                dp[i][0] = i; 
            }
            else{
                dp[i][0] = dp[i-1][0]+1; 
            }
        }
        for(int i = 1; i < numRows; i++){
            for(int j = 1; j < numCols; j++){
                if(word2.charAt(i) == word1.charAt(j)){
                    dp[i][j] = Math.min(dp[i-1][j]+1, Math.min(dp[i][j-1]+1,dp[i-1][j-1])); 
                }
                else{
                    dp[i][j] =  Math.min(dp[i-1][j]+1, Math.min(dp[i][j-1]+1,dp[i-1][j-1]+ 1)); 
                }
            }
        }
        return dp[word2.length() -1][word1.length() -1];
    }
}