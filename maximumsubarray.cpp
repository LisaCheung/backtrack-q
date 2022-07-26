//kadane's alg
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_max = nums[0]; 
        int max_res = nums[0]; 
        for(int i = 1; i < nums.size(); i++){
            curr_max = std::max(nums[i], curr_max + nums[i]); 
            if(curr_max > max_res){
                max_res = curr_max; 
            }
        }
        return max_res; 
    }
};