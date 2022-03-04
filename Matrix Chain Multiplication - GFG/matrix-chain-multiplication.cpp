// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[1001][1001];
    
    Solution(){
        memset(dp, -1, sizeof(dp));
    }
    
    int solve(int arr[] , int i , int j,int n){
        
        int ans = INT_MAX;
        
        if(i>=j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        
        
        
        for(int k=i;k<=j-1;k++){
            
          int temp = solve(arr,i,k,n) + solve(arr,k+1,j,n) + arr[i-1]*arr[k]*arr[j];
         
          ans = min(ans,temp);
          dp[i][j] = ans;
        }
        
        return ans;
       
        
    }


    int matrixMultiplication(int N, int arr[]){
        // code here
        int ans = 0 ;
        //pass from indx =1;
        return solve(arr,1,N-1,N);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends