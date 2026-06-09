class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i=0;i<stones.size();i++)
        {
            pq.push(stones[i]);
        }
        while(!pq.empty() and pq.size()>1)
        {
            int largeststone=pq.top();
            pq.pop();
            int secondlargeststone=pq.top();
            pq.pop();
            int remwt=largeststone-secondlargeststone;
            if(remwt>0)
            {
                pq.push(remwt);
            }
        }
        if(pq.empty())
        {
            return 0;
        }
        return pq.top();
    }
};
