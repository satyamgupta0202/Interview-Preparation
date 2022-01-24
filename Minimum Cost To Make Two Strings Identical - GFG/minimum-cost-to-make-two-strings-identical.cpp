// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	
	int findMinCost(string X, string Y, int costX, int costY)
	{
	    int n = X.size(), m = Y.size();
	    vector <vector<int>> dp(n+1, vector <int> (m+1, 0));
	    for(int i=0; i<=n; i++)
	        dp[i][0] = i*costX;
	    for(int i=0; i<=m; i++)
	        dp[0][i] = i*costY;
	    for(int i=1; i<=n; i++){
	        for(int j=1; j<=m; j++){
	            if(X[i-1] == Y[j-1])
	                dp[i][j] = dp[i-1][j-1];
	            else
	                dp[i][j] = min(costX + dp[i-1][j], costY + dp[i][j-1]);
	        }
	    }
	    return dp[n][m];
	}
  

};

  // if(i==s1.size() || j==s2.size()){
	        
	   //     int sum = 0;
	   //     for(int p=i;p<s1.size();p++){
	   //         sum+=x;
	   //     }
	   //     for(int p=j;p<s2.size();p++){
	   //         sum+=y;
	   //     }
	   //     return sum;
	   // }
	   // if(dp[i][j]!=-1)return dp[i][j];
	    
	   // if(s1[i]==s2[j]){
	   //     return dp[i][j] =  solve(s1,s2,x,y,i+1,j+1);
	        
	   // }
	   // else{
	   //     int k1 = x+ solve(s1,s2,x,y,i+1,j);
	   //     int k2 = y+ solve(s1,s2,x,y,i,j+1);
	   //     return dp[i][j] = min(k1,k2);
	   // }
	

// { Driver Code Starts.
int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
       	string x, y;
       	cin >> x >> y;
        
       	int costX, costY;
       	cin >> costX >> costY;

        

        Solution ob;
        cout << ob.findMinCost(x, y, costX, costY);
	    cout << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends