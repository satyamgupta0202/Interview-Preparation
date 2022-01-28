class Solution {
public:
    int ans=0;
    int dp[1005][1005];
    int solve(string s , string t , int i , int j){
        
        if(i==t.size()){
            return 1;
        }
        
        if(j==s.size()){
            return 0;
        }
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        if(t[i]!=s[j]){
            if(dp[i][j]!=-1)return dp[i][j];
            return dp[i][j] = solve(s,t,i,j+1);
        }
        
        if(t[i]==s[j]){
            
            int l , r;
            if(dp[i+1][j+1]!=-1)l = dp[i+1][j+1];
            else l = solve(s,t,i+1,j+1);
            if(dp[i][j+1]!=-1)r=dp[i][j+1];
            else r = solve(s,t,i,j+1);
            return dp[i][j] = l+r;
        }
        return 0;
    }
    
    
    int numDistinct(string s, string t) {
        
         memset(dp,-1,sizeof(dp));
         return solve(s,t,0,0);
  
    }
};