class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0; 
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    visitIsland(grid, i, j); 
                    res++; 
                }
            }
        }
        return res; 
    }

    void visitIsland(vector<vector<char>>& grid, int x, int y) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) {
            return; 
        }
        if (grid[x][y] == '1') {
            grid[x][y] = '0'; 
            visitIsland(grid, x + 1, y); 
            visitIsland(grid, x - 1, y); 
            visitIsland(grid, x, y + 1); 
            visitIsland(grid, x, y - 1);
        }
         
    }
};
