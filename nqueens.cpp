class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        //Create empty board with size n x n
        // 0 == empty cell
        // 1 == cell with queen
        vector<vector<int>> board(n, vector<int>(n,0));
        vector<vector<string>> res; 
        set<vector<string>> res2; 
        vector<vector<int>> visited; 
        backtrack(n,board, 0, res2,  visited); 
        for(auto f : res2) {
            res.push_back(f); 
        }    
        return res; 
    }
    
    void backtrack(int n, vector<vector<int>>& board, int curr_num_queens, set<vector<string>>& res, vector<vector<int>>& visited){
        if(curr_num_queens == n){
            vector<string> temp_res = to_str_board(board); 
            res.insert(temp_res); 
            return; 
        }
        if(curr_num_queens > n){
            return; 
        }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board.at(0).size(); j++){
                bool is_valid = valid_position(board, i, j); 
                bool already_visited = check_visited(visited, i,j); 
                if(is_valid && !already_visited){
                    curr_num_queens++; 
                    board[i][j] = 1; 
                    visited.push_back({i,j}); 
                    backtrack(n, board,curr_num_queens, res, visited); 
                    visited.pop_back(); 
                    curr_num_queens--; 
                    board[i][j] = 0; 
                }
            }
        }
    }
    bool check_visited(vector<vector<int>>& visited, int curr_i, int curr_j){
        for(int q = 0; q < visited.size(); q++){
            vector<int> v = visited.at(q); 
            if(v[0] == curr_i && v[1] == curr_j){
                return true; 
            }
        }
        return false; 
    }
    bool valid_position(vector<vector<int>>& board, int pos_x, int pos_y){
        //compare against all the other queens on the board to see if it is valid
        for(int i = 0; i < board.size(); i++){
            if(board[i][pos_y] == 1){
                return false; 
            }
        }
        for(int j = 0; j < board.at(0).size(); j++){
            if(board[pos_x][j] == 1){
                return false; 
            }
        }
        //two diagonals
        //diag 1
        int temp_x = pos_x + 1; 
        int temp_y = pos_y + 1; 
        while(temp_x < board.size() && temp_y < board.at(0).size()){
            if(board[temp_x][temp_y] == 1){
                return false; 
            }
            temp_x++; 
            temp_y++; 
        }
        
        int temp_x0 = pos_x - 1; 
        int temp_y0 = pos_y - 1; 
        while(temp_x0 >= 0 && temp_y0 >= 0){
            if(board[temp_x0][temp_y0] == 1){
                return false; 
            }
            temp_x0--; 
            temp_y0--; 
        }
        
        //diag2
        int temp_x1 = pos_x + 1; 
        int temp_y1 = pos_y - 1; 
        while(temp_x1 < board.size() && temp_y1 >= 0){
            if(board[temp_x1][temp_y1] == 1){
                return false; 
            }
            temp_x1++; 
            temp_y1--; 
        }
        
        int temp_x2 = pos_x - 1; 
        int temp_y2 = pos_y + 1; 
        while(temp_x2 >= 0 && temp_y2 < board.at(0).size()){
            if(board[temp_x2][temp_y2] == 1){
                return false; 
            }
            temp_x2--; 
            temp_y2++; 
        }
        return true; 
    }
    vector<string> to_str_board(vector<vector<int>>& board){
        vector<string> ret; 
        for(int q = 0; q< board.size(); q++){
            string row = ""; 
            for(int r = 0; r< board.at(0).size(); r++){
                if(board[q][r] == 1){
                    row += "Q"; 
                }
                else{
                    row += "."; 
                }
            }
            ret.push_back(row); 
        }
        return ret; 
    }
};