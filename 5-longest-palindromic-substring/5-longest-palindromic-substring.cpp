class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.size();
        bool dp[n][n];
        memset(dp,false,sizeof(dp));
        int ans = 0;
        
        string k = "";
        
        for(int i=n-1;i>=0;i--){
            
            for(int j=n-1;j>=i && j<n ;j--){
                
                if(s[i]==s[j]){
                    
                    if(i==j || i+1==j || dp[i+1][j-1]){
                        dp[i][j]=true;
                        
                        if(ans< j-i+1){
                            ans = j-i+1;
                            k = s.substr(i,j-i+1);
                        }
                    }     
                } 
            } 
        }
        return k;   
    }
};