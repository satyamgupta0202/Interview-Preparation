class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            int tar = target - nums[i];
            
            if(mp.count(tar)!=0){
                return {i,mp[tar]};
            }
            else {
                mp[nums[i]]=i;
            }
            
        }
        return {};
    }
};


/** Naive approach 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n  = nums.size();
        for(int i=0;i<n;i++){
            
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j] == target){
                    return {i,j};
                }
            }
            
        }
        return {};
        
    }
};
**/