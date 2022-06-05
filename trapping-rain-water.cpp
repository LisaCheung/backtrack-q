//https://leetcode.com/problems/trapping-rain-water/
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left(height.size(), height[0]); 
        vector<int> right(height.size(), height[height.size() -1]); 
        int res = 0; 
        for(int i = 1; i < height.size(); i++){
            height[i] > left[i-1] ? left[i] = height[i] : left[i] = left[i-1]; 
        }
        for(int i = height.size() -2; i >= 0; i--){
            height[i] > right[i+1] ? right[i] = height[i]: right[i] = right[i+1]; 
        }
        for(int i = 0; i < height.size(); i++){
            res += std::min(left[i], right[i]) - height[i]; 
        }
        return res; 
    }
};