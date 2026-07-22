class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int rows=mat.size();
        int cols=mat[0].size();
        int low=0;
        int high=(rows*cols)-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(mat[mid / cols][mid % cols]==target)
            {
                return true;
            }
            else if(target>mat[mid / cols][mid % cols])
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return false;
    }
};
