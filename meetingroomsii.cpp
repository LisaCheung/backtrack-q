class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.size() < 2){
            return intervals.size(); 
        }
        sort(intervals.begin(), intervals.end(), [this] (vector<int> a, vector<int> b){return a[0] < b[0];}); 
        priority_queue <int, vector<int>, greater<int> > pq;
        pq.push(intervals[0][1]); 
        int i = 1; 
        while(i < intervals.size()){
            bool is_free = intervals[i][0] >= pq.top(); 
            if(is_free) pq.pop(); 
            pq.push(intervals[i][1]); 
            i++; 
        }
        return pq.size(); 
    }
};