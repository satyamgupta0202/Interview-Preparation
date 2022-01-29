// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string S){
	    
	    int n = S.size();
	    int mans=0,curr=0;
	    bool ok =true;
	    for(int i=0;i<n;i++){
	        
	        if(S[i]=='0'){
	            ok=false;
	            curr+=1;
	        }else{
	            curr-=1;
	        }
	        
	        
	        if(curr>mans){
	            mans=curr;
	        }
            if(curr<0){
                curr=0;
            }	        
	        
	    }
	    if(ok)return -1;
	    return mans;
	    
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends