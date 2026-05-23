class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
        {
                return false;
        }
        map<char,int> mpp;
        for(auto it:s)
        {
            mpp[it]++;
        }
        for(auto it:t)
        {
            mpp[it]--;
        }
        for(auto it:mpp)
        {
            if(it.second!=0)
            {
                return false;
            }
        }
        return true;
    }
};