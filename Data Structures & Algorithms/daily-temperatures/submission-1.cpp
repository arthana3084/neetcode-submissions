class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(),0);
        stack<pair<int,int>> st;
        for(int i=0;i<temperatures.size();i++)
        {
            if(st.empty() or st.top().first>=temperatures[i])
            {
                st.push({temperatures[i],i});
            }
            while(!st.empty() and st.top().first<temperatures[i])
            {
                int value=i-st.top().second;
                ans[st.top().second]=value;
                st.pop();
            }
            st.push({temperatures[i],i});
        }
        return ans;
    }
};
