// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    bool isPossible(int arr[], int n, int m, int mid){
        int studentCount = 1; 
        int pageSum = 0;
        for(int i=0; i<n; i++){
            if(pageSum + arr[i] <= mid){
                pageSum = pageSum + arr[i];
            }else{
                studentCount++;
                if(studentCount > m || arr[i] > mid){
                    return false;
                }
                pageSum = arr[i];
            }
        }
        return true;
    }
    int findPages(int A[], int N, int M) 
    {
       int s = 0;
       int sum = 0; 
       int ans = -1;
       for(int i=0; i<N; i++){
           sum = sum+A[i];
       }
       int e = sum;
       int mid = s + (e-s)/2;
       while(s<=e){
           if(isPossible(A, N, M, mid)){
               ans = mid;
               e = mid-1;
           }
           else{
               s = mid+1;
           }
           mid = s + (e-s)/2;
       }
       return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends