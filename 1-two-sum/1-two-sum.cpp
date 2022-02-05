class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int,int>mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
        }
        
        for(int i=0;i<n;i++){
            
            int tar = target-nums[i];
            if(tar!=nums[i]){
                if(mp.count(tar)!=0){
                    return {i,mp[tar]};
                }
            }
            
        }
        int p=-1,q=-1;
        bool ok1=true,ok2=true;
        if(target%2==0){
            for(int i=0;i<n;i++){
                if(nums[i]==target/2 && ok1){
                    ok1=false;
                    p=i;
                }
                else if(nums[i]==target/2 && ok2){
                    q=i;
                    ok2=false;
                }
            }
        }
        if(p!=-1 && q!=-1){
            return {p,q};
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