//https://leetcode.com/problems/search-in-rotated-sorted-array/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int result = binary_search(nums,target, 0,(int) nums.size() - 1);
        return result; 
    }
    int binary_search(vector<int> nums, int target, int left, int right){
        int median = left + (right - left)/2; 
        if(nums[median] ==target){
            return median; 
        }
        if(nums[left] ==target){
            return left; 
        }
        if(nums[right] ==target){
            return right; 
        }
        bool temp1=(target > nums[left] && target < nums[median] && nums[left] < nums[median]); 
        bool temp2=(target < nums[left])&&(target < nums[median] && nums[left] > nums[median]) ;
        bool temp3=(target > nums[right])&&(target > nums[left] && nums[left] > nums[median]); 
        bool temp4=(target > nums[median] && target < nums[right] && nums[median] < nums[right]); 
        bool temp5= (target < nums[left])&&(target < nums[right] && nums[median] > nums[right]);
        bool temp6=(target > nums[right])&& (target > nums[median] && nums[median] > nums[right]); 
        if(temp1|| temp2|| temp3){
            return binary_search(nums, target, left, median - 1); 
        }
        else if(temp4|| temp5|| temp6){
             return binary_search(nums, target, median + 1, right); 
        }
        return -1;    
    }
};