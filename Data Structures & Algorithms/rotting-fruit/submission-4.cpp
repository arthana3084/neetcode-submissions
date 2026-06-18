class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        queue<pair<int,int>> rotten;
        int fresh = 0;

        int rows = grid.size();
        int cols = grid[0].size();

        // Count fresh oranges and store rotten ones
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == 1)
                    fresh++;

                else if(grid[i][j] == 2)
                    rotten.push({i,j});
            }
        }

        // No fresh oranges
        if(fresh == 0)
            return 0;

        int minutes = 0;

        vector<pair<int,int>> directions = {
            {-1,0},
            {1,0},
            {0,-1},
            {0,1}
        };

        while(!rotten.empty())
        {
            int size = rotten.size();
            bool rottedThisMinute = false;

            for(int s = 0; s < size; s++)
            {
                auto [r,c] = rotten.front();
                rotten.pop();

                for(auto dir : directions)
                {
                    int nr = r + dir.first;
                    int nc = c + dir.second;

                    if(nr >= 0 && nr < rows &&
                       nc >= 0 && nc < cols &&
                       grid[nr][nc] == 1)
                    {
                        grid[nr][nc] = 2;
                        fresh--;
                        rotten.push({nr,nc});

                        rottedThisMinute = true;
                    }
                }
            }

            if(rottedThisMinute)
                minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};