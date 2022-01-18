// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[1002][1002][2];
    int solve(string s , int i ,int j , bool istrue){
        
        if(i>j)return 0;
        
        if(i==j){
            if(istrue){
                return dp[i][j][istrue] =  (s[i]=='T');
            }else{
                return dp[i][j][istrue] =  (s[i]=='F');
            }
        }
        if(dp[i][j][istrue]!=-1)return dp[i][j][istrue];
        int ans = 0;
        for(int k=i+1;k<=j-1;k=k+2){
            int lt = solve(s,i,k-1,true);
            int lf = solve(s,i,k-1,false);
            int rt = solve(s,k+1,j,true);
            int rf = solve(s,k+1,j,false);
            
            if(s[k]=='&'){
                if(istrue){
                    ans+= lt*rt;
                }else{
                    ans+= lt*rf + lf*rt + lf*rf;
                }
            }
            else if(s[k]=='|'){
                if(istrue){
                    ans+= lt*rt + lf*rt + rf*lt;
                }else{
                    ans+= lf*rf;
                }
            }
            else if(s[k]=='^'){
                if(istrue){
                    ans+= lt*rf + rt*lf;
                }else{
                    ans+= lt*rt + rf*lf;
                }
            }
        }
        
        return dp[i][j][istrue] =  ans%1003;
        
    }


    int countWays(int N, string S){
        // code here
        memset(dp,-1,sizeof(dp));
        bool istrue = true;
        return solve(S,0,N-1,true);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends