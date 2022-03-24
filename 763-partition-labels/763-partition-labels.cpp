class Solution {
public:
    vector<int> partitionLabels(string s)
    {
        unordered_map<char,int>mp;
        vector<int>ans;
        
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]=i;
        }
        
        int n = s.size();
        stack<int>st;
        int k=0;
        
       // st.push(mp[s[0]]);

        for(int i=0;i<n;i++)
        {
            
            if(st.empty())
            {
                if(mp[s[i]]==i)ans.push_back(1);
                else
                {
                    st.push(mp[s[i]]);
                     k=i;
                }
                
            }
            
            else if(i==st.top())
            {
                ans.push_back((i-k)+1);
                st.pop();
            }

            else if(mp[s[i]]>st.top())
            {
                st.pop();
                st.push(mp[s[i]]);
            }  
        } 
       return ans;   
    }
};