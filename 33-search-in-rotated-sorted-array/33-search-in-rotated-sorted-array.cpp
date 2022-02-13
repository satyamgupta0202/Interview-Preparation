class Solution {
public:
    
    int solve(vector<int>&nums,int low , int high,int target)
    {
        if(nums[low]>target)return -1;
        if(nums[high]<target)return -1;
        while(low<=high)
        {
            int mid = low+ (high-low)/2;
            
            if(nums[mid]==target)return mid;
            
            else if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int low = 0 , high = nums.size()-1;
        int temp=-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            
            if(mid+1< n && nums[mid+1]<nums[mid]){
                temp=mid+1;
                break;
            }
            else if(mid-1>=0 && nums[mid-1]>nums[mid]){
                temp=mid;
                break;
            }
            
            else if(nums[mid]>nums[low]){
                 low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        
        
        if(temp!=-1 && nums[temp]==target)return temp;
        
        low=0;
        high=n-1;
        if(temp==-1){
            return solve(nums,low,high,target);
        }
        int p=-1,q=-1;
        if(temp-1>=0)
        p = solve(nums,low,temp-1,target);
        if(temp+1<n)
         q = solve(nums,temp+1,high,target);
        
        if(p!=-1)return p;
        if(q!=-1)return q;
        return -1;
        
        
        
        
    }
};