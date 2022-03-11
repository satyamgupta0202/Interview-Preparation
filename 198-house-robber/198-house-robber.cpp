class Solution {
public:
    int rob(vector<int>& nums) 
    {
        // 2 1 1 2
        int n = nums.size();
        int ans = 0 , t1=0, t2=0;
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        int dp[n];
        memset(dp,0,sizeof(dp));
        dp[0]=nums[0];
        dp[1]=nums[1];
        dp[1] = max(dp[0],dp[1]);
        for(int i=2;i<n;i++)
        {
            dp[i] = nums[i] + dp[i-2];
            dp[i] = max(dp[i],dp[i-1]);
        } 
        return dp[n-1];  
    }
};