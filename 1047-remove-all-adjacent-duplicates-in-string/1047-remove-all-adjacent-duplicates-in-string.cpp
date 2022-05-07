class Solution {
public:
    string removeDuplicates(string s) 
    {
        stack<char>st;
        int n = s.size();
        string ans = "";
        for(int i=0;i<n;i++)
        {
            if(st.empty() || st.top()!=s[i])
            {
                st.push(s[i]);
            }
            else
            {
                st.pop();
            }
        }
        
        while(!st.empty())
        {
            char k = st.top(); st.pop();
            ans.push_back(k);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};