class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int right=0;
        int maxlength=0;
        map<char,int> freq;
        while(right<s.size())
        {
            freq[s[right]]++;
            while(freq[s[right]]>1)
            {
                freq[s[left]]--;
                left++;
            }
            int currentlength=right-left+1;
            maxlength=max(maxlength,currentlength);
            right++;
        }
        return maxlength;
    }
};
