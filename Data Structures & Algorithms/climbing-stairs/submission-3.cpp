class Solution {
public:
    int climbstairshelper(int n,vector<int>& dp)
    {
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        for(int i=3;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    int climbStairs(int n) {
        if(n==1)
        {
            return 1;
        }
        vector<int> dp(n+1,-1); 
        dp[1]=1;
        dp[2]=2;
        int ans=climbstairshelper(n,dp);
        return ans;
    }
};
