class Solution {
public:
    string removeKdigits(string num, int k) {
        
        int n = num.size();
        stack<char>st;
        
        for(int i=0;i<num.size();i++){
            
            while(!st.empty() && k>0 && st.top()>num[i]){
                k--;
                st.pop();
            }
            
            st.push(num[i]);
            
            //handle for 0's
            
            if(st.size()==1 && num[i]=='0')st.pop();
            
        }
        
       while(k && !st.empty()){
           st.pop();
           k--;
       }
       
        string ans="";
        while(!st.empty()){
            char k = st.top();st.pop();
            ans.push_back(k);
        }
        
        reverse(ans.begin(),ans.end());
        if(ans.size()!=0)return ans;
        return "0";
    
        
    }
};