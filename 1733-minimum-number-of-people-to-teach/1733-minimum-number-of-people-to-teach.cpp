class Solution {
public:
    
    bool check(vector<int>&a , vector<int>&b){
          for(auto &l1 : a) {
            for(auto &l2 : b) 
                if(l1 == l2) return true;
        }
 
        return false;
    }
    
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        
        int f = friendships.size();
        
        unordered_set<int>s;
        
        for(int i=0;i<f;i++){
            
            int guy1 = friendships[i][0];
            int guy2 = friendships[i][1];
            
           //             Dont share common language 
            if(!check(languages[guy1-1] , languages[guy2-1])){
                s.insert(guy1);
                s.insert(guy2);
            }    
        }
        
        unordered_map<int,int>ump;
        for(int i=1;i<=languages.size();i++){
            if(s.count(i)==0)continue;  //he interacts with his friend
            
            for(auto &lang: languages[i-1]){
                ump[lang]++ ;     //other language then the mutual one's
            }
            
        }
        
        int ans = 0;
        for(auto it: ump){
            ans = max(ans , it.second);
        }
        
        return s.size() - ans;
        
        
        
    }
};