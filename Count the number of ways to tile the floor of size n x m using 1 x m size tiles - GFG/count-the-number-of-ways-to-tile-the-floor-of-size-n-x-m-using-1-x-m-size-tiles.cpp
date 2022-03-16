// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
	public:
	int countWays(int n, int m)
	{
	    // Code here.
	   long long mod = 1e9+7;
	  int dp[n+1];
	  dp[0]=0;
	  dp[1]=1;
	  for(int i=2;i<=n;i++)
	  {
	      if(i<m)dp[i]= 1;
	      
	      if(i==m)dp[i]=2;
	      
	      if(i>m)
	      dp[i]=(dp[i-1]%mod+dp[i-m]%mod)%mod;
	  }
	  
	  return dp[n]%mod;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.countWays(n, m);
		cout << ans <<"\n";
	}  
	return 0;
}  // } Driver Code Ends