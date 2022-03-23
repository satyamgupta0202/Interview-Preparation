// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    int lcs(string s1 , string s2 ,  int n ,int m)
    {
        
        int dp[n+1][m+1];
        int ans = 0;
        memset(dp,0,sizeof(dp));
        
      // for(int i=0;i<=n;i++)dp[i][0]=1;
       
       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=m;j++)
           {
               if(s1[i-1] !=s2[j-1])
               {
                   dp[i][j]=0;
               }
               else
               {
                   dp[i][j] =max(dp[i-1][j-1]+1 , dp[i][j]);
                   ans = max(ans,dp[i][j]);
               }
           }
       }
       return ans;
    }
    
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        // your code here
        return lcs(s1,s2,n,m);
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends