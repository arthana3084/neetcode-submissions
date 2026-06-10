class Solution {
public:
    vector<vector<int>> ans;
    vector<int> subset;
    vector<vector<int>> subsets(int index,vector<int>& nums)
    {
        if(index==nums.size())
        {
            ans.push_back(subset);
            return ans;
        }
        subset.push_back(nums[index]);
        subsets(index+1,nums);
        subset.pop_back();
        subsets(index+1,nums);
        return ans;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result=subsets(0,nums);
        return result;
    }
};
