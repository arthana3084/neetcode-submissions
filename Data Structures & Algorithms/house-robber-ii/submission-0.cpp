class Solution {
public:
    int robhouse(vector<int>& nums,int house,vector<int>& dp)
    {
        if(dp[house]!=-1)
        {
            return dp[house];
        }
        dp[house]=max(nums[house]+robhouse(nums,house-2,dp),(robhouse(nums,house-1,dp)));
        return dp[house];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)
        {
            return nums[0];
        }
        if(nums.size()==2)
        {
            return max(nums[0],nums[1]);
        }
        vector<int> nums1(nums.begin()+1,nums.end());
        vector<int> nums2(nums.begin(),nums.end()-1);
        vector<int> dp1(nums1.size(),-1);
        dp1[0]=nums1[0];
        dp1[1]=max(nums1[0],nums1[1]);
        vector<int> dp2(nums2.size(),-1);
        dp2[0]=nums2[0];
        dp2[1]=max(nums2[0],nums2[1]);
        int nofirsthouse=robhouse(nums1,nums1.size()-1,dp1);
        int nolasthouse=robhouse(nums2,nums2.size()-1,dp2);
        return max(nofirsthouse,nolasthouse);
    }
};
