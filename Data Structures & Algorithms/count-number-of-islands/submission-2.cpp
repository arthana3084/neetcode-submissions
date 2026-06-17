class Solution {
public:
    void dfs(vector<vector<char>>& grid,vector<vector<int>>& visited,int i,int j)
    {
        if(i>=grid.size() or i<0 or j>=grid[0].size() or j<0)
        {
            return;
        }
        if(grid[i][j]=='0')
        {
            return;
        }
        if(visited[i][j])
        {
            return;
        }
        visited[i][j]=1;
        dfs(grid,visited,i-1,j);
        dfs(grid,visited,i+1,j);
        dfs(grid,visited,i,j-1);
        dfs(grid,visited,i,j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        int islands=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1' and !visited[i][j])
                {
                    islands++;
                    dfs(grid,visited,i,j);
                }
            }
        }
        return islands;
    }
};
