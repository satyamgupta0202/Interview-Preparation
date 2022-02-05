class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        set<vector<int>>s;
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            for(int j = i+1;j<n;j++){
                
                int tar = target - nums[i] - nums[j];
                
                int low = j+1 , high = n-1;
                
                while(low<high){
                    
                    if(nums[low] + nums[high] > tar){
                        high--;
                    }
                    else if(nums[low]+nums[high]<tar){
                        low++;
                    }
                    else{
                        vector<int>p={nums[i],nums[j],nums[low],nums[high]};
                        s.insert(p);
                        low++;
                        high--;
                    }
                    
                }
                
                
            }
        }
        for(auto it:s)
        {
            ans.push_back(it);
        }
        return ans;
    }
};