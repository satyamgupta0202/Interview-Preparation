class Solution {
public:
    
    int maximumCandies(vector<int>& c, long long k) 
    {
        long long low = 1 , high = 1e9;
        long long ans =0;
        
        long long sum = accumulate(c.begin(),c.end(),0LL);
        
        if(sum < k)
            return 0;
        
        
        while(low<=high)
        {
            long long mid = low + ((high-low)/2);
            
            long long p=0;
        
            for(auto &val : c)
            {
                long long x = val;
                p += x/mid;
            }
            
            
            if(p>=k)
            {
                low=mid+1;
                ans=max(ans,mid);
            }
            else
            {
                high=mid-1;
            }
        }
        
        return ans;
    }
};