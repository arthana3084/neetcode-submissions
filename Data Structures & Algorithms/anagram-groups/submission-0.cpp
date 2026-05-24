class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> anag;
        for(int i=0;i<strs.size();i++)
        {
            string strs1= strs[i];
            sort(strs1.begin(),strs1.end());
            anag[strs1].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto it: anag)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};
