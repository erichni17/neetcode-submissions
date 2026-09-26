class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size(); 
        int cols = heights[0].size(); 
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false)); 
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false)); 

        for (int j = 0; j < cols; ++j) {
            explore(pacific, heights, 0, j, 0); 
        }
        for (int i = 1; i < rows; ++i) {
            explore(pacific, heights, i, 0, 0); 
        }
        for (int j = 0; j < cols; ++j) {
            explore(atlantic, heights, rows - 1, j, 0); 
        }
        for (int i = 0; i < rows - 1; ++i) {
            explore(atlantic, heights, i, cols - 1, 0); 
        }   

        vector<vector<int>> res; 
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (atlantic[i][j] && pacific[i][j]) {
                    res.push_back({i, j}); 
                }
            }
        }
        return res; 
    } 

    void explore(vector<vector<bool>>& ocean, vector<vector<int>>& heights, int r, int c, int curr) {
        int m = heights.size(); 
        int n = heights[0].size(); 
        if (r >= 0 && r < m && c >= 0 && c < n
            && !ocean[r][c] && heights[r][c] >= curr){
            ocean[r][c] = true;
            curr = heights[r][c]; 
            explore(ocean, heights, r - 1, c, curr);
            explore(ocean, heights, r + 1, c, curr); 
            explore(ocean, heights, r, c - 1, curr); 
            explore(ocean, heights, r, c + 1, curr); 
        }
    }
};
