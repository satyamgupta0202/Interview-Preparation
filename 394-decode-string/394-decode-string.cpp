class Solution {
public:
    string decodeString(string s) 
    {
        int n = s.size();
        int num = 0;
        string  str = "";
        stack<pair<int , string>>st;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]>='0' && s[i]<='9')
            {
                num = num*10 + (s[i]-'0');
            }
            
            if(s[i]>='a' && s[i]<='z')
            {
                str.push_back(s[i]);
            }
            
            if(s[i]==']')
            {
                auto j = st.top().first;
                auto jk = st.top().second;
                st.pop();
                for(int p=1;p<=j;p++)
                {
                    jk=jk+str;
                }
               str = jk;
            }
            
            if(s[i]=='[')
            {
                st.push({num,str});
                num=0;
                str = "";
            }  
        }
        return str;
    }
};