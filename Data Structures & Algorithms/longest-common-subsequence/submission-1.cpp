class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                int match=0;
                int notmatch1=0;
                int notmatch2=0;
                if(text1[i]==text2[j])
                {
                    match=1+dp[i+1][j+1];
                }
                else
                {
                    notmatch1=dp[i+1][j];
                    notmatch2=dp[i][j+1];
                }
                dp[i][j]=max({match,notmatch1,notmatch2});
            }
        }
        return dp[0][0];
    }
};
