class Solution {
public:
    int dp[20][20];
    int solve(vector<int>&nums ,int low , int high) {
  
        
      if(low==high)return dp[low][high] =  nums[low];
        
      if(low>high)return  0;
        
        if(dp[low][high]!=-1)return dp[low][high];

        int o1 = nums[low] + min(solve(nums,low+2,high),solve(nums,low+1,high-1));
        int o2 = nums[high] + min(solve(nums,low,high-2),solve(nums,low+1,high-1));
        return dp[low][high] =  max(o1,o2);   
    }
    
    
    bool PredictTheWinner(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        
        int kk = solve(nums, 0 , nums.size()-1);
        if(kk >= sum-kk)return true;
        return false;
        
    }
};