class Solution {
public:
    vector<string> ans;
    string curr;
    void generatepara(string curr,int n,int open,int close)
    {
        if(curr.size()==2*n)
        {
            ans.push_back(curr);
            return;
        }
        if(open!=n)
        {
            generatepara(curr+'(',n,open+1,close);
        }
        if(close<open)
        {
            generatepara(curr+')',n,open,close+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        int open=0;
        int close=0;
        generatepara(curr,n,open,close);
        return ans;
    }
};
