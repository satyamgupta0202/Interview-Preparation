class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
      int ans = 0;
      int cnt = 0;
      unordered_set<int>s(nums.begin() , nums.end());
        
     for(auto n: nums){
         
          if(s.count(n-1)==0){
              
              cnt = 0;
             
              while(s.count(n)!=0)
              {
                  n++;
                  cnt++;
              }
              ans = max(ans,cnt);
          }
     }
        return ans;
        
        
    }
};

/**


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        set<int>s(nums.begin(),nums.end());
        
        int ans = 0,cnt=0;
        
        if(s.size()==0 || s.size()==1)return s.size();
        
        
        auto it = s.begin();
        int curr = *it;
        int prev = curr;
        it++;
        while(it!=s.end()){
            
            cout<<*it<<endl;
            
            if(*it != prev+1){
                
                ans = max(ans,cnt);
                cnt=0;
                prev = *it;
                
            }else{
                cnt++;
                prev = *it;
            }
            
            it++;
        }
        return max(ans,cnt)+1;
        
    }
};

**/