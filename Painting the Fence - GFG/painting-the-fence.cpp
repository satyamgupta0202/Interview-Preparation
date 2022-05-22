// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long countWays(int n, int k)
    {
        long long mod = 1e9+7;
        if(n==1)return k;
        
        long long a = k;
        long long b = (k*(k-1));
        long long tot = a+b;
        
        for(int i=3;i<=n;i++)
        {
            a = b;
            b = ((tot%mod)*(k-1));
            
            tot = a+b;
            
            
        }
        return tot%mod;
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends