class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int,int> hashmap;
        for(int i=0;i<nums.size();i++)
        {   
            int need=target-nums[i];
            if(hashmap.find(need)!=hashmap.end())
            {
                ans.push_back(hashmap[need]);
                ans.push_back(i);
            }
            hashmap[nums[i]]=i;
        }
        return ans;
    }
};
