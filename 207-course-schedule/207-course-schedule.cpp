class Solution {
public:
    
    bool cycle(int node,vector<int>adj[],vector<int>&vis,vector<int>&dfsVis )
    {
        vis[node]=1;
        dfsVis[node]=1;
        
        for(auto it :  adj[node])
        {
            if(vis[it]==0)
            {
                if(cycle(it,adj,vis,dfsVis) == true)
                {
                    return true;
                }
            }
            else if(dfsVis[it]==1)return true;
        }
        
        dfsVis[node]=0;
        return false;
    }
    
    
    bool canFinish(int n, vector<vector<int>>& v) 
    {
        
        vector<int>adj[n];
        vector<int>vis(n,0);
        vector<int>dfsVis(n,0);
        
        for(int i=0;i<v.size();i++)
        {
            int a = v[i][0];
            int b = v[i][1];
            adj[b].push_back(a);
        }
        
        
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                if(cycle(i,adj,vis,dfsVis) == true)
                {
                    return false;
                }
            }
        }
        if(cycle(0,adj,vis,dfsVis) == true)return false;
        
//         for(int i=0;i<v.size();i++)
//         {
//             int a = v[i][0];
//             if(cycle(a,adj,vis,dfsVis)==true)return false;
//         }
        
        
        
         return true;
    }
};