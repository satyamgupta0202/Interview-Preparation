// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	
	    int solve(int n) {
	        int dp[3][n+1];
	        for(int i=0;i<=n;i++){
	            dp[0][i]=0;
	        }
	        for(int i=0;i<=2;i++){
	            dp[i][0]=1;
	        }
	        dp[0][0]=0;
	        
	        for(int i=1;i<=2;i++){
	            for(int j=1;j<=n;j++){
	                
	                if(i>j){
	                    dp[i][j]=dp[i-1][j];
	                }else{
	                    dp[i][j] =(dp[i-1][j]+dp[i][j-i]); 
	                }
	            }
	        }
	        return dp[2][n];
	    }
	
	
		int nthStair(int n){
		    //  Code here
		    return solve(n);
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
		int ans  = ob.nthStair(n);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends