class Solution {
public:
    int numDecodings(string s) {
        
        int n = s.size();
        int dp[n+1];
        
//         check for invalid string directly
        if(s[0]=='0')return 0;
        
        
        
        for(int i=0;i<=n;i++)dp[i]=0;
        
        dp[0]=1;
        dp[1]=1;
        
        for(int i=2;i<=n;i++){
            
            int a = s[i-2]-'0';
            int b = s[i-1]-'0';
            
            int num = a*10+b;
            
            if(b!=0)dp[i]+=dp[i-1];
            if(num>=10 && num<=26)dp[i]+=dp[i-2];
            
        }
        
        return dp[n];
        
        
    }
};