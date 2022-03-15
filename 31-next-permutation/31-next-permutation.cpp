class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size() , k , l;
        
        //step:1 find first index k such that , nums[k]<nums[k+1] 
        for(k=n-2;k>=0;k--){
            if(nums[k+1]>nums[k]){
                break;
            }
        }
        
        //if k is negative array is sorted so reverse and return .
        if(k<0)reverse(nums.begin(),nums.end());
        
        //gind l such that nums[l]>nums[k] ... l>=k
        else{
            for(l=n-1;l>k;l--){
                if(nums[l]>nums[k])break;
            }
        //swap nums[l],nums[k]
        swap(nums[l],nums[k]);
            
        //reverse all nums from k+1 to end 
        reverse(nums.begin()+k+1,nums.end());
        }
    }
};