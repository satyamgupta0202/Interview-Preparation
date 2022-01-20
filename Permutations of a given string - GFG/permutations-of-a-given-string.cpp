// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    vector<string>ans;
	    
	    void solve(string &S , int n ,int start , string &path) {
	        
	        if(path.size()==n){
	           // sort(path.begin(),path.end());
	            ans.push_back(path);
	            return ;
	        }
	        
	        for(int i=start;i<n;i++){
	            
	            path.push_back(S[i]);
	            swap(S[start] , S[i]);
	            solve(S,n,start+1,path);
	            swap(S[start] , S[i]);
	            path.pop_back();
	            
	        }
	    }
	    
		vector<string>find_permutation(string S){
		    
		    
		  string path = "";
		  //sort(S.begin(),S.end());
		  int n = S.size();
		  
		  solve(S,n,0,path);
		  sort(ans.begin(),ans.end()); 
		   return ans;
		   
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends