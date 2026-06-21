class Solution {
public:
    int mincosthelper(vector<int>& cost,int n,vector<int>& dp)
    {
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        return dp[n]=cost[n]+min(mincosthelper(cost,n-1,dp),mincosthelper(cost,n-2,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int size=cost.size();
        vector<int> dp(size,-1);
        dp[0]=cost[0];
        dp[1]=cost[1];
        return min(mincosthelper(cost,size-1,dp),mincosthelper(cost,size-2,dp));
    }
};
