//https://leetcode.com/problems/unique-paths/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<std::vector<int> > res(m,vector<int>(n));
        for(int i = 0; i < m; i++) res[i][0] = 1; 
        for(int j = 0; j < n; j++) res[0][j] = 1; 
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                res[i][j] = res[i-1][j] + res[i][j-1]; 
            }
        }
        return res[m-1][n-1]; 
    }
};