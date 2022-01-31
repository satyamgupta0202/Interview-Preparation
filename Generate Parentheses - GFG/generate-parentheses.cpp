// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    vector<string>v;
    
    void solve(int open , int close , string s){
        
        if(open==0 && close==0){
            v.push_back(s);
            return ;
        }
        
        if(open!=0){
            
            string op1 = s;
            op1.push_back('(');
            solve(open-1,close,op1);
        }
        
        if(close>open){
            string op2 = s;
            op2.push_back(')');
            solve(open,close-1,op2);
        }
        
    }
    
    vector<string> AllParenthesis(int n) {
        // Your code goes here 
        int open=n,close=n;
        string s = "";
        solve(open,close,s);
       
        return v;
        
    }
};

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends