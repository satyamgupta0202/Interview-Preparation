class Solution {
public:
     int dp[1099][1099];
     int solve(vector<int>&nums , int n , vector<int>&multipliers , int m , int i,int w){
        
         
        if(w>=m || i>=n)return 0;
         
        int r = i+n-w-1;
         
        if(dp[i][w]!=INT_MIN)return dp[i][w];
         
        
        
        // if(i==j)return dp[i][j] =  a[i]*k[w];
         
         return dp[i][w] =   max(
            nums[i]*multipliers[w] +  solve(nums,n,multipliers,m,i+1,w+1) ,
            nums[r]*multipliers[w] +  solve(nums,n,multipliers,m,i,w+1)
         );
        
        
        
    }
    
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        
        int n = nums.size();
        int m = multipliers.size();
        int ans=0;
      //  memset(dp,INT_MIN,sizeof(dp));
        for(int i=0;i<1009;i++){
            for(int j=0;j<1009;j++){
                dp[i][j]=INT_MIN;
            }
        }
        return solve(nums,n,multipliers,m,0,0);
     
        
        
        
        
    }
};