// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	
    	int cnt = 0 , ans = 0;
    	
    	sort(arr,arr+n);
    	sort(dep , dep+n);
    	
    	int i=0,j=0;
    	
    	while(i<=n-1 && j<=n-1){
    	    
    	    if(dep[j]>=arr[i]){
    	        cnt++;
    	        i++;
    	        ans = max(ans,cnt);
    	    }else{
    	        cnt--;
    	        j++;
    	    }
    	}
    	
    	return ans;
    	
    }
};



















/** 
 O(N)Space Complexity 
  	vector<pair<int,int>>v;
    	for(int i=0;i<n;i++){
    	    v.push_back({arr[i],dep[i]});
    	}
    	sort(v.begin(),v.end());
        priority_queue<int , vector<int> , greater<int>>q;	
    	int ans = 1;
    	q.push(v[0].second);
    	
    	for(int i=1;i<n;i++){
    	    
    	    if(q.top() < v[i].first){
    	        q.pop();
    	    }
    	    else{
    	        ans++;
    	    }
    	    q.push(v[i].second);
    	}
    	return ans;
**/


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends