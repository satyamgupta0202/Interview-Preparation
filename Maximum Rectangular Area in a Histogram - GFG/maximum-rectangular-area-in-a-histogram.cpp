// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n){
        // Your code here
        vector<long long>left(n,-1);
        vector<long long>right(n,-1);
        
        //left
        stack<pair<long long,long long>>l;
        for(long long i=0;i<n;i++){
            
            while(!l.empty() && l.top().first>=arr[i]){
                l.pop();
            }
            if(!l.empty() && l.top().first < arr[i]){
                left[i]=l.top().second;
            }
            l.push({arr[i],i});
            
        }
        //right
         stack<pair<long long,long long>>r;
        for(long long i=n-1;i>=0;i--){
            
            while(!r.empty() && r.top().first>=arr[i]){
                r.pop();
            }
            if(!r.empty() && r.top().first< arr[i]){
                right[i]=r.top().second;
            }
            r.push({arr[i],i});
            
        }
        // for(int i=0;i<n;i++){
        //     cout<<left[i]<<" "<<right[i]<<endl;
        // }
        long long ans = INT_MIN;
        for(long long i=0;i<n;i++){
            long long curr = arr[i];
            long long gl = left[i];
            long long gr = right[i];
            long long larea=0;
            long long rarea =0 ;
            if(gl != -1){
                larea = max((long long)0,(i-gl-1)*(curr));
            }else{
                larea = max((long long)0,(i)*curr);
            }
            if(gr!=-1){
                rarea = max((long long)0,(gr-i-1)*curr);
            }else{
                rarea= max((long long)0,(n-i-1)*curr);
            }
            ans = max(ans,curr+larea+rarea);
        }
        return ans;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends