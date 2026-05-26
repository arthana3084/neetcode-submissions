class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int i=0;
        while(i<nums.size())
        {   
            int leftproduct=1;
            int rightproduct=1;
            for(int j=0;j<i;j++)
            {
                leftproduct*=nums[j];
            }
            for(int j=i+1;j<nums.size();j++)
            {
                rightproduct*=nums[j];
            }
            int result=leftproduct*rightproduct;
            ans.insert(ans.begin()+i,result);
            i++;
        }
        return ans;
    }
};
