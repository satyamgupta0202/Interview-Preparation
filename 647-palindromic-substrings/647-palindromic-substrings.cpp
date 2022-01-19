class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        bool dp[n][n];
        int cnt=0;
        
       // for(int i=0;i<n;i++)dp[i][i]=1;
        
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){

                    if(s[i]==s[j]){
                        if(j==i ||j-i==1 || dp[i+1][j-1] ){
                            dp[i][j]=true;
                        }else{
                            dp[i][j]=false;
                        }
                    }else{
                        dp[i][j]=false;
                    }
    
               if(dp[i][j])cnt++; 
            }
        }
        return cnt;
    }
};