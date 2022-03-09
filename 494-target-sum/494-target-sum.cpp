class Solution {
public:
    
    int cnt = 0;
    
    void solve(int target , int i , vector<int>&nums , long long k)
    {
        if(i==nums.size())
        {
            if(target==k)cnt++;
            else return;
        }
        
        if(i>=nums.size())return ;
        
        solve(target,i+1,nums,k-nums[i]);
        solve(target,i+1,nums,k+nums[i]);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int n = nums.size();
        long long k=0;
        solve(target , 0 , nums ,k);
        
        return cnt;
    }
};