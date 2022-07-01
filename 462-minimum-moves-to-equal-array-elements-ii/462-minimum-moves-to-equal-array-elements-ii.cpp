class Solution {
public:
    
    
    int solve(int tar , vector<int>& nums)
    {
        int cnt = 0;
        
        for(auto it: nums)
        {
            cnt+= (abs(it-tar));
        }
        return cnt;
    }
    
    
    int minMoves2(vector<int>& nums) 
    {
        int n = nums.size();
        if(n==1)return 0;
        sort(nums.begin() , nums.end());
        
        int s = 0;
        
//         for(auto it: nums)
//         {
//             s+=it;
//         }
        
//         int temp1 = s/(n-1);
//         int temp2 = s/(n+1);
        int ans = INT_MAX;
        
        int temp1 = nums[n/2];
        int temp2 = nums[(n/2) -1];
        
        for(int i=temp2;i<=temp1;i++)
        {
            int k = solve(i,nums);
            ans = min(ans, k);
        }
        
        
        return ans;
        
    }
};