class Solution {
public:
    bool isPalindrome(string s) {
        for(int i=0;i<s.size();i++)
        {
            s[i]=tolower(s[i]);
        }
        int left=0;
        int right=s.size()-1;
        while(left<right)
        {
            while(left<right and !isalnum(s[left]))
            {
                left++;
            }
            while(left<right and !isalnum(s[right]))
            {
                right--;
            }
            if(s[left]!=s[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
