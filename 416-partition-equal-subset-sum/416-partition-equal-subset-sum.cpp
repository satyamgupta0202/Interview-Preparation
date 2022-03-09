class Solution {
public:
    
    bool solve(int sum , vector<int>&nums)
    {
        int n = nums.size();
        int dp[n+1][sum+1];
        for(int i=0;i<=sum;i++)dp[0][i]=false;
        for(int i=0;i<=n;i++)dp[i][0]=true;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(nums[i-1]>j)
                {
                    dp[i][j]=dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[n][sum];
    }
    
    
    bool canPartition(vector<int>& nums) 
    {
        int n = nums.size();
        int s=0;
        
        for(auto it: nums)s+=it;
        
        if(s%2)return false;
        
        return solve(s/2,nums);
        
    }
};