//https://leetcode.com/problems/unique-paths-ii/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int num_rows = obstacleGrid.size(), num_cols = obstacleGrid.at(0).size(); 
        vector<vector<int> > res(num_rows,vector<int>(num_cols));
        int curr = 1; 
        for(int i = 0; i < num_rows; i++){
            if(obstacleGrid[i][0] == 1){
                res[i][0] = 0, curr = 0; 
            }
            else{
                res[i][0] = curr; 
            } 
        }
        curr = 1; 
        for(int j = 0; j < num_cols; j++){
            if(obstacleGrid[0][j] == 1){
                res[0][j] = 0; 
                curr = 0; 
            }
            else{
                res[0][j] = curr; 
            } 
        }
        for(int i = 1; i < num_rows; i++){
            for(int j = 1; j < num_cols; j++){
                if(obstacleGrid[i][j] == 1){
                    res[i][j] = 0; 
                }
                else{
                    res[i][j] = res[i-1][j] + res[i][j-1]; 
                }
            }
        }
        return res[num_rows -1][num_cols-1]; 
    }
};