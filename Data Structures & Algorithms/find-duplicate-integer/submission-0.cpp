class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> seen;
        for(int i=0;i<nums.size();i++)
        {
            if(!seen.count(nums[i]))
            {
                seen.insert(nums[i]);
            }
            else
            {
                return nums[i];
            }
        }
    }
};
