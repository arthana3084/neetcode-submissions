class Solution {
public:
    int dfs(vector<vector<int>>& grid,vector<vector<int>>& visited,int i, int j)
    {
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size())
        {
            return 0;
        }
        if(visited[i][j])
        {
            return 0;
        }
        if(grid[i][j]==0)
        {
            return 0;
        }
        int left,right,down,up;
        visited[i][j]=1;
        {
            left=dfs(grid,visited,i-1,j);
            down=dfs(grid,visited,i,j-1);
            right=dfs(grid,visited,i+1,j);
            up=dfs(grid,visited,i,j+1);
        }
        return 1+up+down+left+right;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        int maxcount=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1 and !visited[i][j])
                {
                    int islandlength=dfs(grid,visited,i,j);
                    maxcount=max(maxcount,islandlength);
                }  
            }    
        }
        return maxcount;
    }
};

