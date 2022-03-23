class Solution {
public:
    int distinctSubseqII(string s) 
    {
        long long mod = 1e9+7;
        int n = s.size();
        map<char,int>mp;
        
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        
        dp[0]=1;
        
        for(int i=1;i<=n;i++)
        {
            dp[i] = (dp[i-1]*2)%mod;
            
            if(mp.count(s[i-1])!=0)
            {
                int k = mp[s[i-1]];
                
                dp[i] = (dp[i]%mod - dp[k]%mod + mod)%mod;
            }
            
            mp[s[i-1]]=i-1;
            
        }
        
        return dp[n]-1;
    }
};