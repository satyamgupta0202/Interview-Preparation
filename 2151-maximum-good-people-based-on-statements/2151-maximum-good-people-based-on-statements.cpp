class Solution {
public:
    int maximumGood(vector<vector<int>>& s) {
        
       int n = s.size();
       
//  0 0
//  1 1
//  0 1
//  1 0
        
//       try all combinations : Left-> multiply by 2 , right shift / by 2
        int ans = 0;
        bool ok =false;
        for(int mask = 0 ; mask< 1<<n ; mask++){     //2^n-1 combination of subset 
        
            ok = true;
            
            for(int i=0;i<n;i++){      //check ith bit 
                
                if(!( mask>>i & 1  )){   //ith is good whatever hw will say is always correct, so we will check further and if he is not good then we have considered for now he is good and continued further
                    
                    continue;
                }
                
                for(int j=0;j<n;j++){      //now we check jth person if he doestnt make opinion for ith person we will simply continue
                    if(i==j || s[i][j]==2){
                        continue;
                    }
//     otherwise we will check the opinions with s[i][j] if they dont match our subset is invalid                
                    if( (mask>>j &1) != s[i][j] ){
                        ok = false;
                    }
                }
                
            }
//             if we get valid subset we will check for makimum 1 
            if(!ok){
                continue;
            }
            
            ans = max(ans , __builtin_popcount(mask));     
        }
        return ans;   
    }
};