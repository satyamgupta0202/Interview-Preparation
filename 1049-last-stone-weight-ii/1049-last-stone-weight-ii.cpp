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
        
        cout<<s<<endl;
 
        
      int ans = INT_MAX;
	    for(int i=0;i<=n;i++){
	        for(int j=0;j<=s/2;j++){
	            if(dp[i][j]){
	                ans = min (ans , s - 2*j);
	            }
	        }
	    }
        
        return ans;
        
        
        
        
    }
};