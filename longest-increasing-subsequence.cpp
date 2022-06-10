//https://leetcode.com/problems/longest-increasing-subsequence/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp(nums.size(), 1); 
        for(int i = 0; i < nums.size(); i++){
            int x = nums.at(i), j = 0; 
            while(j < i){
                int y = nums.at(j); 
                if(y < x){
                    if(temp.at(i) < temp.at(j) + 1) temp.at(i) = temp.at(j) + 1; 
                }
                j++; 
            }
        }
        int max_res = temp.at(0); 
        for(auto & p: temp){
            if(p > max_res) max_res = p; 
        }
        return max_res; 
    }
};