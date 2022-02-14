class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
     
        int n = nums.size();
        if(n==1)return nums[0];
        if(nums[n-1]!=nums[n-2])return nums[n-1];
        if(nums[0]!=nums[1])return nums[0];
        int low = 0 , high = nums.size()-1;  
        
        
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            bool ok = (high-mid)%2==0;
            
            if(mid>0 && mid<n-1 && nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1])
            {
                return nums[mid];
            }
            
            else if(nums[mid]==nums[mid+1])
            {
                cout<<nums[mid]<<" "<<mid<<high<<endl;
                
                if(ok)
                {
                    low = mid+2;
                }
                else
                {
                    high=mid-1;
                    
                }
            }
            
            else
            {
                cout<<nums[mid]<<endl;
                
                if(ok)
                {
                    high = mid-2;
                }
                else
                {
                    low=mid+1;
                }
            }    
        }
        
        return nums[low];
    }
};