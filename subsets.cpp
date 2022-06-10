//https://leetcode.com/problems/subsets
#include <iostream> 
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr_vec; 
        vector<vector<int>> res; 
        res.push_back({}); 
        vector<int> curr_i; 
        backtrack(nums, curr_vec, res, 0, curr_i); 
        return res; 
    }
    void backtrack(vector<int>& nums, vector<int>& curr_vec, vector<vector<int>>& res, int count, vector<int>& curr_i){
        if(count == nums.size()){
            return; 
        }
        int temp; 
        if(curr_i.empty()){
            temp = 0; 
        }
        else{
            temp = curr_i.at(curr_i.size() -1); 
        }
        for(int i = temp; i < nums.size(); i++){
            bool has_i = (std::find(curr_i.begin(), curr_i.end(), i) != curr_i.end()); 
            if(!has_i){
                curr_vec.push_back(nums.at(i)); 
                res.push_back(curr_vec); 
                curr_i.push_back(i); 
                backtrack(nums, curr_vec, res, count+1, curr_i); 
                curr_i.pop_back(); 
                curr_vec.pop_back(); 
            }            
        }
    }
};