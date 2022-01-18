// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        // code here
        stack<pair<int,string>>st;
        string curr = "";
        int num  = 0;
        int n = s.size();
        
        for(int i=0;i<n;i++){
            
            if(s[i] == '['){
                
                st.push({num,curr});
                curr = "";
                num = 0;
                
            }
            
            else if(s[i] == ']'){
                auto it = st.top(); 
                st.pop();
                //cout<<it.first<<" "<<it.second<<endl;
                string temp = curr;
                for(int i=1;i<it.first;i++){
                    curr = curr+temp;
                }
                curr = it.second+curr;
            }
            
            else if(s[i]>='a' && s[i]<='z'){
                curr.push_back(s[i]);
            }
            else{
                num = num *10 + s[i]-'0';
            }
        }
        return curr;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends