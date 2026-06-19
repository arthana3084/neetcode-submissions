class Solution {
public:
    int climbstairshelper(int n,vector<int>& dp)
    {
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        dp[n]=climbstairshelper(n-1,dp)+climbstairshelper(n-2,dp);
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
