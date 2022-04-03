class Solution {
public:
    
    long long solve(vector<int>&c , long long tof)
    {
        // if(tof==0)return 0;
        long long p=0;
        
        for(auto &val : c)
        {
            long long x = val;
            p += x/tof;
        }
            
        
        return p;
    }
    
    
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
            long long p = solve(c,mid);
            
            // cout << mid << "\n";
            if(mid == 1) cout << p << "\n";
            
            // cout << p << "\n";
            
            
            if(p>=k)
            {
                // cout << low << " " << high << " " << mid << "\n";
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