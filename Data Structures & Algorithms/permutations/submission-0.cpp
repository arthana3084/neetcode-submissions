class Solution {
public:
    vector<vector<int>> ans;
    vector<int> permutation;
    void generatepermutation(vector<int>& permutation,vector<int>& nums,set<int>& hashset)
    {
        if(permutation.size()==nums.size())
        {
            ans.push_back(permutation);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(!hashset.count(nums[i]))
            {
                permutation.push_back(nums[i]);
                hashset.insert(nums[i]);
                generatepermutation(permutation,nums,hashset);
                permutation.pop_back();
                hashset.erase(nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> permutation;
        set<int> hashset;
        generatepermutation(permutation,nums,hashset);
        return ans;
    }
};
