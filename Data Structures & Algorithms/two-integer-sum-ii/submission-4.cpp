class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int left=0;
        int right=numbers.size()-1;
        for(int i= right;i>=0;i--)
        {
            int sum=numbers[left]+numbers[right];
            if(sum==target)
            {
                ans.push_back(left+1);
                ans.push_back(right+1);
                return ans;
            }
            else if(sum>target)
            {
                right--;
            }
            else
            {
                left++;
            }           
        }
        return ans;
    }
};
