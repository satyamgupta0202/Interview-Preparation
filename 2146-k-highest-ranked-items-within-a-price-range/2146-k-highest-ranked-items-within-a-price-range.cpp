class Solution {
public:
    
    bool check(int i,int j , int row,int col ,vector<vector<int>>& grid){
        
        if(i<0 || j<0 || i>=row || j>=col || grid[i][j]==0 )return false;
        return true;
         
    }
    
    
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        
        //distance 
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>>dis(row,vector<int>(col,INT_MAX));
       // vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
        dis[start[0]][start[1]]=0;
        queue<pair<int,int>>q;
        q.push({start[0],start[1]});
       // visited[start[0]][start[1]]=true;
        while(!q.empty()){
            auto s = q.front().first;
            auto e = q.front().second;
            q.pop();
            
            if(check(s+1,e,row,col,grid) && dis[s+1][e]==INT_MAX){
                dis[s+1][e] = (1+dis[s][e]);
                q.push({s+1,e});
              //  visited[s+1][e]=true;
            }
            
            if(check(s-1,e,row,col,grid) && dis[s-1][e]==INT_MAX){
                dis[s-1][e] =(1+dis[s][e]);
                q.push({s-1,e});
               // visited[s-1][e]=true;
            }
            
            if(check(s,e+1,row,col,grid) && dis[s][e+1]==INT_MAX){
                dis[s][e+1] = (1+dis[s][e]);
                q.push({s,e+1});
               // visited[s][e+1]=true;
            }
            
            if(check(s,e-1,row,col,grid) && dis[s][e-1]==INT_MAX){
                dis[s][e-1] = ( 1+dis[s][e]);
                q.push({s,e-1});
               // visited[s][e-1]=true;
            }    
        }
        
//        
        vector<vector<int>>lol;
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){  
               if(grid[i][j]>=pricing[0] && grid[i][j]<=pricing[1] && dis[i][j]!=INT_MAX){
                   vector<int>temp({dis[i][j] , grid[i][j] , i , j});
                 
                   lol.push_back(temp);
               }  
            }
        }
        
        sort(lol.begin(),lol.end(),[](vector<int>&a , vector<int>&b){
            
           if(a[0]==b[0] && a[1]==b[1] && a[2]==b[2]){
               return a[3]<b[3];
           }
           if(a[0]==b[0] && a[1]==b[1]){
               return a[2]<b[2];
           }
            if(a[0]==b[0]){
               return a[1]<b[1];
           }
            return a[0]<b[0];
              
        });
        
        vector<vector<int>>ans;
        int c=0;
        for(auto &kl: lol){
            c++;
            vector<int>kk;
            kk.push_back(kl[2]);
            kk.push_back(kl[3]);
            ans.push_back(kk);
            if(c==k)return (ans);
            
        }
        

        return ans;
        
        
        
        
    }
};