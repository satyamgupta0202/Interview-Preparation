// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++


    
   class Solution{
    public:
    
    vector<string>ans;
    
    bool check(int i,int j , vector<vector<int>> &m , vector<vector<int>>&vis )
    {
        if(i>=m.size() || j>=m.size() || i<0 ||j<0 || m[i][j]==0 || vis[i][j]==1)return false;
        return true;
    }
    
    void solve(vector<vector<int>> &m , int n ,string &path , vector<vector<int>>&vis , int i,int j )
    {
        if(i==n-1 && j==n-1)
        {
            //cout<<path;
            ans.push_back(path);
            return;
        }
        
        //if(!check(i,j,m,vis))return;
        //left
        vis[i][j]=1;
        
        if(check(i,j-1,m,vis))
        {
            path+="L";
            vis[i][j-1]=1;
            solve(m,n,path,vis,i,j-1);
            vis[i][j-1]=-1;
            path.pop_back();
        }
        //Right
        if(check(i,j+1,m,vis))
        {
            path+="R";
            vis[i][j+1]=1;
            solve(m,n,path,vis,i,j+1);
            vis[i][j+1]=-1;
            path.pop_back();
        }
        //Down
        if(check(i+1,j,m,vis))
        {
            path+="D";
            vis[i+1][j]=1;
            solve(m,n,path,vis,i+1,j);
            vis[i+1][j]=-1;
            path.pop_back();
        }
        //up
        if(check(i-1,j,m,vis))
        {
            path+="U";
            vis[i-1][j]=1;
            solve(m,n,path,vis,i-1,j);
            vis[i-1][j]=-1;
            path.pop_back();
        }
        
        vis[i][j]=-1;
        
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(m[0][0]==0)return {};
        string path="";
        vector<vector<int>>vis(n,vector<int>(n+1,-1));
        solve(m,n,path,vis,0,0);
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