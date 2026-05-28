class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans1;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            int j=i+1;
            int k=nums.size()-1;
            while(j<k)
            {
                if(nums[i]+nums[j]+nums[k]==0)
                {   vector<int> v={nums[i],nums[j],nums[k]};
                    ans1.insert(v);
                    k--;
                    j++;
                }
                else if(nums[i]+nums[j]+nums[k]<0)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }
        for(auto it:ans1)
        {
            ans.push_back(it);
        }
        return ans;
    }
};
