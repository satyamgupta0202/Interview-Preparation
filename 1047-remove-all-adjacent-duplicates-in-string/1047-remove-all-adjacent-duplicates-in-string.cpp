class Solution {
public:
    string removeDuplicates(string s) 
    {
        string ans = "";
        
        for(auto it: s)
        {
            if(ans.size()==0 || ans.back()!=it )
            {
                ans.push_back(it);
            }
            else
            {
                ans.pop_back();
            }
        }
        return ans;
    }
};