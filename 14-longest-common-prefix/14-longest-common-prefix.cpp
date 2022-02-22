class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        
        string ans  = "";
        int n = str.size();
        string temp = str[0];
        
        for(int i=0;i<temp.size();i++)
        {
            char k = temp[i];
            cout<<k<<endl;
            int c=0;
            bool ok = true;
            for(int j=1;j<n;j++)
            {
                if(str[j][i]==k)c++;
                else ok = false;
            }
            
            if(  ok){
                cout<<c<<endl;
                ans.push_back(k);
            }else{
                return ans;
            }
                    
        }
        return ans;

    }
};