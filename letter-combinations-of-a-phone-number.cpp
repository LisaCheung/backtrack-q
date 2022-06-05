//https://leetcode.com/problems/letter-combinations-of-a-phone-number/
class Solution {
    public:
        vector<string> letterCombinations(string digits) {
            if(digits == ""){
                return vector<string>(); 
            }
            unordered_map<string, string> hm = {
                {"2","abc"},
                {"3","def"},
                {"4","ghi"},
                {"5","jkl"},
                {"6","mno"},
                {"7","pqrs"},
                {"8","tuv"},
                {"9","wxyz"},
            };
            vector<string> to_letters; 
            to_letters.reserve(digits.length()); 
            vector<string> result; 
            for(char c: digits){
                string s = ""; 
                s.push_back(c); 
                to_letters.push_back(hm[s]);
            }
            backtrack(to_letters, 0, "", result); 
            return result; 
        }
        void backtrack(vector<string> arr, int letters_index,string res, vector<string>& result){
            if(letters_index == arr.size()){
                result.push_back(res); 
                return; 
            }
            for(int i = 0; i < arr[letters_index].length(); i++){
                res += arr[letters_index][i]; 
                backtrack(arr, letters_index + 1, res, result); 
                res.pop_back(); 
            }
            
        }
    };