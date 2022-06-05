//https://leetcode.com/problems/3sum-closest/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = nums[0] + nums[1] + nums[2]; 
        sort(nums.begin(), nums.end()); 
        int left, right; 
        for(int i = 0; i < nums.size() - 2; i++){
            if(!(i-1 >= 0 && nums[i-1] == nums[i])){
                left = i+1, right = nums.size() -1; 
                while(left < right){
                    int sum = nums[i] + nums[left] + nums[right]; 
                    if(abs(closest - target) > abs(sum - target)) closest = sum; 
                    if(sum < target) left++; 
                    else if(sum > target) right--; 
                    else return target;   
                }    
            }
        }
        return closest; 
    }
};