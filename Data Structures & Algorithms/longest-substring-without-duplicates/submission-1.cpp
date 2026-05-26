class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int right=0;
        int length=0;
        map<char,int> freq;
        for(int i=0;i<s.size();i++)
        {  
            freq[s[i]]++;
            while(freq[s[i]]>1)
            {
                freq[s[left]]--;
                left++;
            }
            int currentlength=right-left+1;
            length=max(length,currentlength);
            right++;
        }
        return length;
    }
};
