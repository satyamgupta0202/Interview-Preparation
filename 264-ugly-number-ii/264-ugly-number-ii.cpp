class Solution {
public:
    int nthUglyNumber(int n) 
    {
        int dp[n+1];
        dp[0]=1;
        long i2=0,i3=0,i5=0;
        long n2=2,n3=3,n5=5;
        
        for(int i=1;i<=n;i++)
        {
            int k = min(n2, min(n3,n5));
            cout<<k<<" ";
            dp[i]=k;
            
            if(k==n2)
            {
                 i2++;        
                n2=(long)2*dp[i2];
       
            }
            
            if(k==n3)
            {
                i3++;  
                n3=(long)3*dp[i3];
              
            }
            if(k==n5)
            {
                 i5++; 
                n5=(long)5*dp[i5];
              
            }
        }
        return dp[n-1];   
    }
};