class Solution {
public:
    int numTilings(int n) {
        
        int dp[n+1];
        int mod = 1e9+7;
        for(int i=0;i<=n;i++)dp[i]=0;
        
        if(n<=2)return n;
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        if(n==3)return 5;
        dp[3]=5;
        for(int i=4;i<=n;i++)
        {
            
            dp[i] = ((2*dp[i-1])%mod + (dp[i-3]%mod))%mod;
          

        }
        return dp[n];
        
        
        
        
        
        
    }
};