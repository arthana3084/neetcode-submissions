class Solution {
public:
    int dfs(vector<vector<int>>& grid,vector<vector<int>>& visited,int i,int j,int& component)
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
        component++;
        left=dfs(grid,visited,i-1,j,component);
        right=dfs(grid,visited,i+1,j,component);
        down=dfs(grid,visited,i,j-1,component);
        up=dfs(grid,visited,i,j+1,component);
        return 1+up+down+right+left;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        int maxcomponent=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                int component=0;
                if(grid[i][j]==1 and !visited[i][j])
                {
                    dfs(grid,visited,i,j,component);
                    maxcomponent=max(maxcomponent,component);
                }
            }
        }
        return maxcomponent;
    }
};
