class Solution {
public:
    bool isMatch(string str, string pattern) {
        
       int n = pattern.size();
        int m = str.size();
        bool dp[n+1][m+1];
        
        for(int i=n;i>=0;i--){
            for(int j=m;j>=0;j--){
                
                if(i==n && j==m){
                    dp[i][j]=true;
                }
                
                
                else if(i==n){
                    dp[i][j]=false;
                }
                
                
                else if(j==m){
                    if(pattern[i]=='*'){
                        dp[i][j]=dp[i+1][j];
                    }else{
                        dp[i][j]=false;
                    }
                }
                
                else{
                    
                   if(pattern[i] =='*'){
                    
                    dp[i][j] = (dp[i+1][j] || dp[i][j+1]);
                    
                     }
                     
                   else if(pattern[i]=='?'){
                    dp[i][j]=dp[i+1][j+1];
                  }
                  
                  
                      
                    else if(pattern[i]==str[j]){
                        dp[i][j]=dp[i+1][j+1];
                    }else{
                        dp[i][j]=false;
                    }
                }
                
                
          }
        }
        
        return dp[0][0];
        
    }
};