class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //Divide and Conquer
        int low = 0 , high = nums.size()-1;
        int n = nums.size();
        if(n==1)return 0;
        if(nums[0]>nums[1])return 0;
        if(nums[n-1]>nums[n-2])return n-1;
        
        
        while(low<=high)
        {
            int mid = low + (high-low)/2;
       
            
            if(mid>0 && mid<nums.size() && nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            
            else if(nums[mid+1]>nums[mid]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
       return 0; 
    }
};