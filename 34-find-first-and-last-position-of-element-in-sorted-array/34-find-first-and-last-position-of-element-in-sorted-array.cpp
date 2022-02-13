class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      
        int n = nums.size();
        int first=-1,last=-1;
        int f1=0,l1=n-1,f2=0,l2=n-1;
        
        while(f1<=l1){
            int mid = f1+(l1-f1)/2;
            
            if(nums[mid]==target){
                first=mid;
                l1=mid-1;
            }
            else if(nums[mid]>target){
                l1=mid-1;
            }
            else{
                f1=mid+1;
            }  
        }
        ///
        while(f2<=l2){
            int mid = f2+(l2-f2)/2;
            
            if(nums[mid]==target){
                last=mid;
                f2=mid+1;
            }
            else if(nums[mid]>target){
                l2=mid-1;
            }
            else{
                f2=mid+1;
            }  
        }
        
        return {first,last};
      
    }
};