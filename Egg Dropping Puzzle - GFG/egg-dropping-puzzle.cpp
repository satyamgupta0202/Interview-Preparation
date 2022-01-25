// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
   int dp[205][205];
   Solution(){
       memset(dp,-1,sizeof(dp));
   }
  int solve(int egg , int f) {
      
      int ans = INT_MAX;
      if(egg==1){
         return  dp[egg][f] = f;
      }

      
      if(f==0 || f==1){
          return dp[egg][f] =  f;
      }
      
      if(dp[egg][f]!=-1)return dp[egg][f];
      
      
      for(int k=1;k<=f;k++){
          
          int t1= solve(egg-1 , k-1);
          int t2 = solve(egg , f-k);
          
          int t = 1 + max(t1,t2);
          ans = min(ans,t);
          dp[egg][f]= ans;
      }
      return ans;
      
      
  }
    
    int eggDrop(int n, int k) {
       
       
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