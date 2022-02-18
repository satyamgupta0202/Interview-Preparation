// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  
    int check(vector<int>&v , int n)
    {
        stack<pair<int,int>>sl,sr;
        vector<int>l(n,-1);
        vector<int>r(n,n);
        
        //left
        for(int i=0;i<n;i++)
        {
            while(!sl.empty() && sl.top().first>=v[i])
            {
                sl.pop();
            }
            
            if(!sl.empty() && sl.top().first<v[i])
            {
                l[i]=sl.top().second;
            }
            
            sl.push({v[i],i});
        }
        //right
        for(int i=n-1;i>=0;i--)
        {
            while(!sr.empty() && sr.top().first>=v[i])
            {
                sr.pop();
            }
            
            if(!sr.empty() && sr.top().first<v[i])
            {
                r[i]=sr.top().second;
            }
            
            sr.push({v[i],i});
        }
        
        int ans = 0;
        
        for(int i=0;i<n;i++)
        {
            int a = l[i];
            int b = r[i];
           // cout<<a<<" "<<b<<endl;
            ans = max(ans , v[i]*(b-a-1));
        }
       // cout<<ans<<"lol"<<endl;
        return ans;
    }
  
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int ans = INT_MIN;
        vector<int>v(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(M[i][j])
                {
                    v[j]++;
                }
                else
                {
                    v[j]=0;
                }
            }
             int k = check(v,m);
             ans = max(ans ,k);
            
            //for(int k=0;k<m;k++)
            // cout<<v[k]<<" ";
            // cout<<endl;
        }
        return ans;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends