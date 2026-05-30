class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int carfleet=position.size();
        vector<pair<int,int>> cars;
        stack<float> st;
        for(int i=0;i<position.size();i++)
        {
            cars.push_back({position[i],speed[i]});
        }
        sort(cars.begin(),cars.end(),greater<pair<int,int>>());
        for(int i=0;i<cars.size();i++)
        {   
            float finishtime=float(target-cars[i].first)/cars[i].second;
            if(st.empty() or st.top()<finishtime)
            {
                st.push(finishtime);
            }
            else if(!st.empty() and st.top()>=finishtime)
            {
                carfleet--;
            }
        }
        return carfleet;
    }
};

    
