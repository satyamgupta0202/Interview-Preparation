class Solution {
public:
    
    void dfs(int node , vector<int>&vis , vector<int>adj[])
    {
        vis[node] = 1 ;
        
        for(auto it: adj[node])
        {
            if(vis[it]==0)
            {
                dfs(it,vis,adj);
            }
        }
    }
    
    int findParent(int u ,vector<int>&par)
    {
        if(par[u]==u)return u;
        
        return par[u] = findParent(par[u] , par);
    }
    
    void Union(int u , int v , vector<int>&rank , vector<int>&par)
    {
        u = findParent(u , par);
        v = findParent(v , par);
        
        if(rank[u] < rank[v])
        {
            par[u] = v;
        }
        else if(rank[u]>rank[v])
        {
            par[v] = u;
        }
        else
        {
            rank[u]++;
            par[v]=u;
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        int k = connections.size();
        
        vector<int>adj[n];
        
        for(int i=0;i<k;i++)
        {
            int a = connections[i][0];
            int b = connections[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        int ans = 0;
        vector<int>vis(n,0);
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                dfs(i,vis,adj);
                ans++;
            }
        }
        
        
        vector<int>rank(n,0);
        vector<int>par(n,0);
        
        for(int i=0;i<n;i++)
        {
            par[i]=i;
        }
        
        int dis=0 , extra=0;
        for(int i=0;i<k;i++)
        {
            int a = connections[i][0];
            int b = connections[i][1];
            
            if(findParent(a,par)!=findParent(b,par))
            {
                Union(a,b,rank,par);
            }
            else
            {
                extra++;
            }   
        }
        
        if(extra<ans-1)
        {
         return -1;   
        }
        
        return (ans-1);
        
    }
};