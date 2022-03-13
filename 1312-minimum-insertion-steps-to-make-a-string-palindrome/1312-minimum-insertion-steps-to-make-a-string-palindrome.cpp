class Solution {
public:
    
    int solve(string s1 , string s2)
    {
        int n = s1.size();
        int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        
        for(int i=0;i<=n;i++)dp[i][0]=0;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    } 
    
    
    int minInsertions(string s)
    {
        int n = s.size();
        string s2 = s;
        reverse(s2.begin(),s2.end());
        
        int k = solve(s,s2);
        
        return n-k;
    }
};