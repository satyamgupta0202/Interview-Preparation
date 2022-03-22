class Solution {
public:
    string longestPalindrome(string s)
    {
        
        int n = s.size();
        vector<vector<bool>>dp(n , vector<bool>(n,false));
        int p=-1,q=-1;
        int l=0;
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                if(s[i]==s[j])
                {
                    if(i==j || j-i==1 || dp[i+1][j-1])
                    {
                        dp[i][j]=true;
                        if(l<(j-i+1))
                        {
                            l=j-i+1;
                            p=i;
                            q=j;
                        }
                    }
                }
            }
        }
        return s.substr(p,q-p+1);      
    }
};