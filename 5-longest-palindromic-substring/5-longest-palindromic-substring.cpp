class Solution {
public:
    string longestPalindrome(string s) {
      
         int n = s.size();
         vector<vector<bool>>dp(n,vector<bool>(n,false));
         int l = 0;
         int p=-1,q=-1;
         int ans=0;
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                if(i==j)
                {
                    dp[i][j]=true;
                }
               else if(j-i==1 )
                {
                    if(s[i]==s[j])
                    {
                        dp[i][j]=true;
                    }
                    else
                    {
                        dp[i][j]=false;
                    }
                }
                else 
                {
                    if(s[j]==s[i] && dp[i+1][j-1])
                    {
                        dp[i][j]=true;
                    }
                    else
                    {
                        dp[i][j]=false;
                    }
                }
                
                if(dp[i][j])
                {
                    if(ans<=(j-i+1))
                    {
                        p=i;
                        q=j;
                        ans = j-i+1;
                    }
                }
            }
        }
        return s.substr(p,q-p+1);
        
    }
};