class Solution {
public:
   int  dp[505][505];
    int solve(string s1 , int n1 , string s2 , int n2){
        
        if(n1==0)return dp[n1][n2] =n2;
        if(n2==0)return dp[n1][n2] =  n1;
        
        if(dp[n1][n2]!=-1)return dp[n1][n2];
        
        
        if(s1[n1-1] == s2[n2-1]){
            return dp[n1][n2] =  solve(s1,n1-1,s2,n2-1);
        }
        return dp[n1][n2] = 1+ min(
        
            solve(s1,n1-1,s2,n2-1) ,
            
           min( solve(s1,n1-1,s2,n2) , solve(s1,n1,s2,n2-1))
        
        );
        
    }
    
    
    int minDistance(string word1, string word2) {
        
        memset(dp,-1,sizeof(dp));
        
        int n1 = word1.size();
        int n2 = word2.size();
        return solve(word1,n1,word2,n2);
        
    }
};