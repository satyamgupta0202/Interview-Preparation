// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


vector<int> Smallestonleft(int arr[], int n);


int main() {
	
	int t;
	
	cin >> t;
	
	while(t--){
	    
	    int n;
	    cin >> n;
	    int arr[n+1];
	    
	    for(int i=0;i<n;i++){
	        cin>> arr[i];
	    }
	    
	    vector<int> b;
	    b = Smallestonleft(arr, n);
	    for(int i=0;i<n;i++)
	        cout << b[i] << " ";
	       
	    cout << endl;
	    
	    
	}
	
	return 0;
}// } Driver Code Ends



vector<int> Smallestonleft(int arr[], int n)
{
    // Complete the function
    vector<int>ans(n,-1);
    
    set<int>s;
    s.insert(arr[0]);
    
    for(int i=1;i<n;i++)
    {
      int k = -1;
      s.insert(arr[i]);
      auto it = s.lower_bound(arr[i]);
      if(it!=s.begin())
      {
         it--;
         ans[i]=*it;
      }
  
    }
    return ans;
}