class Solution {
public:
    int dp[2001][2001];
    
    int solve(string s1,string s2){
        
    int n1 = s1.size() , n2 = s2.size();
    int dp[n1+1][n2+1];
    memset(dp,0,sizeof(dp));

    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){

            if(s1[i-1]==s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + int(s1[i-1]);
            }
            else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }

        }
    }
   
   int sum = 0;
   for(int i=0;i<s1.size();i++)sum+=int(s1[i]);
   for(int i=0;i<s2.size();i++)sum+=int(s2[i]);
   return sum - 2*dp[n1][n2];
          
    }
    
    
    int minimumDeleteSum(string s1, string s2) {
      
       
        return solve(s1,s2);        
    }
};