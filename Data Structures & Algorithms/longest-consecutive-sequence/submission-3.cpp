class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        
        for(int i=0;i<nums.size();i++)
        {
            st.insert(nums[i]);
        }

        int count=0;
        int currentcount=0;

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
                count=max(count,currentcount);
            }
            else
            {
                currentcount=1;
                count=max(count,currentcount);
            }
            
        }
        return count;
    }
};
