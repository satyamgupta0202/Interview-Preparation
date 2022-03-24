class Solution {
public:
    
    long mod = (int)1e9+7;
    int kadane(vector<int>arr , int k){
        
        int ans = 0 , curr=0;
        
        for(int i=1;i<=k;i++){
            
         for(int i=0;i<arr.size();i++){
            
            if(curr<0){
                curr=arr[i];
                ans = max(ans ,curr);
            }
            else{
                curr+=arr[i];
                ans = max(ans,curr);
            }    
        }
                
        }
        return (int)ans%mod;  
    }
    
    
    
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        
        int n= arr.size();
        long sum=0;
        for(auto el: arr){
            sum+=el;
        }
        
         int s1 = kadane(arr,1);
        if(k==1){
            return (int)s1%mod;
        }
        
        int s2 = kadane(arr,2);
        
        if(sum<0){
            return (int)(s2%mod);
        }
        
       int ans = (int)(s2 + ((k-2) * (sum) % mod));
        
        return max(ans,0);
        
        
        
    }
};