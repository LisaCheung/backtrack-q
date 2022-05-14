//https://leetcode.com/problems/jump-game-ii/
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),INT_MAX); 
        dp[0] = 0; 
        for(int i = 0; i < nums.size(); i++){
            int temp = nums[i]; 
                for(int j = 0; j < temp; j++){
                if(j+ i+ 1 >= nums.size()){
                    break; 
                }
                if(dp[j + i+ 1] > (dp[i] + 1)){
                    dp[j+ i + 1] = (dp[i]+ 1); 
                    if((j+i + 1) == nums.size() -1){
                        return dp[nums.size() -1]; 
                    }
                }
            }
        }
        return dp[nums.size() -1];  
    }
};