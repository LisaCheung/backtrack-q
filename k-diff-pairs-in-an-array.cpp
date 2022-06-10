//https://leetcode.com/problems/k-diff-pairs-in-an-array/
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(nums.size() < 2) return 0; 
        map<int,int> hm; 
        set<pair<int,int>> s; 
        int count = 0; 
        for(int x: nums){
            if(hm.find(x) != hm.end()){
                hm[x]++; 
                if(k == 0 && hm[x] == 2) count++; 
            }
            else hm[x] = 1; 
        }
        if(k == 0) return count; 
        for(std::map<int,int>::iterator iter = hm.begin(); iter != hm.end(); ++iter){
            int a =  iter->first, b = a - k; 
            if(hm.find(b) != hm.end()) s.insert(pair(b,a)); 
        }
        return s.size(); 
    }
};