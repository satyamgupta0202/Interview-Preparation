// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        // code here
        long long mod = 1e9+7;
        int dp[n+1]={0};
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        dp[3]=4;
        
        for(int i=4;i<=n;i++)
        {
            dp[i]= ((i-1)%mod*dp[i-2]%mod +(dp[i-1]%mod))%mod;
        }
        
        return dp[n];
        
    }
};    
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends