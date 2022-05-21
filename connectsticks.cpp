//https://leetcode.com/problems/minimum-cost-to-connect-sticks/
class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        if(sticks.size() == 1){
            return 0; 
        }
        priority_queue<int, vector<int>, greater<>> q;
        for(auto p: sticks){
            q.push(p); 
        }
        int total_cost = 0; 
        while(!(q.size() == 1)){
            int temp = 0; 
            temp += q.top(); 
            q.pop(); 
            temp += q.top(); 
            q.pop(); 
            q.push(temp); 
            total_cost += temp; 
        }
        return total_cost; 
    }
};