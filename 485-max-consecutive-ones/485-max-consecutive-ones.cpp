class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        
        nums.push_back(-1);
        int n = nums.size();
        int cnt = 0 , ans = 0;
        
        for(int i=0;i<n;i++){
            
            if(nums[i]==1)
            {
                cnt++;
            }
            else
            {
                ans = max(ans, cnt);
                cnt = 0;
            }
        }
        return ans;
    }
};