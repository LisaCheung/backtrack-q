class Solution {
public:
    bool comp(vector<int> v1, vector<int> v2){
        return v1[0] > v2[0]; 
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() < 2) return intervals; 
        sort(intervals.begin(), intervals.end(), [this] (vector<int> a, vector<int> b)          {return a[0] < b[0]; }); 
        vector<vector<int>> res; 
        int i = 0; 
        while(i < intervals.size()){
            int start_i = intervals[i][0], max_end = intervals[i][1]; 
            while(i+1< intervals.size() && max_end >= intervals[i+1][0]){
                if(max_end <= intervals[i+1][1]) max_end = intervals[i+1][1]; 
                i++; 
            }
            res.push_back({start_i, max_end}); 
            i++; 
        }
        return res; 
    }  
};