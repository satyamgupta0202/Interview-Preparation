// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  
   int LCS(string a , string b){
       int n1 = a.size();
       int n2 = b.size();
       int dp[n1+1][n2+1];
       for(int i=0;i<=n1;i++){
           for(int j=0;j<=n2;j++){
               dp[i][j]=0;
           }
       }
       for(int i=1;i<=n1;i++){
           for(int j=1;j<=n2;j++){
               if(a[i-1]==b[j-1]){
                   dp[i][j]=dp[i-1][j-1]+1;
               }else{
                   dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
               }
           }
       }
       
       return dp[n1][n2];
   }
  
    int longestPalinSubseq(string A) {
        //code here
        string a = A;
        reverse(A.begin(),A.end());
        string b = A;
        return LCS(a,b);
    }
};

// { Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends