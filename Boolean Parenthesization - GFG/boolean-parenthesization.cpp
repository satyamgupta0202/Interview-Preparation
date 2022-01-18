// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

long long t[201][201][2];
class Solution{
public:
   int count(string s,int i,int j,bool istrue  )
   {
       if(i>j)
       return 0;
       if(i==j)
       {
       if(istrue==1)
      t[i][j][istrue]= (s[i]=='T');
       else
       t[i][j][istrue]= (s[i]=='F');
       return t[i][j][istrue];
       }
       if(t[i][j][istrue]!=-1)
       {
           return t[i][j][istrue];
       }
       int ans=0;
       for(int k=i+1;k<=j-1;k=k+2)
       {
           int lt=count(s,i,k-1,true);
           int lf=count(s,i,k-1,false);
           int rt=count(s,k+1,j,true);
           int rf=count(s,k+1,j,false);
           if(s[k]=='&')
           {
               if(istrue==true)
               ans=ans+lt*rt;
               else
               ans=ans+lf*rf+lf*rt+lt*rf;
           }
           if(s[k]=='^')
           {
               if(istrue==true)
               ans=ans+lt*rf+lf*rt;
               else
               ans=ans+lf*rf+lt*rt;
           }
           if(s[k]=='|')
           {
               if(istrue==true)
               ans=ans+lt*rt+lf*rt+lt*rf;
               else
               ans=ans+lf*rf;
           }
           
       }
       t[i][j][istrue]=ans%1003;
       return ans%1003;
   }
   int countWays(int N, string S)
   {
       memset(t,-1,sizeof(t));
      return count(S,0,N-1,true);
   }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends