class Solution {
public:
    
    
    bool check(int node , vector<int>adj[] , vector<int>&col , int par)
    {
        
        
        for(auto it : adj[node])
        {
            if(col[it]==-1)
            {
                col[it]=1-col[node];
                if(check(it,adj,col,node)==false)return false;
            }
            else if(col[node]==col[it])return false;
            
            
        }
        return true;
    }
    
    
    
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        
        vector<int>adj[n];
        vector<int>col(n,-1);
        
        for(int i=0;i<n;i++)
        {
            
            for(int j=0;j<graph[i].size();j++)
            {
                int a = graph[i][j];
                adj[i].push_back(a);
            }
         
        }
        
        for(int i=0;i<n;i++)
        {
            if(col[i]==-1)
            {
                col[i]=1;
                if(check(i,adj,col,-1)==false)
                    return false;
            }
        }
        
        return true;
        
    }
};