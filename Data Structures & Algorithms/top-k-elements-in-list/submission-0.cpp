class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> freq;
        for(int i=0;i<nums.size();i++)
        {
            freq[nums[i]]++;
        }
        vector<int> ans;
        vector<pair<int,int>> p;
        for(auto it: freq)
        {
            p.push_back({it.second,it.first});
        }
        sort(p.begin(),p.end());
        int j=p.size()-1;
        for(int i=0;i<k;i++)
        {
            ans.push_back(p[j].second);
            j--;
        }
        return ans;
    }
};
