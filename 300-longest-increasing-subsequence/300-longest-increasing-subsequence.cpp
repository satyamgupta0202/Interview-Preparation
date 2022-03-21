class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();    
        vector<int>dp(n+1,INT_MAX);
        dp[0]=INT_MIN;
        for(int i=0;i<n;i++)
        {    
            auto it = upper_bound(dp.begin(),dp.end() , nums[i]);
            
            auto k = it;
            
            k--;
            
            if(*k != nums[i])
            {
                *it = nums[i];
            }
         }
        
           for(int i=n;i>0;i--)
            {
                if(dp[i]!=INT_MAX)
                {
                    return i;
                }
            }
        
        return -1;
            
        
    }
};


//o(N^2)
/**
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        // (o(N^2))
        int n = nums.size();
        int dp[n];
        memset(dp,0,sizeof(dp));
        
        dp[0]=1;
        
        for(int i=1;i<n;i++)
        {
            dp[i]=1;
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j] && dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                }
            }
        }
        
        return *max_element(dp,dp+n);
    }
};
**/