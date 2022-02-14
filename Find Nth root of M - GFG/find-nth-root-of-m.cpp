// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	
	int check(int num, int n, int m) {
	    unsigned long long ans = 1;
	    for (int i = 1; i <= n; i++) {
	        ans *= num;
	        // To avoid overload
	        if (ans > m)
	            return m+2;
	    }
	    return (int)ans;
	}
	
	
	int NthRoot(int n, int m)
	{
	    if(n==1 || m==1)return m;
	    
	    int low = 0 , high = m/n;
	    
	    while(low<=high){
	        
	        int mid = low + (high-low)/2;
	        
	        if(check(mid,n,m) == m)return mid;
	        
	        else if(check(mid,n,m)>m ){
	            high=mid-1;
	        }
	        else{
	            low=mid+1;
	        }
	    }
	    return -1;
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
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends