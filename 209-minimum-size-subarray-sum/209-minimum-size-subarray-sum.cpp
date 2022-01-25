class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size();
        
        int i=0,j=0;
        int ans = INT_MAX;
        int temp = 0;
        while(j<n){
            
            temp += nums[j];
            
            while(temp>=target){

                ans = min(ans , j-i+1); 
                temp -= nums[i++];
                
            }
            
            // if(temp>=target){
            //     ans = min(ans, j-i+1);
            // }
            
            j++;
            
        }
        if(ans == INT_MAX)return 0;
        return ans;
        
    }
};