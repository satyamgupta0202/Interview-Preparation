class Solution {
public:
    int calPoints(vector<string>& ops)
    {
       int n = ops.size();
       stack<int>st;
       
        for(int i=0;i<n;i++)
        {
            if(ops[i]=="C")
            {
                st.pop();
            }
            else if(ops[i]=="D")
            {
                int a = st.top(); st.pop();
                st.push(a);
                st.push(a*2);
            }
            
            else if(ops[i]=="+")
            {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(a);
                st.push(b);
                st.push(a+b);
            }
            else
            {
                //cout<<stol(ops[i])<<endl;
                st.push(stol(ops[i]));
            }      
        }
        
        int ans = 0;
        while(!st.empty())
        {
            ans+= st.top();
            st.pop();
        }
        
        return ans;
        
        
    }
};