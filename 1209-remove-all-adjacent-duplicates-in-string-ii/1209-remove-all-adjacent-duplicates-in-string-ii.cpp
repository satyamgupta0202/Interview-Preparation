class Solution {
public:
    string removeDuplicates(string s, int k)
    {
        stack<pair<char,int>>st;
        int n = s.size();
        string ans = "";
        for(int i=0;i<n;i++)
        {
            if(st.size()==0)
            {
                st.push({s[i],1});
            }
            
            else if(st.top().first == s[i] && st.top().second + 1 == k)
            {
                st.pop();
            }
            
            else if(st.top().first == s[i])
            {
                st.top().second++;
            }
            else
            {
                st.push({s[i],1});
            }
        }
        
        while(!st.empty())
        {
            char k = st.top().first;
            int l = st.top().second;
            st.pop();
            
            for(int i=1;i<=l;i++)
                ans.push_back(k);
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};