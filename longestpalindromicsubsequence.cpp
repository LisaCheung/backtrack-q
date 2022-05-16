//https://leetcode.com/problems/longest-palindromic-subsequence/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.length(),vector<int>(s.length()));
        for(int i = 0; i < s.length(); i++){
            for(int j = 0; j < s.length(); j++){
                int r = s.length() -1 - j; 
                if(s[r] == s[i]){
                    if((i-1) >= 0 && (j-1)>= 0){
                        int max = std::max({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]+ 1}); 
                        dp[i][j] = max; 
                    }
                    else if((i-1)>= 0){
                        if(dp[i-1][j] == 0){
                            dp[i][j] = 1; 
                        }
                        else{
                            dp[i][j] = dp[i-1][j];  
                        }
                        
                    }
                    else if((j-1)>= 0){
                        if(dp[i][j-1] == 0){
                            dp[i][j] = 1;
                        }
                        else{
                            dp[i][j] = dp[i][j-1];  
                        } 
                    }
                    else{
                        dp[i][j] = 1; 
                    }
                }
                else{
                    if((i-1) >= 0 && (j-1)>= 0){
                        int max = std::max({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}); 
                        dp[i][j] = max; 
                    }
                    else if((i-1)>= 0){
                        dp[i][j] = dp[i-1][j];
                    }
                    else if((j-1)>= 0){
                        dp[i][j] = dp[i][j-1];
                    }
                }
            }
        }
        return dp[s.length() -1][s.length() -1]; 
    }
};