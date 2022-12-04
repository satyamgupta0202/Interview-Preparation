class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        
        
        int n = nums.size();
        vector<long long>prefix(n,0);
        prefix[0] = nums[0];
        
        long long ans = INT_MAX;
        long long res = 0;
        long long sum = nums[0];
        
        for(int i = 1 ; i < n ; i++)
        {
            sum+=nums[i];
            prefix[i] = prefix[i-1]+nums[i];
        }
        
        if(n==1)return 0;
        for(int i=0;i<n;i++)
        {
            
            long long x = prefix[i];
            long long n1 = i+1;
            
            long long y = sum - x;
            long long n2 = n-i-1;
            long long temp;
            if(n2==0)
            {
                temp = sum/n;
            }
            else
            temp = abs( (x/n1) -  (y/n2) );
            
            if(temp<ans)
            {
                ans = temp;
                res = i;
            }
            
        }
        
        return res;
        
    }
};