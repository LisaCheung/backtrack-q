class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res; 
        backtrack(n, 0, 0, "", res); 
        return res; 
    }
    void backtrack(int n, int num_open, int num_close, string curr, vector<string>& result){
        if(num_open == n && num_close == n) result.push_back(curr); 
        else if(num_open > n || num_close > n) return; 
        if(num_open >= num_close && num_open <= n){
                curr += "("; 
                num_open++; 
                backtrack(n, num_open, num_close, curr, result); 
                num_open--; 
                curr.pop_back(); 
                    
                curr += ")"; 
                num_close++; 
                backtrack(n, num_open, num_close, curr, result); 
                num_close--; 
                curr.pop_back(); 
        }
    }
};