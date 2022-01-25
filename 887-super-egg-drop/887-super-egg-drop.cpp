class Solution {
public:
    int dp[102][10005];
    int solve(int egg , int floor) {
        
        int ans = INT_MAX;
        
        //base conditions
        if(egg==1)return dp[egg][floor] =  floor;
        if(floor == 0 ) return dp[egg][floor] = 0;
        if(floor==1)return dp[egg][floor] = 1;
        
//         MCM hai tho loop tho lagega hi
        int a1,a2;
        if(dp[egg][floor]!=-1)return dp[egg][floor];  
        
        int low=1 , high = floor;
        
        
       while(low<=high){
           
            int mid = (low+high)/2;
            a1 = solve(egg-1,mid-1);
            a2 = solve(egg , floor-mid);
            int temp = 1+max(a1,a2);   //maximum floor
            ans= min(ans,temp);       // minimum step
            dp[egg][floor]=ans;
           
           if(a1>a2){
               high = mid-1;
           }else{
               low=mid+1;
           }
           
        }
        return ans;
    }

    int superEggDrop(int k, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(k,n);
    }
};