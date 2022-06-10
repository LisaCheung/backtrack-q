//https://leetcode.com/problems/container-with-most-water/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0; 
        int right = height.size() - 1; 
        int curr_max = (right - left)*min(height[left], height[right]); 
        while (left < right){
            int temp_max = (right - left)*std::min(height[left], height[right]); 
            if(temp_max > curr_max) curr_max = temp_max; 
            height[left] > height[right] ? right-- : left++; 
        }
        return curr_max; 
    }
};