// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    long long int dp[1001][1001];
    long long  mod = 1e9+7;
    long long int solve(string &str , int i , int j)
    {
        if(i>j)return 0;
         if(i==j)return 1;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
       
        
       
        
        
        if(str[i] == str[j] ){
            int l = solve(str,i+1,j);
            int r = solve(str,i,j-1);
            return dp[i][j] =   (1+l+r)%mod;
        }
        else{
            int a = solve(str,i+1,j);
            int b = solve(str,i,j-1);
            int c = solve(str,i+1,j-1);
            return dp[i][j] = (mod+a+b-c)%mod ;
        }
        
    }
    
    int  countPS(string str)
    {
       //Your code here
       memset(dp,-1,sizeof(dp));
       int n = str.size();
       return solve(str,0,n-1);
      
    }
     
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}  // } Driver Code Ends