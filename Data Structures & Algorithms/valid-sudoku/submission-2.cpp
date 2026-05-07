class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size(); 
        vector<unordered_set<char>> rows(n);
        vector<unordered_set<char>> cols(n);
        vector<unordered_set<char>> subBoxes(n); 

        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                char val = board[i][j];
                if (val == '.') continue; 
                int box = i/3 * 3 + j/3;
                if (rows[i].count(val) || cols[j].count(val)
                    || subBoxes[box].count(val)) return false; 
                
                rows[i].insert(val);
                cols[j].insert(val);
                subBoxes[box].insert(val); 
            }
        }
        return true; 
    }
};
