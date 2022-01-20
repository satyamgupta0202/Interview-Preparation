class Solution {
 
    bool canSpeakCommon(vector<int> &a,vector<int> &b)
    {
       
        for(auto &val : a)
        {
            for(auto &ele : b) 
                if(val == ele) return true;
        }
 
        return false;
    }
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
 

        unordered_set<int> st;
 
        for(auto &fri : friendships)
        {
            
            if(!canSpeakCommon(languages[fri[0]-1] , languages[fri[1]-1]))
            {
               
                st.insert(fri[0]);
                st.insert(fri[1]);
            }
        }
 
     
        unordered_map<int,int> mp;
 
        for(int i=1;i<=size(languages);i++)
        {
         
            if(st.count(i) == 0) continue;
 
            
            for(auto &ele : languages[i-1])
                mp[ele]++;
        }
 
        int res = 0;
 
        for(auto &[key,value] : mp)
            res = max(res,value);
 
        return size(st) - res;
    }
};