// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        int ans = 0;
        int p = -1 ,q=-1;
        bool dp[n][n];
        
        memset(dp , false, sizeof(dp));
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                if(s[i] == s[j])
                {
                    if(j-i==1 || j-i==0 || dp[i+1][j-1])
                    {
                        dp[i][j] = true;
                        if(j-i+1>=ans)
                        {
                            ans = j-i+1;
                            p = i;
                            q = j;
                        }
                    }
                }
            }
        }
        
        return s.substr(p , ans);
        
    }
};

// { Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends