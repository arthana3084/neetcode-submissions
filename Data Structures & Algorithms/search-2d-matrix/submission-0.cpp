class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(auto it: matrix)
        {
            for(int i=0;i<it.size();i++)
            {
                if(it[i]==target)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
