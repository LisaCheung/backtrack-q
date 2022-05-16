class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.empty() && word2.empty()){
            return 0; 
        }
        else if(word1.empty()){
            return word2.length(); 
        }
        else if(word2.empty()){
            return word1.length(); 
        }
        vector<vector<int>> dp(word2.length(),vector<int>(word1.length()));
        int num_rows = word2.length(); 
        int num_cols = word1.length(); 
        if(word1[0] == word2[0]){
            dp[0][0] = 0; 
        }
        else{
            dp[0][0] = 1; 
        }
        for(int i = 1; i < num_cols; i++){
            if(word1[i] == word2[0]){
                dp[0][i] = i; 
            }
            else{
                dp[0][i] = dp[0][i-1]+1; 
            }
        }
        for(int i = 1; i < num_rows; i++){
            if(word2[i] == word1[0]){
                dp[i][0] = i; 
            }
            else{
                dp[i][0] = dp[i-1][0]+1; 
            }
        }
        for(int i = 1; i < num_rows; i++){
            for(int j = 1; j < num_cols; j++){
                if(word2[i] == word1[j]){
                    int min = std::min({dp[i-1][j]+1, dp[i][j-1]+1,dp[i-1][j-1]}); 
                    dp[i][j] = min; 
                }
                else{
                    int min = std::min({dp[i-1][j]+ 1, dp[i][j-1]+ 1,dp[i-1][j-1]+ 1}); 
                    dp[i][j] = min; 
                }
            }
        }
        return dp[word2.length() -1][word1.length() -1]; 
    }
};