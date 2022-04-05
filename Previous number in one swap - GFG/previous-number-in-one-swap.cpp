// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string previousNumber(string s)
    {
        int n = s.size();
        int i=n-2;
        
        while(i>=0 && s[i]<=s[i+1])
        {
          i--;   
        }
       // cout<<s[i-1]<<" "<<s[i]<<endl;
        
        
        if(i<0)return "-1";
        
      //  cout<<s[i-1]<<endl;
        
        int k = n-1;
        if(i==0 and s[i+1] =='0')
            return "-1";
        while(i<k and s[i]<=s[k])
            k--;
        while(s[k]==s[k-1])
        k--;
        
        swap(s[i],s[k]);
        
        
        
        
        //swap(s[i-1],s[i]);
        
        
        // if(s[0]=='0')return "-1";
        
        return s;
        
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.previousNumber(S) << endl;
    }
    return 0; 
}   // } Driver Code Ends