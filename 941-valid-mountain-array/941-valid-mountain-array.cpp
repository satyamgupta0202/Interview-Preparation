class Solution {
public:
    bool validMountainArray(vector<int>& nums) {
        
        int n = nums.size();
        
        int i=0;
        int c1=0,c2=0;

        while(i+1<n){
            if(nums[i+1]>nums[i]){
                i++;
                c1++;
            }else{
                break;
            }
        }
        
        while(i+1<n){
             if(nums[i+1]>=nums[i]){
                 return false;
             }else{
                 c2++;
             }
            i++;
        }
        if(c1&&c2)
        return true;
        return false;
        
       
        
    }
};