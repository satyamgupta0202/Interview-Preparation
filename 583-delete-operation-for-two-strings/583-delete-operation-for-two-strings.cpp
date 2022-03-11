class Solution {
public:
    
    int solve(string s1 ,string s2)
    {
        
        int n1 = s1.size() , n2 = s2.size();
        int dp[n1+1][n2+1];
        memset(dp,0,sizeof(dp));
        
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        
        return dp[n1][n2];
        
    }
    
    
    int minDistance(string s1, string s2) 
    {
        int k = solve(s1,s2);
        
        return s1.size() + s2.size() -k-k;
        
    }
};