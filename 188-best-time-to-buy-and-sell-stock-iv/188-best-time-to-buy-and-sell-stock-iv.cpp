class Solution {
public:
    int maxProfit(int k, vector<int>&a) 
    {
        int n = a.size();
        if(n==0)return 0;
        int dp[k+1][n];
        memset(dp,0,sizeof(dp));

       for(int i=1;i<=k;i++){
        for(int j=1;j<n;j++){
            
           int m = dp[i][j-1];

           for(int k=0;k<j;k++){
               int aa = dp[i-1][k];
               int bb = a[j]-a[k];
               m = max(m , aa+bb);
           }

           dp[i][j] = m;
        }
    }
        
        return dp[k][n-1];
        
        
    }
};