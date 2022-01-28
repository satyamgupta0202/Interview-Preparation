class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        
        if(n==0)return 1;
        if(n==1)return 10;
        
        long dp[n+1];
        
        dp[1]=10;
        
        int pro = 9;
        int k=9;
        for(int i=2;i<=n;i++){
            
            pro = pro*k;
            dp[i] = dp[i-1]+pro;
            k--;
        }
        
        
       return dp[n];
    }
};