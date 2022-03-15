// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int TotalWays(int n)
	{
	    // Code here
	    long long mod  = 1e9+7;
	    long long o=1;
	    long long z=1;
	    
	    for(int i=2;i<=n;i++)
	    {
	        int nz = o%mod;
	        int no = (o%mod+z%mod)%mod;
	        
	        z=nz%mod;
	        o=no%mod;
	       
	    }
	    
	    return ((o+z)%mod*(o+z)%mod)%mod;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends