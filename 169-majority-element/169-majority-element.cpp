class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
//         Voting Algorithm
        int cnt = 0 ,ans = 0;
        
        for(int i=0;i<nums.size();i++){
            
            if(cnt==0)
            {
                ans = nums[i];
            }
            if(ans == nums[i])
            {
                cnt++;
            }
            else{
                cnt--;
            }
            
        }
        return ans;
        
    }
};




/**

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1)return nums[0];
        int cnt = 0;
        int ans = 0;
        int res = nums[0];
        sort(nums.begin(),nums.end());
       // for(auto it: nums)cout<<it;
        for(int i=0;i<n;i++){
            
            if(i+1<n && nums[i]==nums[i+1]){
                cnt++;
            }
            else{
                if(cnt>ans){
                    ans = cnt;
                    res = nums[i];  
                    cout<<res;
                }
                  cnt=0;
            } 
        }
        if(ans>=floor(n/2))
        return res;
        return 0;
    }
};
**/