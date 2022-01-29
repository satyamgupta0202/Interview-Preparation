class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        

        int n = nums.size();
        if(n<3)return 0;
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0]=0;
        dp[1]=0;
        dp[2]=0;
        
        for(int i=3;i<=n;i++){
            
            int c = nums[i-1];
            int b = nums[i-2];
            int a = nums[i-3];
            
            if(2*b == a+c){
                dp[i] = dp[i-1]+1;
            }      
        }
        
        int s = 0;
        
        for(auto it: dp)s+=it;
        
        return s;
            
        
        
        
    }
};