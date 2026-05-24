class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0;
        int min_so_far=prices[0];
        for(int i=0;i<prices.size();i++)
        {
            int profit;
            if(prices[i]<min_so_far)
            {
                min_so_far=prices[i];
            }
            profit=prices[i]-min_so_far;
            maxprofit=max(maxprofit,profit);
        }
        return maxprofit;
    }
};
