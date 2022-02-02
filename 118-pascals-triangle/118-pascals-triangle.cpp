class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        vector<vector<int>>ans;
        vector<int>curr={1};
        vector<int>prev{1,1};
        
        if(n==1){
                ans.push_back(curr);
                return ans;
            }
    
            if(n==2){
                ans.push_back(curr);
                ans.push_back(prev);
                return ans;
            }
        
        ans.push_back(curr);
        ans.push_back(prev);
        
        for(int i=3;i<=n;i++){
            
             vector<int>lol(i,1);
             for(int i=0;i<prev.size()-1;i++){
                 lol[i+1]=prev[i]+prev[i+1];
             }
             prev=lol;
             ans.push_back(lol);
        }
        
         return ans;
        
    }
};