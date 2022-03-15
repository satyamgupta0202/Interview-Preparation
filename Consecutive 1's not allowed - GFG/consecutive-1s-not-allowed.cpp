// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	 #define ll long long
     ll mod = 1e9+7;
	ll countStrings(int n) 
	{
	    // code here
        ll z=1,o=1;
        
        for(ll i=2;i<=n;i++)
        {
            ll nz = (z%mod+o%mod);
            ll no = z%mod;
            
            z=nz;
            o=no;
        }
        
        return (o%mod+z%mod)%mod;
	    
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends