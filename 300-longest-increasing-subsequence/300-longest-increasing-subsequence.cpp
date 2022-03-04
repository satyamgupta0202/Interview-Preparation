class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        
        int d[n+1];
        for(int i=0;i<=n;i++)
        {
            d[i]=INT_MAX;
        }
        d[0]=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            auto it = upper_bound(d,d+n+1,nums[i]);
            auto k = it;
            k--;
            if(*k != nums[i])
            *it = nums[i];
        }
        
        for(int i=n;i>0;i--)
        {
            if(d[i]!=INT_MAX)
            {
                return i;
            }
        }
        
        return -1;
        
    }
};