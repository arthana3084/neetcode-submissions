class Solution {
public:
    int robhouse(vector<int>& nums,int house,vector<int>& dp)
    {
        if(dp[house]!=-1)
        {
            return dp[house];
        }
        dp[house]=max(nums[house]+robhouse(nums,house-2,dp),robhouse(nums,house-1,dp));
        return dp[house];
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        if(nums.size()==1)
        {
            return nums[0];
        }
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        return robhouse(nums,nums.size()-1,dp);
    }
};
