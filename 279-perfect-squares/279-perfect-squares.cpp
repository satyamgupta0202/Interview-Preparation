class Solution {
public:
    int numSquares(int n)
    {
        int dp[n+1];
        memset(dp,1000000,sizeof(dp));
        dp[0]=0;
        dp[1]=1;
       

        for(int i=2;i<=n;i++)
        {
            for(int j=1;j*j<=i;j++)
            {
               dp[i] = min(dp[i] , dp[i-(j*j)] +1);
            }
        }
        return dp[n];
    }
};