// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int dp[300][300];
    
    Solution(){
            memset(dp,-1,sizeof(dp));
           };
    
    int solve(int e , int f) 
    {
        
        if(e==1)return f;
        
        if(f==0 || f==1)return f;
        
        if(dp[e][f]!=-1)return dp[e][f];
        
        int ans = INT_MAX;
        
        for(int k=1;k<=f;k++)
        {
            int t1 = solve(e-1,k-1);
            int t2 = solve(e,f-k);
            
            int temp = 1 + max(t1,t2);
            
            ans = min(ans,temp);
        }
        
        return dp[e][f] =  ans;
        
    }
    
    int eggDrop(int n, int k) 
    {
        // your code here
        return solve(n,k);
        
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends