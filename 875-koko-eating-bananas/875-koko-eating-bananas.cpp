class Solution {
public:
    
    int check(vector<int>&piles , int n , int speed){
        
        int time = 0 ;
        
        for(int i=0;i<n;i++){
           
            if(piles[i]%speed == 0 ){
                time+= (piles[i]/speed);
            }else{
                time+= (piles[i]/speed)+1;
            }
            
        }
        return time;      
    }
    
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int n = piles.size();
        sort(piles.begin(),piles.end());
        int start = 1 , end = piles[n-1];
        int ans = INT_MAX;
        while(start<=end){
            
            int mid = (start+end)/2;
            
            int time = check(piles , n , mid);
            
            if(time >h){
                start=mid+1;
            }else{
                ans = min(ans,mid);
                end = mid-1;
            }
            
        }
        return ans;
        
    }
};