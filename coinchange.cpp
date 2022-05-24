//https://leetcode.com/problems/coin-change/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount < 1){
            return 0; 
        }
        map<int,int> mp; 
        return dp(coins,amount,mp); 
    }
    int dp(vector<int>& coins,int curr,map<int,int>& mp){
        if(curr == 0){
            return 0; 
        }
        else if(curr < 0){
            return -1; 
        }
        else if(mp.find(curr) != mp.end()){
            return mp[curr]; 
        }
        int m = INT_MAX; 
        for(int c:coins){
            int temp = dp(coins, curr - c, mp);
            if (temp >= 0 && temp < m){
                m = 1 + temp;
            }     
        }
        mp[curr] = (m == INT_MAX) ? -1 : m;
        return mp[curr];
    }
};