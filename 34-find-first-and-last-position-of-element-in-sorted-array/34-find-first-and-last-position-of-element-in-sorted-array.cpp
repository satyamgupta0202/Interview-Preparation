class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int low = 0 , high = nums.size()-1;
        int p=-1,q=-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            
            if(nums[mid]==target)
            {
                p = mid;
                q=mid;
                while(p-1>=0 && nums[p-1]==target ){
                    p--;
                }
                while(q+1<nums.size() && nums[q+1]==target ){
                    q++;
                }
                
                return {p,q};
                
               
            }
            else if(nums[mid]>target)
            {
                high = mid-1;
            }
            else
            {
                low=mid+1;
            }    
        }
        return {p,q};
        
        
        
    }
};