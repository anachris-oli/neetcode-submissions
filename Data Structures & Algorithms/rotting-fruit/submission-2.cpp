class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        
        int n_freshfruit = 0;
        auto rows = grid.size();
        auto cols = grid[0].size();
        vector<vector<int>> minutes_passed(rows,vector<int>(cols,0));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    n_freshfruit++;
            }
        }
        int minutes = 0;
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (!q.empty() and n_freshfruit>0) {
            auto [i, j] = q.front();
            q.pop();
            
            for (auto [di, dj] : dir) {
                auto ni = i + di;
                auto nj = j + dj;
                if (ni >= 0 and nj >= 0 and ni < rows and nj < cols) {
                    if (grid[ni][nj] == 1) {
                        grid[ni][nj] = 2;
                        minutes_passed[ni][nj]=minutes_passed[i][j]+1;
                        q.push({ni, nj});
                        n_freshfruit--;
                        minutes=max(minutes,minutes_passed[ni][nj]);
                    }
                }
            }
            
            
        }
        return n_freshfruit > 0 ? -1 : minutes;
    }
};
