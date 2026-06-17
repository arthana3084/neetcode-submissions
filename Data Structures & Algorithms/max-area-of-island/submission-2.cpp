class Solution {
public:
    int dfs(vector<vector<int>>& grid,vector<vector<int>>& visited,int i,int j)
    {
        if(i>=grid.size() or i<0 or j>=grid[0].size() or j<0)
        {
            return 0;
        }
        if(grid[i][j]==0)
        {
            return 0;
        }
        if(visited[i][j])
        {
            return 0;
        }
        int up,down,right,left;
        visited[i][j]=1;
        left=dfs(grid,visited,i-1,j);
        right=dfs(grid,visited,i+1,j);
        down=dfs(grid,visited,i,j-1);
        up=dfs(grid,visited,i,j+1);
        return 1+up+down+right+left;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        int maxcomponent=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1 and !visited[i][j])
                {
                    int component=dfs(grid,visited,i,j);
                    maxcomponent=max(maxcomponent,component);
                }
            }
        }
        return maxcomponent;
    }
};
