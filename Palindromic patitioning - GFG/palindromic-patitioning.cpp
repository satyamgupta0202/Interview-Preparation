// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[501][501];
    Solution(){
        memset(dp , -1 , sizeof(dp));
    }
    
    
    bool isPalindrome(int i,int j, string str){
        
        while(i<=j){
            if(str[i]==str[j]){
                i++;
                j--;
            }else{
                return false;
            }
        }
        return true;
        
        
    }
    
   
    
    int solve(int i , int j , string str){
        int ans = INT_MAX;
        if(i>=j)return 0;
        
        if(isPalindrome(i,j,str))return 0;
        
         if(dp[i][j]!=-1)return dp[i][j];
         
         for(int k=i;k<=j;k++){
             
             
           
             int left,right;
             if(dp[i][k]==-1){
                 left =  solve(i,k,str);
             }else{
                 left = dp[i][k];
             }
             
             if(dp[k+1][j]==-1){
                 right =  solve(k+1,j,str);
             }else{
                 right = dp[k+1][j];
             }
             
             ans = min(ans,left+right+1);
             dp[i][j]=ans;
             
             
         }
        
       return ans; 
        
    }
    
    int palindromicPartition(string str){
        // code here
        int n = str.size();
        return solve(0,n-1,str);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends