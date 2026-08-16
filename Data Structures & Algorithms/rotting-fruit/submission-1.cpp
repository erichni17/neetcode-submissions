class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size(); 

        queue<pair<int,int>> q; 

        vector<pair<int,int>> dir {
            {-1, 0}, 
            {1, 0}, 
            {0, -1}, 
            {0, 1}
        }; 

        int numFresh = 0; 
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2){
                    q.push({i, j}); 
                } else if (grid[i][j] == 1) {
                    numFresh++; 
                }
            }
        }

        int numMins = 0; 
        while (numFresh != 0 && !q.empty()) {
            int lvl = q.size(); 
            for (int i = 0; i < lvl; ++i) {
                auto [x, y] = q.front(); 
                q.pop();
                for (auto [dx, dy] : dir) {
                    int nx = x + dx;
                    int ny = y + dy; 
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m
                        && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2; 
                        q.push({nx, ny});
                        numFresh--;  
                    }
                }
            }
            numMins++; 
        }

        if (numFresh == 0) return numMins; 
        else return -1; 
    }
};
