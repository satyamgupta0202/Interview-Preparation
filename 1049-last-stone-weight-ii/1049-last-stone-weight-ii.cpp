class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) 
    {
        int n = stones.size();
        int s = 0;
        for(auto it: stones)
        {
            s+=it;
        }
        bool dp[n+1][s+1];
        for(int i=0;i<=s;i++)dp[0][i]=false;
        for(int i=0;i<=n;i++)dp[i][0]=true;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=s;j++)
            {
                if(stones[i-1]>j)
                {
                    dp[i][j]=dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-stones[i-1]];
                }
            }
        }


      int ans = INT_MAX;
	  for(int i=s/2;i>=0;i--)
      {
          if(dp[n][i])
          ans = min(ans ,  s-2*i  );
      }
        
        return ans;
        
        
        
        
    }
};