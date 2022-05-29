//https://leetcode.com/problems/longest-palindromic-substring/
class Solution {
public:
    int countSubstrings(string s) {
        if(s.length() <= 1) return s.length(); 
        int max_i = 0, max_len = 1, count = 0; 
        for(int i = 0; i < s.length(); i++){
            int left = i, right = i; 
            while(s[left] == s[right]){
                count++,left--,right++; 
                if(left < 0 || right >= s.length()) break; 

            }
            if(i+1 < s.length()){
                if(s[i+1] == s[i]){
                    left = i, right = i+1; 
                    while(s[left] == s[right]){
                        count++, left--, right++; 
                        if(left < 0 || right >= s.length()) break; 
                    }   
                } 
            }
        }
        return count; 
    }
};