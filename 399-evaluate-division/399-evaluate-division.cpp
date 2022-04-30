class Solution {
public:
    
    void dfs(string src,string des , double temp ,double &ans , map<string , vector<pair<string , double>>>mp , map<string,int>&visited){
        
        if(src == des){
            ans = temp;
            return;
        }
        
        if(mp.count(src)==0 || mp.count(des)==0)return ;
        
        if(visited[src]==1)return;
        
        visited[src]=1;
        
        for(auto it : mp[src]){
            
            auto next = it.first;
            auto wt= it.second;
            if(visited[next]==0){
                dfs(next,des,temp*wt,ans,mp,visited);
            }  
        }
        
    }
    
    
    
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& v, vector<vector<string>>& q) {
        
        map<string , vector<pair<string , double>>>mp;
        int n = e.size();
        vector<double>res;
        
        for(int i=0;i<n;i++){
            
            string a = e[i][0];
            string b = e[i][1];
            double div = v[i];
            
            mp[a].push_back({b,div});
            mp[b].push_back({a,1/div});
            
        }
        
        for(int i=0;i<q.size();i++){
            
            string src = q[i][0];
            string des = q[i][1];
            map<string,int>visited;
            double temp = 1.0 ;
            double ans = -1.0 ;
            
            if(mp.count(src)==1 && mp.count(des)==1){
                dfs(src,des,temp,ans,mp,visited);
            }
             res.push_back(ans);
              
        }
        return res;
    }     
        
};