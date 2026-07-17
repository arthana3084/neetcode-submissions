class Solution {
public:
    int solve(vector<int> &cases)
    {
        int m=cases.size();
        int prev2=cases[0];
        int prev1=max(cases[0],cases[1]);
        int maxcost=0;
        for(int i=2;i<m;i++)
        {
            maxcost=max(cases[i]+prev2,prev1);
            prev2=prev1;
            prev1=maxcost;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        {
            return nums[0];
        }
        if(n==2)
        {
            return max(nums[0],nums[1]);
        }
        vector<int> case1(nums.begin(), nums.end() - 1);
        vector<int> case2(nums.begin() + 1, nums.end());
        int maxcost1=solve(case1);
        int maxcost2=solve(case2);

        return max(maxcost1,maxcost2); 
    }
};
