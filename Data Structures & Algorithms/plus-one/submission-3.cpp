class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=0;
        int result=digits[digits.size()-1]+1;
        int seconddigit=result%10;
        carry=result/10;
        vector<int> ans;
        ans.push_back(seconddigit);
        for(int i=digits.size()-2;i>=0;i--)
        {
            if(carry==0)
            {
                ans.push_back(digits[i]);
            }
            else
            {
                result=digits[i]+carry;
                seconddigit=result%10;
                carry=result/10;
                ans.push_back(seconddigit);
            }
        }
        if(carry==1)
        {
            ans.push_back(carry);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
