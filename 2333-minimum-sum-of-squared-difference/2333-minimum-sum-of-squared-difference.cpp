# define ll long long int
int n = 1e5;

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) 
    {
        vector<ll>nums(n+1,0);
        int l = nums1.size();
        
        for(int i=0;i<l;i++)
        {
           nums[ abs(nums1[i]-nums2[i])]++;
        }
        
        int k = k1+k2;
        
        for(int i=n;i>0;i--)
        {
            if(nums[i]==0)continue;
            
            if(k>=nums[i])
            {
                k-=nums[i];
                nums[i-1]+=nums[i];
                nums[i]=0;
            }
            else
            {
                nums[i-1]+=k;
                nums[i]-=k;
                k=0;
                break;
            }
        }
        
        
        ll ans = 0;
        
        for(int i=1;i<=n;i++)
        {
            ans =  ans + (1LL*i*i*(nums[i]));
        }
        
        return ans;

        
    }
};