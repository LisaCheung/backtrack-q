//https://leetcode.com/problems/jump-game/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size(), false); 
        dp[0] = true; 
        int max_jump = 0; 
        for(int i = 0; i < nums.size(); i++){
            int curr_jump = i + nums[i]; 
            if(dp[i] == true){
                if(curr_jump >= nums.size() -1) return true; 
                if(curr_jump > max_jump){
                   for(int j = max_jump; j <= curr_jump; j++) dp[j] = true; 
                    max_jump = curr_jump; 
                }
                else for(int q = i; q <= curr_jump; q++) dp[q] =true; 
            }  
        }
        return false; 
    }
};
