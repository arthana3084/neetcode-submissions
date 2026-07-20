class Solution {
public:
    bool isSubsetSum(vector<int> &arr,int sum)
    {
        int n=arr.size();
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=true;
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=1;j<=sum;j++)
            {
                bool nottake=dp[i+1][j];
                bool take=false;
                if(arr[i]<=j)
                {
                    take=dp[i+1][j-arr[i]];
                }
                dp[i][j]= take || nottake;
            }
        }
        return dp[0][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        if(sum%2!=0)
        {
            return false;
        }
        return isSubsetSum(nums,sum/2);
    }
};
