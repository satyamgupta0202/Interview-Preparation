class Solution {
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        int n = prices.size();
        if(n==0)return 0;
        int dp[k+1][n];
        memset(dp,0,sizeof(dp));
        
        for(int i=1;i<=k;i++)
        {
            for(int j=1;j<n;j++)
            {
                int temp = dp[i][j-1];
                for(int p=0;p<j;p++)
                {
                    
                    int a = dp[i-1][p];
                    int b = prices[j]-prices[p];
                    temp = max(temp , a+b);
                }
                dp[i][j]=temp;
            }
        }
        return dp[k][n-1];
    }
};