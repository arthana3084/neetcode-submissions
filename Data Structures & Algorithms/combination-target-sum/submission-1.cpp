class Solution {
public:
    vector<vector<int>> ans;
    vector<int> combination;
    int sum=0;
    int index=0;
    void combinationhelper(vector<int>&nums, int index,int target,int sum)
    {
        if(sum==target)
        {
            ans.push_back(combination);
            return;
        }
        if(sum>target)
        {
            return;
        }
        if(index==nums.size())
        {
            return;
        }
        combination.push_back(nums[index]);
        sum+=nums[index];
        combinationhelper(nums,index,target,sum);
        combination.pop_back();
        sum-=nums[index];
        combinationhelper(nums,index+1,target,sum);
        return ;
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        combinationhelper(nums,0,target,sum);
        return ans;
    }
};
