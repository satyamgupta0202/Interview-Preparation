// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	
	    int LCS(string s1 , string s2){
	        
	        int n = s1.size();
	        int dp[n+1][n+1];
	        int ans = 0;
	        for(int i=0;i<=n;i++){
	            for(int j=0;j<=n;j++){
	                if(i==0 || j==0)
	                dp[i][j]=0;
	            }
	        }
	        
	        for(int i=1;i<=n;i++){
	            for(int j=1;j<=n;j++){
	                if(s1[i-1]==s2[j-1] && i!=j){
	                    dp[i][j]=dp[i-1][j-1]+1;
	                   
	                }else{
	                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
	                }
	            }
	        }
	        
	        return dp[n][n];
  
	    }
	    
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    string s1 = str;
		   // reverse(str.begin(),str.end());
		    string s2 = str;
		    int k = LCS(s1,s1);
		    return k;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends