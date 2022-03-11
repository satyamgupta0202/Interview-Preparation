class Solution {
public:
    int jump(vector<int>& nums) 
    {
        int n = nums.size();
        int dp[n];
        memset(dp,1000000,sizeof(dp));
        
        dp[0]=0;
        for(int i=0;i<n;i++)
        {
            int jmp = nums[i];
            for(int j=1;j<=jmp && j+i<n ; j++)
            {
                dp[j+i] = min(dp[j+i] , dp[i]+1);
            }
        }
        
        for(int i=0;i<n;i++)
            cout<<dp[i]<<" ";
        
        return dp[n-1];
    }
};