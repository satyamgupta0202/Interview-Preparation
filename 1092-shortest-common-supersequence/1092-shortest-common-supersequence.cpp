class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        
        int n1 = str1.size(),n2=str2.size();
        int dp[n1+1][n2+1];
        for(int i=0;i<=n1;i++){
            for(int j=0;j<=n2;j++){
                dp[i][j]=0;
            }
        }
        
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        
        int i=n1,j=n2;
        string ans="";
        while(i>0 && j>0){
            
            if(str1[i-1]==str2[j-1]){
                ans.push_back(str1[i-1]);
                    i--;
                    j--;
            }else{
                if(dp[i-1][j]>dp[i][j-1]){
                    ans.push_back(str1[i-1]);
                    i--;
                }else{
                    ans.push_back(str2[j-1]);
                    j--;
                }    
            }  
        }
        
        while(i>0){
            ans.push_back(str1[i-1]);
            i--;
        }
        while(j>0){
            ans.push_back(str2[j-1]);
            j--;
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
        
    }
};