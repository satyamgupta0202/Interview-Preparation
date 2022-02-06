class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        map<char,int>mp;
        int n = s.size();
        int i=0 , j=0;
        int ans = 0 ,cnt = 0;
        
        
        while(j<n){
            
            mp[s[j]]++;
            
            // if(mp[s[j]]==1){
            //     ans = max(ans, j-i+1);
            // }
            
            while(i<j && mp[s[j]]>1){
                mp[s[i]]--;
                i++;
            }
            
            if(mp.count(s[j])==1){
                ans = max(ans, j-i+1);
            }
            
            j++;    
        }
        return ans;  
    }
};