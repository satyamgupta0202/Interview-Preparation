// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    
    vector<int>ans;
    
    void bfs(int node , vector<int>adj[] , vector<int>&vis)
    {
        queue<int>q;
        q.push(node);
      
        //ans.push_back(node);
        
        while(!q.empty())
        {
            auto curr = q.front(); q.pop();
            ans.push_back(curr);
            vis[curr]=1;
            for(auto it: adj[curr])
            {
                if(vis[it]==0)
                {
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        
    }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) 
    {
        // Code here
        vector<int>vis(V,0);
        bfs(0,adj,vis);
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends