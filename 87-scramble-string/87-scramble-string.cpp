class Solution {
public:
    unordered_map<string,bool>mp;
    bool solve(string s1 , string s2){
        
        
        if(s1.compare(s2)==0)return true;
        
        if(s1.size()==1)return false;
        
        
        int n = s1.size();
        
        string key = s1+s2;
        
        if(mp.find(key)!=mp.end()){
            return mp[key];
        }
        
        bool flag = false;
        
        for(int i=1;i<=n-1;i++){
           
            if(((solve(  s1.substr(0,i) , s2.substr(n-i,i)    )==true && 
             
               solve(s1.substr(i,n-i) , s2.substr(0,n-i)) ==true)) ||
               
               (
                   solve(s1.substr(0,i) , s2.substr(0,i))==true   &&
                   solve(s1.substr(i,n-i) , s2.substr(i,n-i))==true
               
               )
               
              ){
                flag=true;
               return  true;
               
            }
            
            
        }
        mp[key]=flag;
        return false;
        
    }
    
    
    
    bool isScramble(string s1, string s2) {
        
      //  memset(dp,false,sizeof(dp));
        
        if(s1.compare(s2)==0)return true;
        
        if(s1.size()!=s2.size())return false;
        
        return solve(s1,s2);
        
    }
};