class Solution {
public:
    int dp[1000][1000];
    int solve(int i , int j , vector<int>&nums,int left ,int right)
    {
        int ans = INT_MIN;
        
        if(i==j) return dp[i][j] = nums[i]*left*right;
        
        if(i>j)return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        for(int k=i;k<=j;k++)
        {
                int temp = solve(i,k-1,nums,left,nums[k]) + solve(k+1,j,nums,nums[k],right) +                                               nums[k]*left*right;
                ans = max(ans , temp);
              dp[i][j]=ans;
        }
        return ans;
    }
    
    
    int maxCoins(vector<int>& nums)
    {
        memset(dp,-1,sizeof(dp));
        int n = nums.size();
        return solve(0,n-1,nums,1,1);
    }
};