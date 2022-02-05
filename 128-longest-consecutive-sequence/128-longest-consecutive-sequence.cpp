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