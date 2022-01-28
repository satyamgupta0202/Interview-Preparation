class Solution {
public:
    
    void check(string p , string up , vector<string>&ans) {
        
        if(up.size()==0){
            ans.push_back(p);
            return;
        }
        
        int c = up[0]-'0' ;
       
        if(c>=2 && c<=6){
        for(int i=(c-2)*3;i<(c-1)*3;i++){
            char temp = 'a'+i;
            check(p+temp,up.substr(1),ans);    
        }
    }
        else if(c==7){
            check(p+'p',up.substr(1),ans);
            check(p+'q',up.substr(1),ans);
            check(p+'r',up.substr(1),ans);
            check(p+'s',up.substr(1),ans);
        }
        else if(c==8){
            check(p+'t',up.substr(1),ans);
            check(p+'u',up.substr(1),ans);
            check(p+'v',up.substr(1),ans);
        }
        else{
            check(p+'w',up.substr(1),ans);
            check(p+'x',up.substr(1),ans);
            check(p+'y',up.substr(1),ans);
            check(p+'z',up.substr(1),ans);
        }
     
   
        
        
        
    }
    
    
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)return{};
        vector<string>ans;
        string up = digits;
        string p = "";
        check(p,up,ans);
        return ans;
    }
};