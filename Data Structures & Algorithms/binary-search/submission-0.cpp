class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lower=0;
        int upper=nums.size()-1;
        while(lower<=upper)
        {
            int midpoint=(upper+lower)/2;
            int midvalue=nums[midpoint];
            if(target==midvalue)
            {
                return midpoint;
            }
            else if(target<midvalue)
            {
                upper=midpoint-1;
            }
            else
            {
                lower=midpoint+1;
            }
        }
        return -1;
    }
};
