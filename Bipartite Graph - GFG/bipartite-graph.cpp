// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

   bool dfs(int node , int par , vector<int>&col , vector<int>adj[])
   {
      
       for(auto it: adj[node])
       {
           if(col[it]==-1)
           {
               col[it]=1-col[node];
               if(!dfs(it,node,col,adj))return false;
           }
           else if(col[it]==col[node])return false;
       }
       return true;
   }

	bool isBipartite(int n, vector<int>adj[])
	{
        vector<int>col(n,-1);
        vector<int>vis(n,0);
        
        for(int i=0;i<n;i++)
        {
            if(col[i]==-1)
            {
                col[i]=1;
                if(!dfs(i,-1,col,adj))return false;
            }
        }
        return true;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends