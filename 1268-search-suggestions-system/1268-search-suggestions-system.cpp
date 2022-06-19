class Solution {
public:
    
    vector<vector<string>>ans;
    
    vector<vector<string>> suggestedProducts(vector<string>& p, string s)
    {
        sort(p.begin(),p.end());
        for(int i=0;i<s.size();i++) 
        {
            string  k = s.substr(0,i+1);
            vector<string>res;
            int c=0;
            for(int j=0;j<p.size() && c<3;j++)
            {
                string t = p[j];
                string lol = t.substr(0,i+1);
                if(lol == k)
                {
                    res.push_back(t);
                    c++;
                }
            }
            sort(res.begin(),res.end());
            ans.push_back(res);
        }
        return ans;
    }
};