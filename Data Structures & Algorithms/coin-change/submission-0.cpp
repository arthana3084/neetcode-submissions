class Solution {
public:
    int solve(int i,int remainingsum,int n,vector<int> &coins)
    {
        if(remainingsum==0)
        {
            return 0;
        }
        if(i==n)
        {
            return INT_MAX;
        }
        int nottake=solve(i+1,remainingsum,n,coins);
        int take=INT_MAX;
        if(coins[i]<=remainingsum)
        {
            int res = solve(i, remainingsum - coins[i],n,coins);
            if (res != INT_MAX)
            {
                take = 1 + res;
            }    
        }
        return min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans=solve(0,amount,coins.size(),coins);
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};
