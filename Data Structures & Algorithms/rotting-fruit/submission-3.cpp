class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> rotten;
        int fresh=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    fresh++;
                }
                if(grid[i][j]==2)
                {
                    rotten.push({i,j});
                }
            }
        }
        if(fresh==0 and rotten.empty())
        {
            return 0;
        }
        int minutes=-1;
        while(!rotten.empty())
        {
            int size=rotten.size();
            for(int s=0;s<size;s++)
            {
                int i=rotten.front().first;
                int j=rotten.front().second;
                rotten.pop();
                int left=i-1;
                int right=i+1;
                int up=j-1;
                int down=j+1;
                if(left>=0 and grid[left][j]==1)
                {
                    grid[left][j]=2;
                    rotten.push({left,j});
                    fresh--;
                }
                if(right<grid.size() and grid[right][j]==1)
                {
                    grid[right][j]=2;
                    rotten.push({right,j});
                    fresh--;
                }
                if(up>=0 and grid[i][up]==1)
                {
                    grid[i][up]=2;
                    rotten.push({i,up});
                    fresh--;
                }
                if(down<grid[0].size() and grid[i][down]==1)
                {
                    grid[i][down]=2;
                    rotten.push({i,down});
                    fresh--;
                }
            }
            minutes++;
        }
        if(fresh > 0)
        {
            return -1;
        }
        return minutes;
    }
};
