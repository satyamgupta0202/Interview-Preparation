class Solution {
public:
    int maximumGood(vector<vector<int>>& s) {
        
       int n = s.size();
       
//  0 0
//  1 1
//  0 1
//  1 0
        
//         try all combinations : Left-> multiply by 2 , right shift / by 2
        int ans = 0;
        bool ok =false;
        for(int mask = 0 ; mask< 1<<n ; mask++){  //2^n-1 combination of subset 
        
            ok = true;
            
            for(int i=0;i<n;i++){
                
                if(!( mask>>i & 1  )){
                    continue;
                }
                
                for(int j=0;j<n;j++){
                    if(i==j || s[i][j]==2){
                        continue;
                    }
                    
                    if( (mask>>j &1) != s[i][j] ){
                        ok = false;
                    }
                }
                
            }
            
            if(!ok){
                continue;
            }
            
            ans = max(ans , __builtin_popcount(mask));
            
            
            
        }
        
        
        
        return ans;
        
        
        
    }
};