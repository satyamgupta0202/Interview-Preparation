class Solution {
public:
    int ans = 0;
    
    int solve(vector<int>v1 , vector<int>v2)
    {
        int n1 = v1.size() , n2 = v2.size();
        int dp[n1+1][n2+1];
        
        memset(dp,0,sizeof(dp));
        
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(v1[i-1]==v2[j-1])
                {
                    dp[i][j] = 1+dp[i-1][j-1];
                    ans = max(ans , dp[i][j]);
                }
                else
                {
                    dp[i][j]=0;
                }
            }
        }
        
        return ans;
        
        
    }
    
    int findLength(vector<int>& nums1, vector<int>& nums2)
    {
        return solve(nums1,nums2);
        
    }
};