// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	    int mod = 1e9+7;
		int nthPoint(int n){
		    // Code here
		    int dp[n+1]={0};
		    dp[0]=1;
		    
		    for(int i=1;i<=n;i++){
		        for(int j=1;j<=2;j++){
		            if(j>i){
		                dp[i]=dp[i-1]%mod;
		            }else{
		                dp[i] = dp[i]%mod + dp[i-j]%mod;
		            }
		        }
		    }
		    return dp[n]%mod;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends