// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& arr, int n) 
    {
        
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            st.push(i);
        }
        
        while(st.size()!=1)
        {
            int i = st.top();
            st.pop();
            int j = st.top();
            st.pop();
            
            if(arr[i][j]==1)
            {
                st.push(j);
            }
            else
            {
                st.push(i);
            }
            
        }
        
        int pot = st.top();
        
        for(int i=0;i<n;i++)
        {
            if(i!=pot)
            {
                if(arr[pot][i]==1 || arr[i][pot]==0)
                {
                    return -1;
                }
            }
        }
        return pot;
    }
};

/**
 * class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& arr, int n) 
    {
        // code here 
        vector<int>in(n,0);
        vector<int>out(n,0);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(arr[i][j])
                {
                    in[j]++;
                    out[i]++;
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(in[i]==n-1 && out[i]==0)
            return i;
        }
        return -1;
    }
};
**/

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends