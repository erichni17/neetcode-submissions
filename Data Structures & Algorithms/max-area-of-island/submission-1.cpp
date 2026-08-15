class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0; 
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    int area = 0; 
                    visitIsland(grid, i, j, area);
                    maxArea = max(maxArea, area); 
                }
            }
        }
        return maxArea; 
    }
    void visitIsland(vector<vector<int>>& grid, int x, int y, int& area) {
        static vector<pair<int,int>> dir {
            {-1, 0},
            {1, 0}, 
            {0, -1},
            {0, 1}
        };
        grid[x][y] = 0; 
        area++; 
        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i].first;
            int ny = y + dir[i].second; 
            if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size()
                && grid[nx][ny] == 1) {
                    visitIsland(grid, nx, ny, area); 
            }
        }
    }
};
