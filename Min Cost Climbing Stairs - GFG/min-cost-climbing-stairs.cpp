// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Back-end complete function Template for C++
/**
int dp[1004];
  
    int solve(vector<int> & cost, int index, int n) {   
        if(index >= n) {
            return 0; 
        }
        if(dp[index] != -1) {
            return dp[index];  
        }
        return dp[index] = min(cost[index] + solve(cost, index+1, n), cost[index] + solve(cost, index + 2, n));
    }
    int minCostClimbingStairs(vector<int>&cost ,int N) { 
        memset(dp, -1, sizeof(dp));  
        return min(solve(cost, 0, N), solve(cost, 1, N));
    }

 * **/
 
class Solution {
  public:
    int dp[1005];
    
    Solution(){
        memset(dp,-1,sizeof(dp));
    }
    
    int solve(vector<int>cost , int n) {
        
        if(n==0)return 0;
        
        if(n<0)return 0;
        
        //take 
        if(dp[n] !=-1)return dp[n];
        
         return dp[n] =  cost[n-1] + min(solve(cost,n-1) , solve(cost,n-2)) ;
        
        
        
        
    }
  
    int minCostClimbingStairs(vector<int>&cost ,int N) {
        //Write your code here
        // reverse(cost.begin(),cost.end());
        
        int t1 =  solve(cost,N);
        int t2 = solve(cost , N-1);
        return min(t1,t2);
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>cost(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>cost[i];
        }

        Solution ob;
        cout<<ob.minCostClimbingStairs(cost,N);
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends