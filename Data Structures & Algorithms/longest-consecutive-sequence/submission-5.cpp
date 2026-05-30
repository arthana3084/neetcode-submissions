class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int currentcount=0;
        int maxcount=0;
        for(int i=0;i<nums.size();i++)
        {
            st.insert(nums[i]);
        }
        for(int i=0;i<nums.size();i++)
        {
            if(!st.count(nums[i]-1))
            {
                int x=nums[i];
                currentcount=1;
                while(st.count(x+1))
                {
                    currentcount++;
                    x++;
                }
                maxcount=max(currentcount,maxcount);
            }
            else
            {
                currentcount=1;
            }
        }
        return maxcount;
    }
};
