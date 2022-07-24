class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int valley = prices[0]; 
        int peak = prices[0]; 
        int i = 0; 
        int max_profit = 0; 
        while((i+1)< prices.size()){
            while((i+1) < prices.size() && prices[i] >= prices[i+1]){
                i++; 
            }
            valley = prices[i]; 
            while((i+1) < prices.size() && prices[i] < prices[i+1]){
                i++; 
            }
            peak = prices[i]; 
            max_profit += peak - valley; 
        }
        return max_profit;    
    }
};