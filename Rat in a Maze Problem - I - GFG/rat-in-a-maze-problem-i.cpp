// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
   vector<string>ans;
    void dfs(int i,int j,vector<vector<int>>&visited,string str,vector<vector<int>>&m,int n)
    {
        if(i<0||j<0||i>n-1||j>n-1||m[i][j]==0||visited[i][j]==1) return ;
        if(i==n-1 && j==n-1)
        {
            ans.push_back(str);
            str="";
            return ;
        }
        visited[i][j]=1;
        dfs(i-1,j,visited,str+"U",m,n);
        dfs(i+1,j,visited,str+"D",m,n);
        dfs(i,j+1,visited,str+"R",m,n);
        dfs(i,j-1,visited,str+"L",m,n);
        visited[i][j]=0;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<int>>visited(n,vector<int>(n));
        if(m[0][0]==0) return {};
        if(m[n-1][n-1]==0) return {};
        string str="";
        dfs(0,0,visited,str,m,n);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends