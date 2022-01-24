class Solution {
public:
    bool detectCapitalUse(string word) {
        
        int n = word.size();
        int c=0;
        
        if(n==1)return true;
        map<int,bool>mp;
        
        for(int i=0;i<n;i++){
            
             int lol = (int)word[i];
            if(lol>=65 && lol<=90){
                mp[i]=true;
                c++;
            }else{
                mp[i]=false;
            }            
        }
        
        if(c==1 && mp[0] || ( c==n ) || c==0){
            return true;
        }
        return false;
        
        
        
    }
};