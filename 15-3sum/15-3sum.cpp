class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            
            
            int tar = -(nums[i]);
            
            int low = i+1 , high = n-1;
            
            while(low<high){
                
                if(nums[low]+nums[high] > tar){
                    high--;
                }
                else if(nums[low]+nums[high]<tar){
                    low++;
                }
                else{
                    vector<int>temp={nums[low],nums[high],nums[i]};
                    ans.push_back(temp);
                    low++;high--;
                    while(low<high && nums[low]==temp[0])low++;
                    while(low<high && nums[high]==temp[1])high--;
                }
            } 
            while(i+1<n && nums[i]==nums[i+1])i++;
        }
        
        return ans;
    }
};



/**
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>>ans;
        sort(nums.begin() ,nums.end());
        int n = nums.size();
        
        for(int i=0;i<nums.size();i++){
            
            
            int target = -(nums[i]);
            
            int start = i+1;
            int end =  n-1;
            
            while(start<end){
                
                if(nums[start]+nums[end] > target){
                    end--;
                }
                
                else if(nums[start]+nums[end]<target){
                    start++;
                }
                
                else{
                    vector<int>t({nums[start],nums[end],nums[i]});
                  
                    ans.push_back(t);   
                    start++;
                    end--;
                    while(start<end && t[0] == nums[start])start++;
                    while(start<end && t[1] == nums[end])end--;
                }
                
                
            }
            
            while(i+1<n && nums[i]==nums[i+1])i++;
            
        }
        return ans;
        
        
    }
};
**/