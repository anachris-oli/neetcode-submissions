class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        auto rows = grid.size();
        auto cols = grid[0].size();
        vector<vector<int>> distances(rows, vector<int>(cols,INT_MAX));

        queue<pair<int,int>> nodes_not_visited;

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==0)
                {
                    nodes_not_visited.push({i,j});
                }
            }
        }

        vector<pair<int,int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
        while(not nodes_not_visited.empty())
        {
            auto [i,j]=nodes_not_visited.front();
            nodes_not_visited.pop();
            for(auto [di,dj]:directions)
            {
                if(grid[i][j]<0) continue;
                else
                {
                    auto ni = i+di;
                    auto nj = j+dj;
                    if(ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                        if(grid[i][j]+1 < grid[ni][nj])
                        {
                            grid[ni][nj] = grid[i][j]+1;
                            nodes_not_visited.push({ni,nj});
                        }
                    }
                }
            }
        }

    }

};
