class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(),1);
        int leftproduct=1;
        int rightproduct=1;
        for(int i=0;i<nums.size();i++)
        {
            ans[i]=leftproduct;
            leftproduct*=nums[i];
        }
        for(int j=nums.size()-1;j>=0;j--)
        {
            ans[j]*=rightproduct;
            rightproduct*=nums[j];
        }
        return ans;
    }
};
