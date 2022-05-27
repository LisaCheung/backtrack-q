//https://leetcode.com/problems/longest-palindromic-substring/
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()||s.length() <= 1) return s; 
        int max_i = 0; 
        int max_len = 1; 
        for(int i = 0; i < s.length(); i++){
            int left = i; 
            int right = i; 
            while(s[left] == s[right]){
                if(right -left +1 > max_len){
                    max_len = right -left+1; 
                    max_i = left; 
                }
                left--; 
                right++; 
                if(left < 0 || right >= s.length()) break; 

            }
            if(i+1 < s.length()){
                if(s[i+1] == s[i]){
                    left = i; 
                    right = i+1; 
                    while(s[left] == s[right]){
                        if(right -left +1 > max_len){
                            max_len = right -left+1; 
                            max_i = left; 
                        }
                        left--; 
                        right++; 
                        if(left < 0 || right >= s.length()) break; 
                    }   
                } 
            }
        }
        return s.substr(max_i, max_len); 
    }
};