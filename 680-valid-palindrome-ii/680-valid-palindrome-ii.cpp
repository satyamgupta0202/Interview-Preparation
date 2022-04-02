class Solution {
public:
    
    bool check(string s , int i ,int j)
    {
        while(i<=j)
        {
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    
    bool validPalindrome(string s) 
    {
        int i = 0;
        int j = s.size()-1;
        
        while(i<=j && s[i]==s[j])
        {
            i++;
            j--;
        }
        
        if(i>j)return true;
        
        return ( check(s,i+1,j) || check(s,i,j-1));
        
    }
};