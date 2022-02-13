// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    int low = 0 , high = n-1;
	    
	    while(low<=high)
	    {
	        int mid = low + (high-low)/2;
            if(mid+1<n && arr[mid]>arr[mid+1])return mid+1;
            else if(mid-1>=0 && arr[mid]<arr[mid-1])return mid;
	        else if(arr[mid]<arr[low]){
	            high=mid-1;
	        }
	        else{
	            low=mid+1;
	        }
	    }
	    return 0;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends