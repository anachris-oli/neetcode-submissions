class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int num_islands = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    num_islands++;
                    rec(grid, i,j);
                }
            }
        }
        return num_islands;
    }

    void rec(vector<vector<char>>& grid, int i, int j)
    {
        if(i>=grid.size() or j>=grid[i].size()) return;
        if(i<0 or j<0) return;

        if(grid[i][j]=='0') return;

        grid[i][j] = '0';
        rec(grid,i+1,j);
        rec(grid,i,j+1);
        rec(grid,i-1,j);
        rec(grid,i,j-1);
    }
};
