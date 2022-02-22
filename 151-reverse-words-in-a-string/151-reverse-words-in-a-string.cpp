class Solution {
public:
    string reverseWords(string s) {
        
        stringstream str(s);
        
        string ans = "";
        string word;
        int c=0;
        while(str>>word){
            string temp;
            if(c!=0)
            temp =word+" ";
            else
            temp = word;   
            c++;
            reverse(temp.begin(),temp.end());
            ans.append(temp);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
        
    }
};