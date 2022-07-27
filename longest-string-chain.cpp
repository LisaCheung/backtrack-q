//https://leetcode.com/problems/longest-string-chain/
//tle
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), []
    (const std::string& a, const std::string& b){
        return a.size() < b.size();
    }); 
        vector<int> dp(words.size(), 1); 
        int max_res = 1; 
        for(int i = 1; i < words.size(); i++){
            int curr_max = 1; 
            int j = 0; 
            while(j < i){
                bool is_pred = is_predecessor(words[j], words[i]); 
                if(is_pred){
                    if(dp[j]+dp[i] > curr_max){
                        curr_max = dp[j]+dp[i]; 
                    }
                }
                j++; 
            }
            dp[i] = curr_max; 
            if(curr_max > max_res){
                max_res = curr_max; 
            }
        }
        return max_res; 
    }
    bool is_predecessor(string before, string after){
        if(before.length() == after.length() -1){
            string temp; 
            for(int i = 0; i < after.length(); i++){
                temp = after.substr(0, i) + after.substr(i+1, after.length() + 1); 
                if(temp == before){
                    return true; 
                }
            }
        }
        return false; 
    }
};
