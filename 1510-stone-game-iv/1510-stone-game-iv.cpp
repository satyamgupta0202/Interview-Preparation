class Solution {
public:
   
    
    bool winnerSquareGame(int n) {
     
    bool dp[n+1];
    memset(dp,false,sizeof(dp));
        
    dp[0]=false;
    //dp[1]=true;

    for(int i=0;i<=n;i++){

        if(dp[i])continue ;
         // we will start from faulsi , and try to jump over the squares of the number 

        for(int j=1;i+j*j<=n;j++){
            dp[i+j*j]=true;
        }
    }
   return dp[n];
    }
};