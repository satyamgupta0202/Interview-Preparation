class Solution {
public:
    
    int solve(string s1  , string s2) {
        
        int n1 = s1.size() , n2 = s2.size();
        
        int dp[n1+1][n2+1];
        for(int i=0;i<=n1;i++){
            for(int j=0;j<=n2;j++){
                
                if(i==0){
                    dp[i][j]=j;
                }
                else if(j==0){
                    dp[i][j]=i;
                }
                
                else if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1+min(  dp[i-1][j-1] , min(dp[i-1][j] ,dp[i][j-1]));
                }
                
            }
        }
        return dp[n1][n2];
        
    }
    
    int minDistance(string word1, string word2) {
        return solve(word1,word2);
    }
};