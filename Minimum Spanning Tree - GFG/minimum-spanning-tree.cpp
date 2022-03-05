// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int>vis(V,0);
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> >pq;
        vector<int>dis(V,1000000);
        
        vis[0]=0;
        pq.push({0,0});
        
        while(!pq.empty())
        {
            auto curr = pq.top().second;
        
            vis[curr]=1;
            pq.pop();
            
            for(auto it: adj[curr])
            {
                auto nxt = it[0];
                auto k = it[1];
                if(vis[nxt]==0 && k<dis[nxt])
                {
                    dis[nxt]=k;
                    pq.push({dis[nxt],nxt});
                }
            }
            
        }
        
        int ans =0;
        for(int i=0;i<V;i++)
        {
            if(dis[i]!=1000000)
            ans+=dis[i];
        }
        return ans;
        
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends