// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int dp[1005][1005];
	int solve(string s1 , string s2 , int x , int y , int i , int j) {
	    
	    if(i==s1.size() || j==s2.size()){
	        
	        int sum = 0;
	        for(int p=i;p<s1.size();p++){
	            sum+=x;
	        }
	        for(int p=j;p<s2.size();p++){
	            sum+=y;
	        }
	        return sum;
	    }
	    if(dp[i][j]!=-1)return dp[i][j];
	    
	    if(s1[i]==s2[j]){
	        return dp[i][j] =  solve(s1,s2,x,y,i+1,j+1);
	        
	    }
	    else{
	        int k1 = x+ solve(s1,s2,x,y,i+1,j);
	        int k2 = y+ solve(s1,s2,x,y,i,j+1);
	        return dp[i][j] = min(k1,k2);
	    }
	    
	    
	}
	
	int findMinCost(string X, string Y, int costX, int costY)
	{
	    // Your code goes here
	    memset(dp,-1,sizeof(dp));
	    return solve(X,Y,costX,costY,0,0);
	    
	}
  

};
	

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