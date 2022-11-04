class Solution {
public:
    
    bool check(char k)
    {
        if(k==' ')return false;
        if(k=='A' || k=='a' || k=='e'|| k=='E' || k=='i' || k=='I' || k=='o' || k=='O' || k=='u' || k=='U')return true;
        
        return false;
    }
    
    string reverseVowels(string s) {
        
        int i = 0 , j = s.size()-1;
        
        while(i<=j)
        {
            if(check(s[i]) && check(s[j]))
            {
                swap(s[i] , s[j]);
                i++;
                j--;
            }
            // cout<<s[i] <<" "<<s[j]<<endl;
            if(i<=j && check(s[i]) == false)i++;
            
            if(i<=j && check(s[j]) == false)j--;
            
            
        }
        
        return s;
    }
};