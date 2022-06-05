//https://leetcode.com/problems/3sum/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res; 
        if(nums.empty() || nums.size() < 3) return res; 
        sort(nums.begin(), nums.end()); 
        int target = 0; 
        int left, right; 
        for(int i = 0; i < nums.size() - 2; i++){
            if(!(i-1 >= 0 && nums[i-1] == nums[i])){
                left = i+1, right = nums.size() -1; 
                while(left < right){
                    int sum = nums[i] + nums[left] + nums[right]; 
                    if(sum < target) left++; 
                    else if(sum > target) right--; 
                    else{
                        res.push_back({nums[i], nums[left], nums[right]}); 
                        while(left < right && nums[left] == nums[left+1]) left++;
                        while(left < right && nums[right] == nums[right-1]) right--; 
                        left++, right--;    
                    }   
                }    
            }
        }
        return res; 
    }
};