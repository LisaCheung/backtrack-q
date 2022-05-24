//https://leetcode.com/problems/number-of-islands/
#include <iostream> 
#include <queue> 
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0; 
        int num_rows = grid.size(); 
        int num_cols = grid.at(0).size(); 
        for(int i = 0; i < num_rows; i++){
            for(int j = 0; j < num_cols; j++){
                if(grid[i][j] == '1'){
                    ++res; 
                    queue<int> row_queue; 
                    queue<int> col_queue;
                    row_queue.push(i); 
                    col_queue.push(j); 
                    while(!row_queue.empty() && !col_queue.empty()){
                        int q = row_queue.front(); 
                        int r = col_queue.front(); 
                        row_queue.pop(); 
                        col_queue.pop(); 
                        grid[q][r] = '0'; 
                        if(q+ 1 < num_rows){
                            if(grid[q+1][r] == '1'){
                                row_queue.push(q+1); 
                                col_queue.push(r); 
                                grid[q+1][r] = '0'; 
                            }
                            
                        }
                        if(r+1 < num_cols){
                            if(grid[q][r+1] == '1'){
                                row_queue.push(q); 
                                col_queue.push(r+1); 
                                grid[q][r+1] ='0'; 
                            } 
                        }
                        if(r-1 >= 0){
                            if(grid[q][r-1] == '1'){
                                row_queue.push(q); 
                            col_queue.push(r-1 ); 
                                grid[q][r-1] ='0';
                            } 
                            
                            
                        }
                        if(q-1 >= 0){
                            if(grid[q-1][r] == '1'){
                                row_queue.push(q-1); 
                                col_queue.push(r); 
                                grid[q-1][r] ='0';
                            } 
                            
                        } 
                    }
                  
                }
            }
        }
        return res; 
    }
};