// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    
    vector<int>ans;
    
    void solve(int node , int par , vector<int>&vis , vector<int>&in , vector<int>&low , vector<int>adj[],int &timer)
    {
        vis[node]=1;
        low[node]=in[node]=timer++;
        int child = 0;
        
        
        for(auto it: adj[node])
        {
            
            if(it==node)continue;
            
            if(vis[it]==1)
            {
                low[node] = min(low[node], in[it]);
            }
            
            if(vis[it]==0)
            {
                solve(it , node , vis , in , low , adj , timer);
                low[node] = min(low[node] , low[it]);
                child++;
                
                if(par != -1 && low[it]>=in[node])
                {
                    // cout<<"LOL";
                    ans.push_back(node);
                }
            }
        }
        
                if(par==-1 && child>1)
                {
                   ans.push_back(node);
                }
    }
    
    vector<int> articulationPoints(int V, vector<int>adj[]) 
    {
        vector<int>vis(V,0) , in(V,-1) , low(V,-1);
        int timer = 0;
        solve(0,-1,vis,in,low,adj,timer);
        sort(ans.begin(),ans.end());
        set<int>s(ans.begin() , ans.end());
        vector<int>res(s.begin() , s.end());
        if(res.size()==0)return {-1};
        return res;
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
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends